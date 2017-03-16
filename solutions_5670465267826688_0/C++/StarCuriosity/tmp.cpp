#include <bits/stdc++.h>
using namespace std;

enum NUM{one = 0, i = 1, j = 2, k = 3};

struct Number{
    int sign;
    NUM num;
};

Number prod[4][4];

void init()
{
    for(int i = 0; i < 4; ++i)
        prod[i][0] = prod[0][i] = Number{1, (NUM)i};
    for(int i = 1; i < 4; ++i)
        prod[i][i] = Number{-1,one};
    prod[1][2] = Number{1,k};
    prod[1][3] = Number{-1,j};
    prod[2][1] = Number{-1,k};
    prod[2][3] = Number{1,i};
    prod[3][1] = Number{1,j};
    prod[3][2] = Number{-1,i};
}

Number operator*(Number const& a, Number const& b)
{
    int tmpsign = a.sign * b.sign;
    Number ans = prod[a.num][b.num];
    ans.sign *= tmpsign;
    return ans;
}

Number pow(Number const& a, long long b)
{
    Number ans = Number{1,one};
    Number tmp = a;
    while (b)
    {
        if (b & 1)
            ans = ans * tmp;
        tmp = tmp * tmp;
        b >>= 1;
    }
    return ans;
}

inline Number getNumber(char c)
{
    if (c == 'i')
        return Number{1, i};
    if (c == 'j')
        return Number{1, j};
    return Number{1,k};
}

bool operator== (Number const& a, Number const& b)
{
    return a.sign == b.sign && a.num == b.num;
}

bool operator!= (Number const& a, Number const& b)
{
    return !(a==b);
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    init();
    int T = 100;
    cin >> T;
    for(int test = 1; test <= T; ++test)
    {
        int l = 0;
        long long x = 0;
        cin >> l >> x;
        string s = "ij";
        cin >> s;
        Number cur{1, one};
        for(int i = 0; i < l; ++i)
            cur = cur * getNumber(s[i]);
        cur = pow(cur, x);
        string ans;
        if (cur != Number{-1, one})
        {
            ans = "NO";
        }
        else
        {
            int right = min(l*x, 50001LL);
            cur = Number{1, one};

            int ind = 0;
            for(ind = 0; ind < right; ++ind)
            {
                cur = cur * getNumber(s[ind%l]);
                if (cur == Number{1,i})
                    break;
            }
            if (cur != Number{1,i})
            {
                ans = "NO";
            }
            else
            {
                int indr = 100000 - (100000%l);
                indr = min((long long)indr, l*x);
                cur = Number{1, one};
                for(--indr; indr > ind; --indr)
                {
                    cur = getNumber(s[indr % l]) * cur;
                    if (cur == Number{1, k})
                        break;

                }
                if (cur == Number{1,k})
                    ans = "YES";
                else
                    ans = "NO";
            }
        }
        cout << "Case #" << test << ": " << ans << "\n";
    }

    return 0;
}
