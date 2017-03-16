#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
FILE *fin,*fout;
void initefile()
{
	fin = fopen("c:/googlejam/Asmall.txt","r");
	fout = fopen("c:/googlejam/Asmall_out.txt","w");
}
void outfile()
{
	fclose(fin);
	fclose(fout);
}

int f(int &n,int m)
{
	int i=0;
	while(n<=m)
	{
		n+=n-1;
		++i;
	}
	return i;
}

int main()
{
	initefile();
	int T;
	fscanf(fin,"%d",&T);
	for(int curt=1;curt<=T;++curt)
	{
		int A,N;
		int a[105]={0};
		fscanf(fin,"%d%d",&A,&N);
		int i,j;
		for(i=0;i<N;++i)fscanf(fin,"%d",&a[i]);
		vector<int>b;
		for(i=0;i<N;++i)b.push_back(a[i]);
		sort(b.begin(),b.end());
		for(i=0;i<N;++i)a[i]=b[i];

		if(A==1)
		{
			fprintf(fout,"Case #%d: %d\n",curt,N);
			continue;
		}
		int le[105]={0};
		int nc = 0;
		int tmpa=A;
		for(i=0;i<N;++i)
		{
			nc+=f(tmpa,a[i]);
			le[i]=nc;
			if(tmpa<=a[N-1])
				tmpa+=a[i];
		}
		int minop=le[N-1];
		for(j=N-1;j>=1;--j)
		{
			if(minop>(le[j-1]+N-j))
				minop=le[j-1]+N-j;
		}
		minop= minop>N?N:minop;
		fprintf(fout,"Case #%d: %d\n",curt,minop);
	}
	outfile();
	return 1;
}