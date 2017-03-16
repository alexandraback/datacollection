#include <bits/stdc++.h>
using namespace std;
#define print_out(x) cout << "print_out: " << #x << " == " << x << endl;
#define sz(x) int((x).size())
#define pb(x) push_back(x)
#define F first
#define S second
#define whole(a) a.begin(), a.end()
#define FOR(i, N) for (int i = 0; i < N; ++i)
typedef long long int int64;
typedef unsigned int uint;


struct Quaternion
{
    char num;
    bool neg;


    typedef map<pair<char, char>, Quaternion> MultTable;
    static MultTable mult_tbl;

    static void setup()
    {
        mult_tbl[{'1', '1'}] = Quaternion('1', false);
        for (char c : "ijk")
        {
            mult_tbl[{'1', c}] = Quaternion(c, false);
            mult_tbl[{c, '1'}] = Quaternion(c, false);
            mult_tbl[{c, c}] = Quaternion('1', true);
        }

        mult_tbl[{'i', 'j'}] = Quaternion('k', false);
        mult_tbl[{'i', 'k'}] = Quaternion('j', true);

        mult_tbl[{'j', 'i'}] = Quaternion('k', true);
        mult_tbl[{'j', 'k'}] = Quaternion('i', false);

        mult_tbl[{'k', 'i'}] = Quaternion('j', false);
        mult_tbl[{'k', 'j'}] = Quaternion('i', true);
    }

    Quaternion(char num, bool neg)
        : num(num), neg(neg)
    {}

    Quaternion()
        : num('0'), neg(false)
    {}

    Quaternion& operator*=(Quaternion const& other)
    {
        if (num == '0' || other.num == '0')
        {
            num = '0';
            neg = false;
        }
        else
        {
            bool new_neg = neg ^ other.neg;
            *this = mult_tbl[{num, other.num}];
            neg ^= new_neg;
        }

        return *this;
    }
};

Quaternion::MultTable Quaternion::mult_tbl;

bool operator==(Quaternion const& a, Quaternion const& b)
{
    return a.num == b.num && a.neg == b.neg;
}

Quaternion operator*(Quaternion a, const Quaternion &b)
{
    a *= b;
    return a;
}

vector<int> findQuat(const string &s, const Quaternion &q, int beg)
{
    vector<int> ends;

    Quaternion acc('1', false);

    for (int i = beg; i < sz(s); ++i)
    {
        acc *= Quaternion(s[i], false);

        if (acc == q)
            ends.pb(i + 1);
    }

    return ends;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);

    Quaternion::setup();

    int cases_amount;
    cin >> cases_amount;

    for (int test_case = 1; test_case <= cases_amount; ++test_case)
    {
        int str_length, repeats;
        cin >> str_length >> repeats;

        string raw_s;
        cin >> raw_s;

        string s;
        FOR(i, repeats)
            s += raw_s;

        // ---

        bool ans;

        {
            bool i_found = false;
            bool j_found = false;
            Quaternion acc('1', false);

            const Quaternion i_quat('i', false);
            const Quaternion j_quat('j', false);
            const Quaternion k_quat('k', false);

            const Quaternion minus_one('1', true);

            for (int i = 0; i < sz(s); ++i)
            {
                acc *= Quaternion(s[i], false);

                if (acc == i_quat)
                    i_found = true;

                if (i_found && (minus_one * i_quat * acc) == j_quat)
                    j_found = true;
            }


            ans = (i_found && j_found && (j_quat * i_quat * acc) == k_quat);
        }

        cout << "Case #" << test_case << ": " << (ans ? "YES" : "NO") << "\n";
    }

    return 0;
}
