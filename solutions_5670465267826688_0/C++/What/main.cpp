#include <iostream>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <vector>

using namespace std;

template <typename T> int sgn(T val) { return (T(0) < val) - (val < T(0)); }

#define I 2
#define J 3
#define K 4

int mulM[5][5] =
{
    {0, 0, 0, 0, 0},
    {0, 1, I, J, K},
    {0, I,-1, K,-J},
    {0, J,-K,-1, I},
    {0, K, J,-I,-1},
};

struct Q
{
    signed char v;
    explicit Q(int vv = 1) : v(vv) {}
};
Q mulQ(Q a, Q b) { return Q(sgn(a.v) * sgn(b.v) * mulM[abs(a.v)][abs(b.v)]); }
Q mrlQ(Q a, Q b) { return mulQ(b, a); }
Q operator * (Q a, Q b) { return mulQ(a, b); }
bool operator == (Q a, Q b) { return a.v == b.v; }
bool operator != (Q a, Q b) { return a.v != b.v; }

Q mul1(vector<Q> const & S, int const X)
{
    vector<Q>SX(S.size() * X);
    for (size_t i = 0; i < SX.size(); ++i) SX[i] = S[i % S.size()];

    return accumulate(SX.begin(), SX.end(), Q(1), mulQ);
}

template <typename IterT, typename OpT>
int64_t firstQ(Q v, IterT beg, IterT end, int64_t const X, OpT op)
{
    Q q;
    int64_t res = 0;
    for (int64_t x = 0; x < X; ++x)
    {
        for (IterT it = beg; it != end; ++it)
        {
            q = op(q, *it);
            ++res;
            if (q == v)
                return res;
        }
    }
    return res + 1;
}

bool solve1(vector<Q> const & S, int64_t const X)
{
    if (Q(-1) != mul1(S, X))
        return false;
    return firstQ(Q(I), S.begin(), S.end(), X, mulQ) + firstQ(Q(K), S.rbegin(), S.rend(), X, mrlQ) < X * static_cast<int64_t>(S.size());
}

int main()
{
    assert(Q(I) * Q(J) == Q(K));
    assert(Q(I) * Q(I) == Q(-1));
    assert(Q(I) * Q(-I) == Q(1));

    int caseCount = 0;
    cin >> caseCount;

    for (int i = 0; i < caseCount; ++i)
    {
        int L, X;
        string s;
        cin >> L >> X >> s;
        assert(s.size() == static_cast<size_t>(L));
        vector<Q> S(s.size());
        for (int j = 0; j < L; ++j)
        {
                 if (s[j] == '1') S[j] = Q(1);
            else if (s[j] == 'i') S[j] = Q(I);
            else if (s[j] == 'j') S[j] = Q(J);
            else if (s[j] == 'k') S[j] = Q(K);
            else assert(false);
        }
        cout << "Case #" << i + 1 << ": " << (solve1(S, X) ? "YES" : "NO") << endl;
    }
    return 0;
}

