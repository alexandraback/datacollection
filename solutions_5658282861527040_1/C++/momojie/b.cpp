#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;

const int maxs = 32;

LL f[40][2][2][2][2];
int x[40],y[40],z[40];
LL xx[40],yy[40],zz[40];

LL solve()
{
	int a,b,k;
	scanf("%d%d%d",&a,&b,&k);
	a--;
	b--;
	k--;
	for (int i = 0 ; i < maxs; i++)
	{
		x[i] = ((a & (1 << i)) > 0);
		y[i] = ((b & (1 << i)) > 0);
		z[i] = ((k & (1 << i)) > 0);
	}
	for (int i = 0 ; i < maxs ; i++)
	{
		xx[i] = x[i] ? (1 << i) : 0;
		if (i) xx[i] += xx[i-1];
		yy[i] = y[i] ? (1 << i) : 0;
		if (i) yy[i] += yy[i-1];
		zz[i] = z[i] ? (1 << i) : 0;
		if (i) zz[i] += zz[i-1];
	}
	memset(f,0,sizeof(f));
	f[maxs][0][0][0][0] = 1;
	LL ret = 0;
	for (int i = maxs ; i > 0 ; i--)
		for (int p = 0 ; p < 2 ; p++)
			for (int q = 0 ; q < 2 ; q++)
				for (int u = 0 ; u < 2 ; u++)
					for (int v = 0 ; v < 2 ; v++)
					{
						if (f[i][p][q][u][v] == 0) continue;
//						printf("%d %d %d %d %d %I64d\n",i,p,q,u,v,f[i][p][q][u][v]);
						if ((p & q) < z[i])
						{
							LL lf , rt;
							if (u) lf = (1 << (i));
							else lf = xx[i-1] + 1;
							if (v) rt = (1 << (i));
							else rt = yy[i-1] + 1;
	//						printf("%d %d %d %d %d %I64d %I64d\n",i,p,q,u,v,lf,rt);
							ret += f[i][p][q][u][v] * (lf *rt);
						}
						else
						{
							for (int pp = 0 ; pp < 2 ; pp++)
							{
								if (!u && pp > x[i-1]) continue;
								for (int qq = 0 ; qq < 2 ; qq++)
								{
									if (!v && qq > y[i-1]) continue;
									if ((pp & qq) > z[i-1]) continue;
									f[i-1][pp][qq][u|(pp<x[i-1])][v|(qq<y[i-1])]
										+= f[i][p][q][u][v];
	//								printf("%d %d %d %d %d %I64d\n",
	//										i-1,pp,qq,u|(pp<x[i-1]),v|(qq<y[i-1]),f[i-1][pp][qq][u|(pp<x[i-1])][v|(qq<y[i-1])]);

								}
							}
						}
					}
	for (int p = 0 ; p < 2 ; p++)
		for (int q = 0 ; q < 2 ; q++)
			for (int u = 0 ; u < 2 ; u++)
				for (int v = 0 ; v < 2 ; v++)
					ret += f[0][p][q][u][v];
	return ret;
}

int main()
{
	int t;
	int cas = 0;
	scanf("%d",&t);
	while (t--)
	{
		printf("Case #%d: ",++cas);
		cout<<solve()<<endl;
	}
	return 0;
}
