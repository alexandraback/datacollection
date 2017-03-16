///     Raihan Ruhin
///     CSE, Jahangirnagar University.
///     Dhaka-Bangladesh.
///     id: raihanruhin (topcoder / codeforces / codechef / hackerrank / uva / uvalive / spoj), 3235 (lightoj)
///     mail: raihanruhin@ (yahoo / gmail / facebook)
///     blog: ruhinraihan.blogspot.com

#include<bits/stdc++.h>
using namespace std;

#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define PI acos(-1.0)

#define MOD 1000000007
#define MX 100010

#define READ freopen("A-small-attempt0 (1).in", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)

int main()
{
    READ;
    WRITE;
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc,kk=1, n, r, c, w;

    cin>>tc;
    while(tc--)
    {
        cin>>r>>c>>w;
        int res=c/w;

        res*=r;
        if(c%w) res++;
        res+=(w-1);
        cout<<"Case #"<<kk++<<": "<< res <<"\n";
    }
    return 0;
}

