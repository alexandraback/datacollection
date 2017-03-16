#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;
long long gcd(long long p, long long q)
{
	if(p == 0)
		return q;
	return gcd(q % p, p);
}


int main(int argc, char *argv[]) {
	FILE *fin, *fout;
	fin = fopen("A-small-attempt0.in", "r");
	fout = fopen("elf.out", "w");
	
	int cases;
	long long p, q;
	long long limit = pow(2, 40);
	fscanf(fin, "%d", &cases);
	for(int cnt = 1; cnt <= cases; ++cnt)
	{
		fprintf(fout, "Case #%d: ", cnt);
		fscanf(fin, "%lld/%lld", &p, &q);
		
		while(gcd(p, q) > 1)
		{
			long long r = gcd(p, q);
			p /= r;
			q /= r;
		}
		long long tem = q;
		while(tem % 2 == 0)
			tem /= 2;
		if(tem != 1)
		{
			//printf("here\n");
			fprintf(fout, "impossible\n");
			continue;
		}
		//printf("%lld %lld\n", p, q);
		double res = (double)p / q;
		double t;
		int i;
		for(i = 1; i <= 40; ++i)
		{
			t = pow(2, i);
			t = 1 / t;
			//printf("%lf, %lf\n", res, t);
			if(res >= t)
			{
				fprintf(fout, "%d\n", i);
				//fout << i << endl;
				break;
			}
		}
		if(i == 41)
		{
			fprintf(fout, "impossible\n");
		}
		
	}
}