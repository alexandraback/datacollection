#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

const int MAXN=2007;

struct Node
{
	int i,cnt;
	Node(){}
	Node(int i,int cnt):i(i),cnt(cnt){}
	Node(const Node &p):i(p.i),cnt(p.cnt){}
};

int i,j,k,n,m,t,x,y,tcase,xcase,ansa,ansb,rm,cnt; // ring = a, not ring = b
int f[MAXN],idx[MAXN];
bool v[MAXN],tv[MAXN];
vector<int> e[MAXN];
queue<Node> q; 

int start(int k)
{
	int i,j,res=0;
	Node t;
	while (!q.empty())
	{
		q.pop();
	}
	q.push(Node(k,1));
	while (!q.empty())
	{
		t=q.front();
		res=max(res,t.cnt);
		q.pop();
		for (i=0;i<e[t.i].size();i++)
		{
			if (!v[e[t.i][i]])
			{
				q.push(Node(e[t.i][i],t.cnt+1));
				v[e[t.i][i]]=true;
				rm--;
			}
		}
	}
	// cout<<k<<"-"<<res<<endl;
	return res;
}

int visit(int k)
{
	int i,j,res;
	memset(tv,0,sizeof(tv));
	idx[k]=0;
	tv[k]=true;
	v[k]=true;
	rm--;
	while (rm>0 && !tv[f[k]] && !v[f[k]])
	{
		// cout<<k<<"-"<<f[k]<<endl;
		idx[f[k]]=idx[k]+1;
		k=f[k];
		tv[k]=true;
		v[k]=true;
		rm--;
	}
	if (tv[f[k]])
	{
		res=idx[k]+1-idx[f[k]];
		// cout<<"Ring!"<<res<<endl;
	}
	else
	{
		res=0;
	}
	// cout<<endl;
	return res;
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>tcase;
	xcase=0;
	while (xcase<tcase)
	{
		xcase++;
		cout<<"Case #"<<xcase<<": ";
		memset(f,0,sizeof(f));
		memset(v,0,sizeof(v));
		memset(tv,0,sizeof(tv));
		cin>>n;
		rm=n;
		for (i=0;i<=n;i++)
		{
			e[i].clear();
		}
		for (i=1;i<=n;i++)
		{
			cin>>f[i];
			e[f[i]].push_back(i);
		}
		ansa=0;
		ansb=0;
		for (i=1;i<=n;i++)
		{
			if (f[f[i]]==i && !v[i] && !v[f[i]])
			{
				v[i]=true;
				v[f[i]]=true;
				rm-=2;
				ansa+=start(i);
				ansa+=start(f[i]);
			}
		}
		while (rm>0)
		{
			i=1;
			while (v[i]) i++;
			cnt=visit(i); 
			ansb=max(ansb,cnt);
		}
		// cout<<ansa<<" "<<ansb<<endl;
		cout<<max(ansa,ansb)<<endl;
	}
	return 0;
}

