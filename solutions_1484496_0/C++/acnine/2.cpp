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
int half;
int hmask=-1;
int ar[20];

int N;
int store[2000001];
bool isset(int mask,int i)
{
    return ((mask&(1<<i))!=0);   
}
void rec(int mask,int sum)
{
    //cout<<mask<<endl;
    //store[sum].push_back(mask);
    
    for(int i=0;i<N;i++){
        if ( isset(mask,i)==false)
            rec(mask^(1<<i),sum+ar[i]);   
    }    
}
void clear()
{
    //for(int i=0;i<=2000000;i++)store[i].clear();   
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int I=1;I<=T;I++){
        
        scanf("%d",&N);
        memset(store,-1,sizeof(store));
        int sum=0;
        for(int i=0;i<N;i++)scanf("%d",&ar[i]),sum+=ar[i];
        
        sort(ar,ar+N);
        printf("Case #%d: \n",I);
        bool ans=false;
        for ( int i=1;i<=(1<<N);i++){
            
            int sum=0;
            for(int j=0;j<N;j++){
                if ( isset(i,j)){
                    sum+= ar[j];   
                }   
            }
            if ( store[sum]==-1){
                store[sum]=i;   
            }
            else{
                int f = store[sum];
                for(int j=0;j<N;j++)if ( isset(f,j)==true)printf("%d ",ar[j]);
                printf("\n");
                for(int j=0;j<N;j++)if ( isset(i,j)==true)printf("%d ",ar[j]);
                printf("\n"); 
                ans=true;
                break;
            }
        }
        if ( ans==false)printf("Impossible\n");
        
        //rec(0,0);
        
        
        /*bool ans = false;
        int a=-1,b=-1;
        for(int i=1;i<=sum && ans==false;i++){
            for ( int j=store[sum].size()-1;j>=0;j--){
                for ( int k=store[sum].size()-1;k>j;k++){
                    if ( (store[sum][j]&store[sum][k])==0){
                        a=store[sum][j];
                        b=store[sum][k];
                        ans=true; 
                    }
                }   
            }
        }
        printf("Case #%d: ",I);
        if ( a!=-1 && b!=-1){
            for ( int i=0;i<N;i++){
                if ( isset(a,i))printf("%d ",ar[i]);   
            } 
            for ( int i=0;i<N;i++){
                if ( isset(b,i))printf("%d ",ar[i]);   
            } 
        }
        else printf("Impossible\n");
        
        clear();
        */
    }
    
return 0;
}
