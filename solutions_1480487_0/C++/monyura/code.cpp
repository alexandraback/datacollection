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

int B[201];
int A[201];
int n;

void test(int T)
{
	scanf("%d",&n);
	int zcnt=0;
	int s=0;
	rep(i,0,n)
	{
		scanf("%d",A+i);
		if (!A[i]) zcnt++;
		s+=A[i];
	}
	printf("Case #%d:",T);
	rep(i,0,n)
	{
		double l=0,r=1.00;
		double c=(l+r)/2.0;
		while (l<c && c<r)
		{
			double left=1-c;
			double need=A[i]+s*c;
			rep(j,0,n)
				if (i!=j)
					left-=max(0.0,(need-A[j])/s);
			if (left>0) l=c;
			else r=c;
			c=(l+r)/2.0;
		}
		printf(" %.12lf",l*100);
	}
	puts("");
}

void run()
{
	int t;
	cin>>t;
	rep(i,0,t)
		test(i+1);
}

#define F_NAME "A-small-attempt2"
const bool b_test=false;
int main()
{
	if (b_test)
	{
		freopen("test.in","r",stdin);
		freopen("test.out","w",stdout);
	}
	else
	{
		freopen(F_NAME".in","r",stdin);
		freopen(F_NAME".out","w",stdout);
	}
	time_t beg=clock();
	run();
	fprintf(stderr,"Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
	return 0;
}

/*

*/