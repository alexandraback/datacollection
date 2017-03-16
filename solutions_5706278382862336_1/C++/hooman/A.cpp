#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>

long long P,Q;

using namespace std;

long long dd(long long p, long long q)
{
	if(p<q)
	{
		long long tmp = p;
		p = q;
		q = tmp;
	}
	if(p%q)
		return dd(q,p%q);
	return q;
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
		fscanf(in,"%lld/%lld ",&P, &Q);
		long long tmp = dd(P,Q);
		P/=tmp;
		Q/=tmp;
		if(((long long)1<<40)%Q)
			fprintf(out, "Case #%d: impossible\n", t);
		else
		{
			tmp = ((long long)1<<40)/Q;
			tmp*=P;
			for(i=0;tmp;i++,tmp>>=1);
			fprintf(out, "Case #%d: %d\n", t, 40-i+1);
		}
	}
	fclose(in);
	fclose(out);
}
