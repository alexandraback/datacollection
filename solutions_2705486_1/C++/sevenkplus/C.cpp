#include<cstdio>
#include<string>
#include<queue>
#include<cstring>
#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 1000000007
#define N 600010
#define M 1200010
bool e[M];int p[M][26],L=1,d[M*5],d2[M*5],v[M*5],MK;queue<int> q,q2;
void upd(int x,int y,int z)
{
	int x1=x*5+y;
	if(v[x1]!=MK)q2.push(x1);
	if(v[x1]!=MK||d2[x1]>z)
		d2[x1]=z,v[x1]=MK;
	if(e[x])
	{
		int y1=1*5+y;
		if(v[y1]!=MK)q2.push(y1);
		if(v[y1]!=MK||d2[y1]>z)
			d2[y1]=z,v[y1]=MK;
	}
}
void upd(int c)
{
	while(!q2.empty())q2.pop();
	while(!q.empty())
	{
		int _x=q.front();q.pop();
		int x=_x/5,y=_x%5;
		if(p[x][c])upd(p[x][c],max(y-1,0),d[_x]);
		if(!y)
		{
			for(int i=0;i<26;i++)
				if(p[x][i])upd(p[x][i],4,d[_x]+1);
		}
	}
	memcpy(d,d2,sizeof d);
	swap(q,q2);
}
int main()
{
	ifstream fi("garbled_email_dictionary.txt");
	string s;
	while(fi>>s)
	{
		int w=1;
		for(int i=0;i<(int)s.length();i++)
		{
			int c=s[i]-'a';
			if(!p[w][c])p[w][c]=++L;
			w=p[w][c];
		}
		e[w]=1;
	}
	int _;scanf("%d",&_);
	for(int __=1;__<=_;__++)
	{
		string s;cin>>s;
		memset(v,-1,sizeof v);
		while(!q.empty())q.pop();
		d[1*5]=0;q.push(1*5);
		for(int i=0;i<(int)s.length();i++)MK=i,upd(s[i]-'a');
		int S=INF;
		for(int i=0;i<=4;i++)
			if(v[1*5+i]==MK)S=min(S,d[1*5+i]);
		printf("Case #%d: %d\n",__,S);
	}
	return 0;
}