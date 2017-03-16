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
#define x first
#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

ll D[201][201];
int L[201][201];
int U[201][201];
ll Ca[101];
int Va[101];
ll Cb[101];
int Vb[101];

ll getMax(int i,int j,ll di,ll dj)
{
	if (i<0 || j<0) return 0;
	ll tmp=0;
	if (i>0 && j>0) tmp=D[i-1][j-1];
	if (di==dj) return di+1+tmp;
	if (di>dj)
	{
		return dj+1+max(tmp,getMax(i,L[i][j],di-dj-1,Cb[L[i][j]]-1));
	}
	return di+1+max(tmp,getMax(U[i][j],j,Ca[U[i][j]]-1,dj-di-1));
}

void test(int T)
{
	memset(D,0,sizeof(D));
	int n,m;
	cin>>n;
	cin>>m;
	rep(i,0,n)
		scanf("%lld%d",Ca+i,Va+i);
	
	rep(i,0,m)
		scanf("%lld%d",Cb+i,Vb+i);
	rep(i,0,n)
		rep(j,0,m)
			L[i][j]=U[i][j]=-1;
	rep(i,0,n)
		rep(j,0,m)
		{
			if (i!=0) 
			{
				if (Va[i-1]==Vb[j])
					U[i][j]=i-1;
				else
					U[i][j]=U[i-1][j];
			}
			if (j!=0)
			{
				if (Va[i]==Vb[j-1])
					L[i][j]=j-1;
				else
					L[i][j]=L[i][j-1];
			}
			if (Va[i]!=Vb[j])
			{
				if (i!=0) D[i][j]=D[i-1][j];
				if (j!=0) movmax(D[i][j],D[i][j-1]);
			}
			else
			{
				D[i][j]=getMax(i,j,Ca[i]-1,Cb[j]-1);
			}
		}
	printf("%lld\n",D[n-1][m-1]);
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

#define F_NAME "C-large"
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