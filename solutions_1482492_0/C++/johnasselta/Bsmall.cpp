#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#define MAXN 1007
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(a,b,c) for(int a=b;a<=(c);a++)
#define FORD(a,b,c) for (int a=b;a>=(c);a--)
#define VAR(v,n) __typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)

using namespace std;

typedef long long LL;  

int poz,grawitacje,tt;
long double A,B,C,odl,predkosc_sam,pozycja_sam,delta,wyn,result,roz,droga,g,v,v2,tim;
long double t[MAXN],x[MAXN];
long double czas_zrownania_predkosci;

int main()
{
	scanf("%d",&tt);
	REP(h,tt)
	{
		printf("Case #%d:\n",h+1);
		scanf("%Lf %d %d",&odl,&poz,&grawitacje);
		REP(i,poz) scanf("%Lf%Lf",&t[i],&x[i]);
		REP(i,grawitacje)
		{
			scanf("%Lf",&g);
			if (poz == 1) 
			{
				tim = sqrtl(((long double)(2.0)*odl)/g);
				printf("%Lf\n",tim);
			}
			else
			{
				v = (x[poz-1]-x[poz-2])/(t[poz-1]-t[poz-2]);
				t[poz-1] = t[poz-2]+((odl-x[poz-2])/v);
				x[poz-1] = odl;
				if ((g*t[poz-1]*t[poz-1])/(long double)(2.0) >= odl) tim = t[poz-1];
					else tim = sqrtl(((long double)(2.0)*odl)/g);
				printf("%Lf\n",tim);
			}
		}
	}
	return 0;
}
