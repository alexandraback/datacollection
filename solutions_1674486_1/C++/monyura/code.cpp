#pragma comment(linker,"/STACK:128000000")
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef unsigned long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
//#define x first
//#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

bool was[1001]={0};
vector<int> g[1001];
bool ok;

void dfs(int k,int from)
{
	was[k]=1;
	rep(i,0,g[k].size())
		if (g[k][i]!=from)
		{
			if (was[g[k][i]])
				ok=true;
			else
				dfs(g[k][i],k);
		}
}

void test(int T)
{
	int n;
	cin>>n;
	rep(i,0,n)
	{
		int k;
		cin>>k;
		g[i].clear();
		rep(j,0,k)
		{
			int a;
			scanf("%d",&a);
			--a;
			g[i].push_back(a);
		}
	}
	ok=false;
	rep(i,0,n)
	{
		memset(was,0,sizeof(was));
		dfs(i,-1);
		if (ok) break;
	}
	puts(ok?"Yes":"No");
}

void run()
{
	int t;
	cin>>t;
	rep(i,0,t)
	{
		printf("Case #%d: ",i+1);
		test(i+1);
	}
}

#define F_NAME "A-large"
int main()
{
#ifndef F_NAME
		freopen("test.in","r",stdin);
		freopen("test.out","w",stdout);
#else
		freopen(F_NAME".in","r",stdin);
		freopen(F_NAME".out","w",stdout);
#endif
	time_t beg=clock();
	run();
	fprintf(stderr,"Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
	return 0;
}

/*

*/