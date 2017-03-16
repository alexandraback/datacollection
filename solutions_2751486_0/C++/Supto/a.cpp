#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>

#define SQR(x) ((x)*(x))
#define LL long long int
#define LLU long long unsigned
#define pb push_back
#define pp pop_back
#define MP make_pair
#define sz size()
#define VI vector<int>
#define QI queue<int>
#define SI stack<int>
#define ff first
#define ss second
#define MII map<int, int>
#define SD(a) scanf("%d", &a)
#define SD2(a, b) scanf("%d %d", &a, &b)
#define SDL(a) scanf("%lld", &a)
#define SDL2(a, b) scanf("%lld %lld", &a, &b)
#define NL puts("")
#define CLR(a) memset(a, 0, sizeof(a))
#define SET(a) memset(a, -1, sizeof(a))
#define rep(i, init, n) for(i=init; i<n; i++)
#define repv(i, init, n) for(i=init; i>n; i--)
#define rep1(i, init, n) for(i=init; i<=n; i++)
#define repv1(i, init, n) for(i=init; i>=n; i--)
#define popcount(n) __builtin_popcount(n)
#define popcountl(n) __builtin_popcountll(n)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

//If Long Long (mask & (1LL << k))
#define check(mask, k) (mask & (1 << k))
#define set1(mask, k) (mask | (1 << k))
#define set0(mask ,k) (mask & (~(1<<k)))

#define MAXN 10010
#define EPS 1e-9
#define INF 1000000000
#define MOD 747474747
#define pi acos(-1.0)
using namespace std;

char inp[1000005];
bool isvowel(int i)
{
    if(inp[i]=='a' || inp[i]=='e' || inp[i]=='i' || inp[i]=='o' || inp[i]=='u') return 1;
    return 0;
}

int main()
{
    READ("A-small-attempt0.in");
    WRITE("output.txt");
    int ncase, tcase, len, l, i, m, cnt, ans, start, ns, s;
    SD(ncase);
    rep1(tcase, 1, ncase)
    {
        scanf("%s", inp);
        SD(l);
        len=strlen(inp);
        ans=0;
        cnt=0;
        m=0;
        start=0;
        for(i=0; i<len; i++)
        {
            if(isvowel(i))
            {
                cnt=0;
                start=i+1;
            }
            else cnt++;
            if(cnt==l)
            {
                s=len-i;
                ans+=((start-m)*s)+s;
                m=start+1;
                cnt--;
                start++;
            }
        }
        printf("Case #%d: %d\n", tcase, ans);
    }
    return 0;
}
