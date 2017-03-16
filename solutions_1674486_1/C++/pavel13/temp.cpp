#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <string.h>
using namespace std;
#define REP(i,n) for(int i=0,n_=(n);i<n_;i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOR(i,a,b) for (int i=a,b_=b;i<=(b);i++)
#define ALL(a) a.begin(),a.end()
#define SZ(a) (int)(a).size()
#define SORT(a) sort(ALL(a))
#define INF 1073741823
#define DEB(x) cerr<<#x<<":"<<x<<"\n"
#define PB(b) push_back(b)
#define i64 long long
#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

vector<int> SplitInt(string &s)
{
	vector<int>Res;int tmp;stringstream a(s);
	while (a>>tmp){Res.push_back(tmp);}return Res;
}

vector<string> SplitStr(string &s)
{
	vector<string>Res;string tmp;stringstream a(s);
	while (a>>tmp){Res.push_back(tmp);}return Res;
}

//////////////////////////////////////////////////////////////
int tree[10000];
int find(int a)
{

	if (tree[a]==a)
		return a;
	return find(tree[a]);
}
vector<int> G[1001];
int n;
int V[1233];
void dfs(int x)
{

	REP(i,SZ(G[x]))
	{

			V[G[x][i]]++;
			if (V[G[x][i]]<=1)
			dfs(G[x][i]);
			
			

	}
}

int main ()
{
	int c,k;

	scanf ("%d",&c);

	FOR(cas,1,c)
	{
		
		int res=0,m,x;
		string str="No";
		scanf ("%d",&n);
		FOR(i,0,n)
			tree[i]=i;
//		DEB(n);
		memset(G,0,sizeof G);
		REP(i,n)
		{
			scanf ("%d",&m);
			REP(j,m)
			{
				scanf("%d",&x);
				G[i+1].PB(x);
//				int fa=find(i+1);
//				int fb=find(x);
////				DEB(fa);
////				DEB()
//				if (fa==fb)
//				{
//					str="Yes";
//				}
//				else
//				{
//					tree[fb]=fa;
//					tree[x]=fa;
//					tree[i+1]=fa;
//				}
			}
		}
//		REP(i,n){
//		REP(j,n)
//			printf ("%d",G[i+1][j+1]);
//			printf ("\n");
//		}
		FOR(i,1,n)
		{
			
			memset(V,0,sizeof V);
			V[i]=1;
			dfs(i);
			FOR(j,1,n)
			{
//				printf ("%d ",V[j]);
				if (V[j]>=2)
					str="Yes";
			}
//			DEB(str);
			if (str=="Yes")
				break;
		}
		printf ("Case #%d: %s",cas,str.c_str());

		printf ("\n");
	}
	return 0;
}

