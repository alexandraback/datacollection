#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#define N 1004
#define M 1003
#define ll long long
#define inf 1<<29
#define mod 1000000007
#define lson (id<<1)
#define rson (id<<1|1)

#define eps 1e-11
#define pii pair<int,int>
#define pdd pair<double,double>
#define It map<unsigned,string>::iterator
#define MP(i,j) make_pair(i,j)

int f[132][132],c[123][123];
int n,m,h;
struct A{int i,q;double t;}e,t;
bool operator <(A a,A b)
{
	return a.t>b.t;
}
bool mat[132][132];
priority_queue<A>que;
int fx[4][2]={1,0,0,1,-1,0,0,-1};
int nok(int i,int q)
{
	return i<0||q<0||i>=n||q>=m||f[i][q]-c[i][q]<50;
}
double qiu(){
	memset(mat,0,sizeof(mat));
	while(!que.empty())que.pop();
	e.i=e.q=0;
	e.t=0;
	que.push(e);
	while(que.size())
	{
		e=que.top();
		que.pop();
		//cout<<e.i<<"  "<<e.q<<"  "<<e.t<<endl;
		if(mat[e.i][e.q]++)continue;
		if(e.i==n-1&&e.q==m-1)return e.t;
		for(int z=0;z<4;z++)
		{
			t=e;
			t.i+=fx[z][0];
			t.q+=fx[z][1];
			if(nok(t.i,t.q))continue;
		//	cout<<t.i<<"  "<<t.q<<endl;
			int mn=min(f[e.i][e.q],f[t.i][t.q]);
			int mx=max(c[e.i][e.q],c[t.i][t.q]);
			if(mn-mx<50)continue;
			double ts=mn-50;
			ts=h-ts;
			ts/=10;
			ts=max(ts,e.t);
		//	cout<<ts<<endl;
			if(ts==0)t.t=0;
			else if(h-ts*10<c[e.i][e.q]+20)t.t=ts+10;
			else t.t=ts+1;
			que.push(t);

		}

	}

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif

	int t,cas=1;
	cin>>t;
	while(t--)
	{
		cin>>h>>n>>m;
		for(int i=0;i<n;i++)
			for(int q=0;q<m;q++)
				cin>>f[i][q];
		for(int i=0;i<n;i++)
			for(int q=0;q<m;q++)
				cin>>c[i][q];
		printf("Case #%d: %.1lf\n",cas++,qiu());
	}
	return 0;
}

