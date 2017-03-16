#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<sstream>
using namespace std;
#define INF 2000000000
#define INFLL (1LL<<62)
#define SS ({int x;scanf("%d", &x);x;})
#define SSL ({lint x;scanf("%lld", &x);x;})
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i,m,n) for(int i=(m);i<(n);i++)
#define ull unsigned long long
#define lint long long
#define MX 10000001

vector<vector<int> > graph(50);
int n;
int in[50],out[50];
lint sum;
vector<int> st,end;


bool dfs(int fr,int to)
{
	if(fr==to)
	{
//		cout<<"yes "<<fr<<" "<<to<<endl;
		return true;
	}
	int sz=graph[fr].size();
	rep(i,sz)
	{
		if(dfs(graph[fr][i],to))
			return true;
	}
	return false;
}

int cnt(int fr,int to)
{
	int sz=graph[fr].size();
	int tot=0;
	rep(i,sz)
	{
		if(dfs(graph[fr][i],to))
		{
			//cout<<"yes\n";
			tot++;
		}
		if(tot>1)
			break;
	}
	return tot;
}

int main()
{
	int i,j,k,l,m,t;
	t=SS;
	for(k=1;k<=t;++k)
	{
		printf("Case #%d:",k);
		rep(i,50)
			graph[i].clear();
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		n=SS;
		sum=0;
		rep(i,n)
		{
			m=SS;
			rep(j,m)
			{
				l=SS;
				graph[i].push_back(l-1);
				in[l-1]++;
				out[i]++;
			}
		}
//		int sa=st.size();
//		int se=end.size();
		bool flag=false;
		for(int i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				
				if(cnt(i,j)>1)
				{
					flag=true;
					break;
				}	
			}
			if(flag)
				break;
		}
		if(flag)
			printf(" Yes\n");
		else
			printf(" No\n");
	}	
	return 0;
}
