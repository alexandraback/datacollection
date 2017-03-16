//#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
//#endif

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double PI = acos(-1.0);

double F[1000100]={0};
void test()
{
	int n,x,y;
	cin>>n>>x>>y;
	int curr = 1,s = 0;
	int cnt = -2;
	while (s+curr<=n)
	{
		cnt+=2;
		s+=curr;
		curr+=4;
	}
	if (abs(x)+abs(y)<=cnt)
	{
		puts("1.0");
		return;
	}
	if (abs(x)+abs(y)>cnt+2 || x==0)
	{
		puts("0.0");
		return;
	}
	int left = n - s;
	int need = y+1;
	int half = (curr-1)/2;
	double sum = 0;
	rep(i,0,left+1)
	{
		bool needAdd = left-i>half && left-half>=need || left-i<=half && i>=need;
		double curr = F[left]-F[i]-F[left-i]-left*F[2];
		if (needAdd)
			sum+=exp(curr);
	}
	printf("%.10lf\n",sum);
}

void run()
{
	rep(i,1,1000100)
		F[i]=F[i-1]+log(double(i));
	int t;
	cin>>t;
	rep(i,0,t)
	{
		printf("Case #%d: ",i+1);
		test();
		cerr<<i<<" done\n";
	}
}

#define problem "B-large"

int main()
{
#ifndef problem
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#else
	freopen(problem".in","r",stdin);
	freopen(problem".out","w",stdout);
#endif
	time_t st=clock();
	run();
#ifndef problem
	fprintf(stderr, "=============\n");
	fprintf(stderr,"Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
} 