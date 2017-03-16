#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int N,X,Y;

unsigned long long c(int n, int k)
{
	if(k==0 || n<=k)
		return 1;
	static unsigned long long C[1100][1100];
	static bool first = true;
	if(first)
	{
		int i,j;
		first = false;
		for(i=0;i<1100;i++)
			for(j=0;j<1100;j++)
				C[i][j] = 0;
	}
	if(!C[n][k])
		C[n][k] = c(n-1,k)+c(n-1,k-1);
//cout<<n<<' '<<k<<' '<<C[n][k];
	return C[n][k];
}

double solve()
{
	if((X+Y)%2)
		return 0;
	if(X<0)
		X = -X;
	int k;
	for(k=0; N>=(4*k+1);k++)
		N-=(4*k+1);
	k*=2;
	if(X+Y<k)
		return 1;
	if(X+Y>k)
		return 0;
	if(X==0)
		return 0;
	if((X+Y+Y)<N)
		return 1;
	if(Y>=N)
		return 0;
	unsigned long long sum = 0;
	int i=N-2*k;
	if(i<0)
		i = 0;
	for(;i<=Y;i++)
		sum+=c(N,i);
	double p = (((double)sum)/(1<<N));
	return 1-p;
}

int main()
{
	FILE *in,*out;
//	char line[1000];
	int T, t;
	int i, j;
	in = fopen("B.in","r");
	out = fopen("B.out","w+");
//	fgets(line,999,in);
//	sscanf(line,"%d",&T);
	fscanf(in,"%d ",&T);
	for(t = 1; t <= T; t++)
	{
		fscanf(in,"%d %d %d ", &N, &X, &Y);
//		fgets(line,999,in);//empty line
		fprintf(out, "Case #%d: %7f\n",t,solve());
	}
	fclose(in);
	fclose(out);
}
