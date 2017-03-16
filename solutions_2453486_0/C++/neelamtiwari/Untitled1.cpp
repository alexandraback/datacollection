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
#include<string>
 
using namespace std;
 
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
#define FF						first
#define SS						second
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
 

 
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
 
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;
 
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;
 
 
/*Main code begins now */
 
int testnum;
int flag;
int cnt;
 
FILE *f1,*f2;
 
void preprocess()
{
	
}

int mat[][4]={
            {0,1,2,3},
            {4,5,6,7},
            {8,9,10,11},
            {12,13,14,15},
            {0,4,8,12},
            {1,5,9,13},
            {2,6,10,14},
            {3,7,11,15},
            {0,5,10,15},
            {3,6,9,12}
            };
int a[16];            
            
int getsum(int i)
{
int sum=0,j;
for(j=0;j<4;++j)sum+=a[mat[i][j]];
return sum;    
}

void solve()
{
     int sum,i;
	for(i=0;i<10;++i)
	{
    sum=getsum(i);
    if(sum==20||sum==30015)      {fprintf(f2,"Case #%d: X won\n",testnum);return;}
    if(sum==400||sum==30300)     {fprintf(f2,"Case #%d: O won\n",testnum);return;}           
    }
	if(flag==1)	                 {fprintf(f2,"Case #%d: Game has not completed\n",testnum);return;}
	                             {fprintf(f2,"Case #%d: Draw\n",testnum);return;} 
}
 
 
 
bool input()
{
     int i;
     char ch;
     flag=0;
     for(i=0;i<16;++i)
     {
      fscanf(f1,"%c",&ch); 
      while(!(ch=='O'||ch=='X'||ch=='.'||ch=='T'))  fscanf(f1,"%c",&ch);
      if(ch=='X')a[i]=5;
      else if(ch=='O')a[i]=100;
      else if(ch=='.')a[i]=2000;
      else            a[i]=30000;
      if(ch=='.')flag=1;
     }
	return true;
}
 
 
int main()
{
	preprocess();
	int T=1;
	f1=fopen("E:\\A\\input.txt","r+");
	f2=fopen("E:\\output.txt","w");
	if(f1==NULL){cout<<"problem 1\n";}
	if(f2==NULL){cout<<"problem 2\n";}
	fscanf(f1,"%d",&T);
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
return 0;
}
 
