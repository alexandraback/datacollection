#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

unsigned long long c,r;

unsigned long long solve()
{
	unsigned long long min = 1, max = 1;
	unsigned long long val,n;
	for(n=1; 2*n*n+n*(2*r-1) < c; n*=2);
	max = n;
	while(min != max)
	{
		if(max == min+1)
		{
			n = max;
			val = 2*n*n+n*(2*r-1);
			if(val <= c)
				return max;
			else
				return min;
		}

		n = (min+max)/2;
		val = 2*n*n+n*(2*r-1);
		if(val == c)
			return n;

		if(val < c)
			min = n;

		if(val > c)
			max = n-1;
	}
	return min;
}

int main()
{
	FILE *in,*out;
//	char line[1000];
	int T, t;
	int i, j;
	in = fopen("A.in","r");
	out = fopen("A.out","w+");
//	fgets(line,999,in);
//	sscanf(line,"%d",&T);
	fscanf(in,"%d ",&T);
	for(t = 1; t <= T; t++)
	{
		fscanf(in,"%llu %llu ",&r, &c);
//		cout<<r<<' '<<c<<endl;
//		fgets(line,999,in);//empty line
		fprintf(out, "Case #%d: %llu\n",t,solve());
	}
	fclose(in);
	fclose(out);
}
