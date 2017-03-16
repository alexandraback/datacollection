#pragma warning(disable:4786)
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<set>
#include<stdlib.h>
#include<sstream>
#include<functional>
#include<queue>
#include<stack>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define ABS(A) ((A)>0?(A):(-(A)))
#define S(X) ((X)*(X))

typedef pair<int,int> PII;

//int dr[]={-1,0,1,0};
//int dc[]={0,1,0,-1};
//int dr[]={-2,-2,-1,1,2,2,1,-1};
//int dc[]={-1,1,2,2,1,-1,-2,-2};

typedef __int64 LL;
#define I64d "%I64d"
double P[100002];
double p[100002];
double sum[100002];
double mistake[100002];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);	freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);	freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-large.in","r",stdin);			freopen("A-large.out","w",stdout);

	int T, ks;
	double ans,s,P0,P1,x;
	int i, j;
	int A, B;

	scanf("%d",&T);
	for(ks=1;ks<=T;ks++)
	{

		scanf("%d%d",&A,&B);
		for(i=1;i<=A;i++)
			scanf("%lf",&p[i]);

		P0 = P1 = 0;
		
		s = 1;
		sum[0] = 0;
		for(i=1;i<=A;i++)
		{
			mistake[i] = s*(1-p[i]);
			s*=p[i];
			sum[i] = sum[i-1] + mistake[i];
		}

		ans=B+2;

		for(i=1;i<=A;i++)
		{
			P0 += mistake[i]*(B-A+1+B+1);
			P1 += mistake[i]*(1+B+1);

			x = sum[A-i]*(i+i+B-A+1+B+1) + (1-sum[A-i])*(i+i+B-A+1);
			ans = MIN(ans, x);
//			printf("%lf\n",x);
		}
	
		P0+=s*(B-A+1);
		P1 += s*(1+B+1);

		ans = MIN(ans, MIN(P0, P1));

//		printf("%lf %lf\n",P0,P1);

//		ans = MIN(P0, P1);
//		ans = MIN(ans, P[1]);

		printf("Case #%d: %.9lf\n",ks,ans);
		
	}

	return 0;
}