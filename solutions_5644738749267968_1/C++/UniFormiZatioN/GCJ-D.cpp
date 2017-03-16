#include<stdio.h>
#include<algorithm>
#define FOR(ReprI,ReprS,ReprN) for(ReprI=ReprS;ReprI<ReprN;ReprI++)
#define scan(ReprN) scanf("%d",&ReprN)
#define scanLL(ReprN) scanf("%I64d",&ReprN)

#define MAX 3000
double A[MAX],B[MAX];

int main()
{
	freopen("D-large.in","r",stdin);
	freopen("D-large_out.txt","w",stdout);
	int Test,Case,i,j,a,b;
	int N,y;
	scanf("%d",&Test);
	for(Case=1;Case<=Test;Case++)
	{
		scan(N);
		FOR(i,0,N) scanf("%lf",A+i);
		FOR(i,0,N) scanf("%lf",B+i);
		std::sort(A,A+N);
		std::sort(B,B+N);
		y=0, a=0, b=N-1;
		for(i=0;i<N;i++)
			if(A[i]<B[a]) b--;
			else{ a++, y++; }
		for(i=a=0;i<N && a<N;i++,a++)
			while(a<N && B[a]<A[i]) a++;
		
		printf("Case #%d: %d %d\n",Case,y,N-i+(a>N));
	}

	return 0;
}
