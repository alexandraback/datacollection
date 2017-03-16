#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string.h>
#include <list>
#include <bitset>
#include <sstream>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cctype>
#include <fstream>
using namespace std;

#define GI              ({int t;scanf("%d",&t);t;})
#define GL              ({LL t;scanf("%lld",&t);t;})
#define GD              ({double t;scanf("%lf",&t);t;})
#define FOR(i,a,b)      for(int i=a;i<b;i++)
#define REP(i,n)        FOR(i,0,n)
#define FOREACH(i,a)    for(typeof((a).begin()) i=(a).begin();i!=(a).end();i++)
#define SZ(a)           (int)(a.size())
#define ALL(a)          a.begin(),a.end()
#define SORT(a)         sort(ALL(a));
#define REVERSE(a)      reverse(ALL(a))
#define UNIQUE(a)       SORT(a),(a).resize(unique(ALL(a))-(a).begin())
#define fill(x,a)       memset(x, a, sizeof(x))
#define pb              push_back
#define mp              make_pair
#define INF             (int)1e9
#define EPS             double(1e-9)
#define abs(a)          ((a)<0?-(a):(a))
#define dbg(x)          (cerr << #x << ":" << (x) << endl)

typedef long long LL;
typedef vector < int > VI;
typedef vector < string > VS;
typedef pair < int, int > PII;

int main()
{	
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	
	int Kase=GI;
	int n;
	int a[505];
	LL sum=0,fsum=0;
	set < int > myset;
	FOR(kase,1,Kase+1)
	{
        cin>>n;
        REP(i,n) cin>>a[i];
        printf("Case #%d:\n",kase);
        myset.clear();
        bool done=false;
        int cnt=0;
        for(int mask=1; mask<(1<<n);mask++)
        {
            sum=0;
            for(int i=0;i<n;i++)
            {
                if((1<<i)&mask)
                {
                    sum+=a[i];
                }
            }
            if(myset.count(sum)>0) {fsum=sum; done=true; break;}
            else myset.insert(sum);
            if(done) break;
        }
        if(!done) printf("Impossible\n");
        else
        {
                done=false;
        for(LL mask=1LL; mask!=(1LL<<n);mask++)
        {
            sum=0;
            for(int i=0;i<n;i++)
            {
                if((1<<i)&mask)
                {
                    sum+=a[i];
                }
            }
            if(sum==fsum)
            {
                for(int i=0;i<n;i++)
                {
                    if((1<<i)&mask)
                    {
                        printf("%d ",a[i]);
                    }
                }
                cout<<endl;
                cnt++;
                if(cnt==2) {done=true; break;}
            }
            if(done) break;
        }
    }    
    }




//while(1);
return 0;
}
