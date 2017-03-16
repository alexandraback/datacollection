#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>

using namespace std;

long long N;

long long p(int k)
{
	long long ret =1;
	while(k--)
	{
		ret*=10;
	}
	return ret;
}

long long solve(long long n)
{
	long long tmp;
	int nDigits = 0;
	for(tmp=1;tmp<=n;tmp*=10)
	{
		nDigits++;
	}
cout<<n<<' '<<nDigits<<endl;
	if(nDigits==1)
		return n;
	long long ret = 1+solve(p(nDigits-1)-1);
	tmp = p(nDigits/2 + nDigits%2);
	if(!(n%tmp))
	{
		return 1+solve(n-1);
	}
	if(n==((n%tmp)+p(nDigits-1)))
	{
		return ret+(n%tmp);
	}
	ret+=(n%tmp);
	n/=tmp;
	tmp = 0;
	while(n)
	{
		tmp*=10;
		tmp+=(n%10);
		n/=10;
	}
	ret+=tmp;
	return ret;
}

int main()
{
	FILE *in,*out;
	char line[1000];
	int T, t;
	int i, j;
	in = fopen("A.in","r");
	out = fopen("A.out","w+");
//	fgets(line,999,in);
//	sscanf(line,"%d",&T);
	fscanf(in,"%d ",&T);
	for(t = 1; t <= T; t++)
	{
		fscanf(in,"%lld ",&N);
//		fgets(line,999,in);//empty line
		fprintf(out, "Case #%d: %lld\n",t, solve(N));
	}
	fclose(in);
	fclose(out);
}
