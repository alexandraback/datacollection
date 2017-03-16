
/*
Author : Vivek Hamirwasia

A programmer started to cuss,
Because getting to sleep was a fuss.
As he lay there in bed,
Looping 'round in his head,
Was: while(!asleep()) sheep++;

 */
#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LLD long long
#define VI vector < int >
#define PII pair < int , int >

#define gi(x) scanf("%d",&x)
#define gl(x) scanf("%lld",&x)
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)

#define pis(x) printf("%d ",x)
#define pls(x) printf("%lld ",x)
#define pin(x) printf("%d\n",x)
#define pln(x) printf("%lld\n",x)
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")
#define MAX 1000000000

string pin[100];
vector<int> V[100];
vector<int> P;
bool vis[10];

int n, m, cur;
bool dfs(int idx)
{
   if(cur == n-1) return true;

   int sz = V[idx].size();
   for(int i=0;i<sz;i++)
   {
       int ver = V[idx][i];
       if(!vis[ver] && ver == P[cur+1])
       {
	   vis[ver] = true;
	   cur++;
	   bool k = dfs(ver);
	   if(k)
	       return k;
	   else
	   {
	       i = -1;
	   }
       }
       
   }
   return false;
}

bool isvalid()
{
    memset(vis,false,sizeof vis);
    vis[P[0]]=true;
    cur = 0;
    return dfs(P[0]);
}

int main()
{
    int t;
    cin>>t;
    int kase = 0;
    while(t--)
    {
	P.clear();
	kase++;
	cin>>n>>m;
	string ans;

	for(int i=1;i<=9;i++)
	    ans += "99999";

	for(int i=1;i<=n;i++)
	{
	    V[i].clear();
	    cin>>pin[i];
	    P.PB(i);
	}

	for(int i=0;i<m;i++)
	{
	    int a,b;
	    cin>>a>>b;
	    V[a].PB(b);
	    V[b].PB(a);
	}


	do
	{
	    if(isvalid())
	    {
		string can;
		for(int i=1;i<=n;i++)
		{
		    int x = P[i-1];
		    can += pin[x];
		}
		if( (can.size()<ans.size()) || (can.size()==ans.size() && can<ans))
		    ans = can;
	    }

	}while(next_permutation(P.begin(), P.end()));

	cout<<"Case #"<<kase<<": "<<ans<<endl;	

    }

    return 0;
}
