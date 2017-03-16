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


void test()
{
	int sz,n;
	cin>>sz>>n;
	int A[101];
	rep(i,0,n)
		scanf("%d",A+i);
	sort(A,A+n);
	int res = n;
	int done = 0;
	if (sz>1)
	{
		rep(i,0,n)
		{
			res=min(res,done + n - i);
			while (sz<=A[i])
			{
				sz+=sz-1;
				++done;
			}
			sz+=A[i];
			if (sz<0) cerr<<"fail"<<endl;
		}
		res=min(res,done);
	}
	printf("%d\n",res);
}

void run()
{
	int t;
	cin>>t;
	rep(i,0,t)
	{
		printf("Case #%d: ",i+1);
		test();
	}
}

#define problem "A-large"

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