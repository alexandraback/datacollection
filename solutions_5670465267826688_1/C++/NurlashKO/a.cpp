//Solution by Zhusupov Nurlan
#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

typedef long long LL;
typedef map<string , int> MSI;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define pb(x) push_back(x)
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define SZ(t) ((int) t.size())
#define len(t) ((int) t.length())
#define base LL(1e9 + 7)
#define fname ""
#define sz 1000010
#define EPS (1e-8)
#define INF ((int)1e9 + 9)
#define write(xx) printf("%d" , xx);
#define readln(xx) getline(cin , xx)
#define read(xx) scanf("%d" , &xx)
#define mp make_pair

const double PI  = acos(-1.0);

LL l;
int d[4][4] = {{1, 2, 3 , 4}, 
                {2, -1, 4, -3}, 
                {3, -4, -1, 2}, 
                {4, 3, -2, -1}};

int f(int x, int y)
{
    return (x > 0 ? 1 : -1) * (y > 0 ? 1 : -1) * d[abs(x) - 1][abs(y) - 1];
}

bool check(string s, int s1 = 1, int s2 = 1, int s3 = 1, int c = 0)
{
    int p = 0, N = len(s);
    if (N > l)
    {
        while (p < l && s1 != 2)
        {
            s1 = f(s1, s[p]);
            p++;
        }
        for (int i = p; i < l; i++)
            s2 = f(s2, s[i]);
        p = 0;
        while (p < l && s2 != 3)
        {
            s2 = f(s2, s[p]);
            p++;
        }
        for (int i = p; i < l; i++)
            s3 = f(s3, s[i]);
        return s1 == 2 && s2 == 3 && s3 == 4;
    }
    while (p < N && s1 != 2)
    {
        s1 = f(s1, s[p]);
        p++;
    }
    while (p < N && (s2 != 3 || c == 1))
    {
        s2 = f(s2, s[p]);
        p++;
    }
    while (p < N)
    {
        s3 = f(s3, s[p]);
        p++;
    }
    return s1 == 2 && s2 == 3 && s3 == 4;
}

int bin_pow(LL x, LL y)
{
    LL res = 1;
    while (y)
    {
        if (y & 1)
            res = f(res, x);
        x = f(x , x);
        y >>= 1;
    }
    return res;
}


LL test, x;
string s, r;

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    cin >> test;
    for (int T = 1; T <= test; T++)
    {
        cout << "Case #" << T << ": ";
        
        cin >> l >> x;
        cin >> s;
        r = "";
        for (int i = 1; i <= min(x, 10ll); i++)
            r += s;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1') s[i] = 1;
            if (s[i] == 'i') s[i] = 2;
            if (s[i] == 'j') s[i] = 3;
            if (s[i] == 'k') s[i] = 4;
        }
        bool ans = 0;
        int cur = 1;
        for (int i = 0; i < s.length(); i++)
            cur = f(cur, s[i]);
        for (int i = 0 ; i < r.length(); i++)
        {
            if (r[i] == '1') r[i] = 1;
            if (r[i] == 'i') r[i] = 2;
            if (r[i] == 'j') r[i] = 3;
            if (r[i] == 'k') r[i] = 4;
        }
        int p = 0, s1 = 1, s2 = 1, s3 = 1;
        while (p < len(r) && s1 != 2)
        {
            s1 = f(s1, r[p]);
            p++;
        }
        while (p < len(r) && s2 != 3)
        {
            s2 = f(s2, r[p]);
            p++;
        }

        for (int i = p; i < len(r); i++)
            s3 = f(s3, r[i]);
        x = max(0ll, x - 10);
        s3 = f(s3, bin_pow(cur, x));
        ans = (s1 == 2 && s2 == 3 && s3 == 4);
        /*
        if (x == 1)
            ans |= check(s);
        else
        if (cur == 1)
        {
            if (x > 1)
                ans |= check(s + s);
        }
        else
        {
            int s1 = 1;
            for (int i1 = 0; i1 <= 4; i1++)
            {
                int s2 = 1;
                for (int i2 = 0; i2 <= 4; i2++)
                {
                    int s3 = 1;
                    for (int i3 = 0; i3 <= 4; i3++)
                    {
                        int X = x - i1 - i2 - i3;
                        if (X < 0)
                            continue;
                        if (X % 4 == 2)
                            ans |= check(s + s, s1, s2, s3);
                        if (X % 4 == 1 && s3 == 4)
                            ans |= check(s, s1, s2, s3, 1);
                        if (X % 4 == 1 && s1 == 2)
                            ans |= check(s, s1, s2, s3, 1);
                        s3 = f(s3, cur);
                    }
                    s2 = f(s2, cur);
                }
                s1 = f(s1, cur);
            }
        }
        */
        cout << (ans ? "YES" : "NO") << '\n';
    }

}
