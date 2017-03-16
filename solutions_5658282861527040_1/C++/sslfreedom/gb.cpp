#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std; 

typedef long long LL;
const int N=200;

int n;
LL ans, a, b, c;
LL f[N][2][2];


void init()
{
	cin >> a >> b >> c;
	--a; --b;
}

LL g[2][2];

void work()
{
	int tn=29;
	ans=0;
	f[tn+1][0][0]=1;
	f[tn+1][0][1]=0;
	f[tn+1][1][0]=0;
	f[tn+1][1][1]=0;
	for (int i=tn; i>=0; --i)
	{
		int ta=(a & (1 << i));
		int tb=(b & (1 << i));
		int tc=(c & (1 << i));
		g[1][1]=0;
		g[1][0]=0;
		g[0][1]=0;
		g[0][0]=0;
		//11
		g[1][1]+=f[i+1][1][1]*3ll;
		//01
		if (ta)
		{
			g[1][1]+=f[i+1][0][1]*2ll;
			g[0][1]+=f[i+1][0][1];
		}
		else 
			g[0][1]+=f[i+1][0][1]*2ll;
		//10
		if (tb)
		{
			g[1][1]+=f[i+1][1][0]*2ll;
			g[1][0]+=f[i+1][1][0];
		}
		else g[1][0]+=f[i+1][1][0]*2ll;
		//00
		if (!ta && !tb)
			g[0][0]+=f[i+1][0][0];
		if (ta && !tb)
		{
			g[1][0]+=f[i+1][0][0];
			g[0][0]+=f[i+1][0][0];
		}
		if (!ta && tb)
		{
			g[0][1]+=f[i+1][0][0];
			g[0][0]+=f[i+1][0][0];
		}
		if (ta && tb)
		{
			g[0][1]+=f[i+1][0][0];
			g[1][0]+=f[i+1][0][0];
			g[1][1]+=f[i+1][0][0];
		}

		if (tc)
		{
			f[i][1][1]=0;
			f[i][1][0]=0;
			f[i][0][1]=0;
			f[i][0][0]=0;
			// 11
			f[i][1][1]+=f[i+1][1][1];
			//01
			if (ta)
				f[i][0][1]+=f[i+1][0][1];
			//10
			if (tb)
				f[i][1][0]+=f[i+1][1][0];
			//00
			if (ta && tb)
				f[i][0][0]+=f[i+1][0][0];
			LL e=(1 << LL(i));
			LL ra=(a & ((1 << i)-1))+1ll;
			LL rb=(b & ((1 << i)-1))+1ll;
			ans+=g[1][1]*e*e+g[0][1]*ra*e+g[1][0]*e*rb+g[0][0]*ra*rb;
//			cout << e << endl;
//			cout << ra << endl;
//			cout << rb << endl;
//			cout << g[1][1] << endl;
//			cout << g[0][1] << endl;
//			cout << g[1][0] << endl;
//			cout << g[0][0] << endl;

//			cout << ans << endl;
		}
		else 
		{
			f[i][1][1]=g[1][1];
			f[i][1][0]=g[1][0];
			f[i][0][1]=g[0][1];
			f[i][0][0]=g[0][0];
		}
	}
}

int main()
{
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	int cas;
	scanf("%d", &cas);
	for (int k=1; k<=cas; ++k)
	{
		printf("Case #%d: ", k);
		init();
		work();
		cout << ans << endl;
	}
}
