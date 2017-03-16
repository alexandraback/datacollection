#include <iostream>
#include <cstdio>

using namespace std;

int E,R,N,v[10000];

long long solve()
{
	long long g = 0;
	long long i,j, e = E;
	for(i = 0; i < N; i++)
	{
		for(j = i+1; j < N; j++)
			if(v[i]<v[j])
				break;
		long long min = 0;
		if(j<N)
			min = E-R*(j-i);
		if(min<0)
			min = 0;
		if(e>min)
		{
			g += v[i]*(e-min);
			e = min;
		}
		e+=R;
//cout<<"now:"<<g<<' '<<e<<' '<<v[i]<<endl;
	}
	return g;
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
//		fgets(line,999,in);//empty line
		fscanf(in,"%d %d %d ",&E, &R, &N);
//cout<<E<<' '<<R<<' '<<N<<' '<<endl;
		for(i=0; i < N; i++)
			fscanf(in,"%d ",&v[i]);
		fprintf(out, "Case #%d: %lld\n",t,solve());
	}
	fclose(in);
	fclose(out);
}
