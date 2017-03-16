#include<stdio.h>
#include<string.h>
#include<vector.h>
FILE *in,*out;
long long i[1024];
int b[3000000];
vector<long long> h[1048576];
vector<int> hv[1048576];
int main()
{
	in =fopen("c.in" ,"r");
	out=fopen("c.out","w");
	int tests,test;
	int n,v;
	long long x;
	int y;
	int a,s,d,f,j,k,l;
	fscanf(in,"%d",&tests);
	for(test=0;test<tests;test++)
	{
		fprintf(out,"Case #%d:\n",test+1);
		fscanf(in,"%d",&n);
		for(a=0;a<n;a++) fscanf(in,"%I64d",&i[a]);
		for(a=0;a<1048576;a++) h[a].clear();
		v=-1;
		for(a=0;a<n;a++) for(s=a+1;s<n;s++) for(d=s+1;d<n;d++)
		{
			x=i[a]+i[s]+i[d];
			y=x%1048573;
			for(f=0;f<h[y].size();f++) if( h[y][f]==x ) break;
			if( f<h[y].size() )
			{
				v=hv[y][f];
				goto skip;
			}
			h[y].push_back(x);
			hv[y].push_back(a*1000000+s*1000+d);
		}
		skip:;
		if( v==-1 ) fprintf(out,"Impossible\n");
		else
		{
			j=v%1000; v/=1000;
			k=v%1000; v/=1000;
			l=v%1000; v/=1000;
			if( a==j ) { fprintf(out,"%I64d %I64d\n%I64d %I64d\n",i[s],i[d],i[k],i[l]); continue; }
			if( a==k ) { fprintf(out,"%I64d %I64d\n%I64d %I64d\n",i[s],i[d],i[l],i[j]); continue; }
			if( a==l ) { fprintf(out,"%I64d %I64d\n%I64d %I64d\n",i[s],i[d],i[j],i[k]); continue; }
			if( s==j ) { fprintf(out,"%I64d %I64d\n%I64d %I64d\n",i[d],i[a],i[k],i[l]); continue; }
			if( s==k ) { fprintf(out,"%I64d %I64d\n%I64d %I64d\n",i[d],i[a],i[l],i[j]); continue; }
			if( s==l ) { fprintf(out,"%I64d %I64d\n%I64d %I64d\n",i[d],i[a],i[j],i[k]); continue; }
			if( d==j ) { fprintf(out,"%I64d %I64d\n%I64d %I64d\n",i[a],i[s],i[k],i[l]); continue; }
			if( d==k ) { fprintf(out,"%I64d %I64d\n%I64d %I64d\n",i[a],i[s],i[l],i[j]); continue; }
			if( d==l ) { fprintf(out,"%I64d %I64d\n%I64d %I64d\n",i[a],i[s],i[j],i[k]); continue; }
			fprintf(out,"%I64d %I64d %I64d\n%I64d %I64d %I64d\n",i[a],i[s],i[d],i[j],i[k],i[l]);
		}
	}
	return 0;
}