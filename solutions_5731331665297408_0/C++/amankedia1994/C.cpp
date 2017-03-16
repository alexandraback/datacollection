#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

#define sd(x) scanf("%d",&x);
#define slld(x) scanf("%lld",&x);
#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Fill(a, b) memset(a, b, sizeof(a))
#define INF 2000000009

typedef pair<int,int> PII;
typedef vector<int> VI;

#define MAXN 51
stack <int > sta;
bool lst[MAXN][MAXN];
int order[MAXN],k=0;
string ar[MAXN],ans="",fans="",mx="99999";


void solve()
{
	for(int i=0;i<MAXN;i++)
	{
		for(int j=0;j<MAXN;j++)
		{
			lst[i][j]=0;
		}
		ar[i]="";
	}
	while(!sta.empty())sta.pop();
	k=1;
	ans="";fans="";mx="99999";
	int n,m,st=0,a,b;
	sd(n);sd(m)
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
		if(ar[i]<mx)
		{
			mx=ar[i];
			st=i;
		}
	}
	for(int i=0;i<m;i++)
	{
		sd(a);sd(b);
		lst[a-1][b-1]=1;
		lst[b-1][a-1]=1;
	}


	k=0;
	for(int i=0;i<n;i++)
	{
		if(i==st)continue;
		order[k]=i;
		k++;
	}
	mx="99999";
	for(int i=0;i<n;i++)fans+=mx;
	//cout<<fans<<endl;
	do
	{
		//cout<<ar[order[0]]<<" "<<ar[order[1]]<<endl;
		sta.push(st);
		bool flag=0;
		ans=ar[st];
		for(int i=0;i<n-1;i++)
		{
			ans+=ar[order[i]];
			//cout<<"am "<<ans<<" "<<n<<endl;
			while(!sta.empty())
			{
				//cout<<"ab"<<sta.top()<<" "<<order[i]<<endl;;
				if(lst[sta.top()][order[i]]==1)
				{
					sta.push(order[i]);
					break;
				}
				else sta.pop();
			}
			if(sta.empty())
			{
				//cout<<"aman11\n";
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			//cout<<"am "<<ans<<endl;
			if(fans>ans)fans=ans;
		}
		while(!sta.empty())sta.pop();
	} while ( next_permutation(order,order+n-1) );
	cout<<fans<<endl;

}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t=1;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
}

