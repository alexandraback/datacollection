
//~        Author : Sarvesh Mahajan                             
//               IIIT,Hyderabad                                   
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef ONLINE_JUDGE
//#define DEBUG
#endif

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define For(i,a,b) for(i=a;i<b;i++)
#define loop(i,b) for(i=0;i<b;i++)
#define Loop(i,b) for(i=1;i<=b;i++)
#define pi(n) cout<<n<<' '
#define si(n) cin>>n
const int MOD=1e9+7;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef long long LL;
#define F first
#define S second
#define sz(x) (int) x.size()
#define pLL(x) cout<<x<<' '
#define fill(x,c) memset(x,c,sizeof(x))
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#ifdef DEBUG
#define DB(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define DB2(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
#define DB3(x, y, z)       cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<" | "<<#z<<": "<<z<<endl;
#else
#define DB(x)
#define DB2(x,y)
#define DB3(x,y,z)
#endif

LL rev(LL x)
{
	int ret=0;
	while(x)
	{
		int p=x%10;
		ret*=10;
		ret+=p;
		x/=10;
	}
	return ret;
}




int bfs(int start,int dest)
{
	unordered_map<LL,bool> vis;
	unordered_map<LL,int> dist;
	queue<LL> q;
	q.push(start);
	dist[start]=0;
	while(!q.empty())
	{
		LL p=q.front();
		q.pop();
		if(p == dest)
			return dist[p];
		int p1=p+1;
		int p2=rev(p);
		if(!vis[p1])
		{
			q.push(p1);
			dist[p1]=dist[p]+1;
			vis[p1]=1;
		}
		if(!vis[p2])
		{
			q.push(p2);
			dist[p2]=dist[p]+1;
			vis[p2]=1;
		}
	}

	return 0;
}
		






#undef int
int main()
{
int n,t,m,l,k,ans,i,j,res=0,fl;
t=1;
cin>>(t);
int T=t;
Loop(t,T)
{
	cin>>n;
	printf("Case #%d: %d\n",t,bfs(1,n)+1);


}
return 0;
}
