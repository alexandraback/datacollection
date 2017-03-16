#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cstring>
#include <ctime>

#include "gmpxx.h"

using namespace std;
#define pb push_back
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
inline void pisz(int n) { printf("%d\n",n); }
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;

typedef long long num;
typedef double fl;
typedef mpz_class big;

void output(int t, string msg)
{
    cout << "Case #" << t << ": " << msg << "\n";
}
void output(int t, int n)
{
    cout << "Case #" << t << ": " << n << "\n";
}
void output_big(int t, num n)
{
    cout << "Case #" << t << ": " << n << "\n";
}

bool is_vowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
int main()
{
    ios_base::sync_with_stdio(0);
    int tests, n;
    string s;
    cin >> tests;
    REP(t, 1, tests)
    {
        cin >> s >> n;
        int m = s.length();
        vector<pair<int, int> > v;
        int tmp = 0;
        FOR(i, m)
        {
            if(!is_vowel(s[i]))
            {
                tmp++;
            }
            else
            {
                tmp = 0;
            }
            if(tmp >= n)
            {
                v.pb(mp(i - (n - 1) + 1, i + 1));
            }
        }
        num res = 0;
        int k = 1;
        FOR(i, v.size())
        {
            int a = v[i].fi;
            int b = v[i].se;
            //cout << a << " " << a - k + 1 << " " << m + 1 - b << endl;
            res += num(a - k + 1) * num(m + 1 - b);
            k = b + 1 - (n - 1);
        }
        output_big(t, res);
    }
    return 0;
}
