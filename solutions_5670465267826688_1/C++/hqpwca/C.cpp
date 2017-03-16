#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<vector>
#include<functional>
#include<string>
#define INF 1000000007
#define ll long long
#define rep(i,k) for(int i=G.start[k];i!=INF;i=G.next[i])

using namespace std;

int L,res[100005],len;
ll X;
string s;
char trans[5]={'\0','1','i','j','k'};
int mp[5][5]={{0,0,0,0,0},
			  {0,1,2,3,4},
			  {0,2,-1,4,-3},
			  {0,3,-4,-1,2},
			  {0,4,3,-2,-1}};
void change(string k)
{
	memset(res,0,sizeof(res));
	len=k.size();
	for(int i=0;i<len;i++)
		for(int j=1;j<=4;j++)
			if(k[i]==trans[j])
				res[i]=j;
}

int MP(int a,int b)
{
	int ans=1;
	if(a<0)ans*=-1,a*=-1;
	if(b<0)ans*=-1,b*=-1;
	return ans*mp[a][b];
}

int main()
{
freopen("t.in","r",stdin);
freopen("t.out","w",stdout);

	ios::sync_with_stdio(false);
	
	int T;
	cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		bool ans=false;
		cout<<"Case #"<<cas<<": ";
		
		cin>>L>>X>>s;
		
		change(s);
		if(X<3&&len*X<3)
		{
			cout<<"NO"<<endl;
			continue;
		}
		int m=1;
		for(int i=0;i<len;i++)
			m=MP(m,res[i]);
		
		int z=X%4,n=1;
		for(int i=0;i<z;i++)n=MP(n,m);
		
		if(n==-1)
		{
			if(X>6)X=6;
			string ts=s;
			for(int i=0;i<X-1;i++)
				s+=ts;
			change(s);
			
			m=1;
			bool fg=false;
			for(int i=0;i<len;i++)
			{
				m=MP(m,res[i]);
				if(m==2)fg=true;
				if(fg&&m==4)
				{
					ans=true;
					break;
				}
			}
		}
		
		if(ans)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
    
	return 0;
}
