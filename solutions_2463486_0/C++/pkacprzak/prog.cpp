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

bool palindrom[1010];
int dp[1010];

bool is_palindrom(int n)
{
    string s = "";
    while(n > 0)
    {
        s += (char) (n % 10);
        n /= 10;
    }
    for(int i = 0; i < s.length() / 2.0; i++)
    {
        if(s[i] != s[s.length() - 1 - i]) return 0;
    }
    return 1;
}
int current_test;
void output(int res)
{
    printf("Case #%d: %d\n", current_test, res);
}
int main()
{
    int t, a, b;
    REP(n, 0, 1000)
    {
        palindrom[n] = is_palindrom(n);
    }
    dp[0] = 1;
    REP(i, 1, 1000)
    {
        dp[i] = dp[i - 1];
        int sq = (int)floor(sqrt(i));
        if(sq * sq == i && palindrom[i] && palindrom[sq]) dp[i]++;
    }
    scanf("%d", &t);
    for(current_test = 1; current_test <= t; current_test++)
    {
        scanf("%d %d", &a, &b);
        output(dp[b] - dp[a - 1]);
    }
    return 0;
}
