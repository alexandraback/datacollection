#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <limits.h>
#define PI 3.14159265358979323846264338327950288419716939937510
#define MIN(i,j) (i<j?i:j)
#define MIN3(i,j,k) (i<j?MIN(i,k):MIN(j,k))
#define MAX(i,j) (i>j?i:j)
#define MAX3(i,j,k) (i>j?MAX(i,k):MAX(j,k))
#define REP(x) for(int i=0;i<x;i++)
using namespace std;
inline double comb(int n, int k);

#define AMAX 100005
void solve_problem()
{
	int n, i, j,a,b;
	double ans, ktype, kbsp;
	double P[AMAX], TP[AMAX];
	scanf("%d %d",&a,&b);
	ans = b+2;
	REP(a) scanf("%lf", &P[i]);
	TP[0] = P[0];
	REP(a-1) TP[i+1] = P[i+1] * TP[i];
	ktype = (b-a+1)*TP[a-1] + (b-a+2+b)*(1-TP[a-1]);
	if (ktype < ans) ans = ktype;
	for(int i = 1;i<a;i++) 
	{
		kbsp = (i+b-a+i+1)*TP[a-i-1] + (i+i+b-a+2+b)*(1-TP[a-i-1]);
		if (kbsp < ans) ans = kbsp;
	}
	printf("%.6lf\n", ans);
}

int main(void)
{
	int ct, tc;
	scanf("%d",&tc);	
	for(ct=1;ct<=tc;ct++)			
	{
		printf("Case #%d: ", ct);	
		solve_problem();
	}
	return 0;
}

inline double comb(int n, int k)
{
	int nk = n-k, i, j; double num = 1.0, den = 1.0;
	if(k==0) return 1; if(n==0&&k!=0) return 0;
	for(i=n;i>nk;i--) num*=i;
	for(j=2;j<=k;j++) den*=j;
	return num/den;
}
