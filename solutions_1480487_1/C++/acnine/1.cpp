#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;
typedef pair<int,int>pi;

#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
#define FOR(i,a,b)				for(int i=a;i<b;i++)
#define REP(i,n)				FOR(i,0,n)
#define foreach(v,c)            for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp						make_pair
#define tri(a,b,c)				mp(a,mp(b,c))
#define XX						first
#define YY						second.first
#define ZZ						second.second
#define pb						push_back
#define fill(a,v) 				memset(a,v,sizeof a)
#define all(x)					x.begin(),x.end()
#define SZ(v)					((int)(v.size()))
#define DREP(a)					sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)			(lower_bound(all(arr),ind)-arr.begin())
#define debug(args...)			{dbg,args; cerr<<endl;}
#define dline					cerr<<endl	
#define F first
#define S second

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("1large.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int I=1;I<=T;I++){
        int N;
        s(N);
        int sum=0;
        pi ar[N];
        for(int i=0;i<N;i++){
            int a;
            s(a);   
            ar[i] = pi(a,i);
            sum+= a;
        }
        int tot = sum;
        sum*=2;
        sort(ar,ar+N);
        double ans[N];
        int number  = N;
        for ( int i=N-1;i>=0;i--){
            
            double v = sum*1.0/(number*1.0);
            if ( ar[i].F*1.0 >= v ){
                number--;
                sum-= ar[i].F   ;
                ans[ar[i].S]=0.0;
            }
            else{
                ans[ar[i].S] = (v - ar[i].F)/(tot*1.0);
            }
            
        }
        printf("Case #%d: ",I);
        for(int i=0;i<N;i++)printf("%.8lf ",ans[i]*100);
        printf("\n");
        
    }
    
return 0;
}
