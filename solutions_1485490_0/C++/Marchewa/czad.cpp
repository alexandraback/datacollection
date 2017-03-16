#include<cstdio>
#include<algorithm>
#include<vector>
#define PB push_back
#define PII pair<unsigned long long,int>
#define ND second
#define ST first
#define MAXN 101
using namespace std;

int n, m, b;
unsigned long long a;
vector<PII> vn,vm;

unsigned long long napierdalaj(int i, int j, unsigned long long ival, unsigned long long jval, unsigned long long wyn)
{
	unsigned long long x = 0;
	if(i > n-1 || j > m-1)return wyn;
	if(vn[i].ND == vm[j].ND)
	{
//		printf("%d %d\n", vn[i].ND, vm[j].ND);
		if(vn[i].ST-ival == vm[j].ST-jval)
		{
			x = vn[i].ST-ival;
			wyn += x;
//			printf(">%d %d %d %d %llu\n", i, j, ival, jval, wyn);
			return max(napierdalaj(i+1, j, 0, jval+x, wyn), napierdalaj(i, j+1, ival+x,0, wyn));
		}
		else if(vn[i].ST-ival > vm[j].ST-jval)
		{
			x = vm[j].ST-jval;
			wyn += x;
//			printf("->%d %d %d %d %llu\n", i, j, ival, jval, wyn);
			return napierdalaj(i, j+1, ival+x, 0, wyn);
		}
		else if(vn[i].ST-ival < vm[j].ST-jval)
		{
			x = vn[i].ST-ival;
			wyn += x;
//			printf("-->%d %d %d %d %llu\n", i, j, ival, jval, wyn);
			return napierdalaj(i+1, j, 0, jval+x, wyn);
		}
	}
	else
	{
//		printf("--->%d %d %d %d %llu\n", i, j, ival, jval, wyn);
		unsigned long long asdf = napierdalaj(i+1, j, 0, jval, wyn);
		unsigned long long fdsa = napierdalaj(i, j+1, ival, 0, wyn);
		return max(asdf, fdsa);
	}
}


void solve(int num)
{
	vm.clear();
	vn.clear();
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%llu%d", &a, &b);
		vn.PB(PII(a, b));
	}
	for(int j = 0; j < m; j++)
	{
		scanf("%llu%d", &a, &b);
		vm.PB(PII(a, b));
	}
	printf("Case #%d: %llu\n", num, napierdalaj(0,0,0,0,0));
}



int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)solve(i+1);
}
