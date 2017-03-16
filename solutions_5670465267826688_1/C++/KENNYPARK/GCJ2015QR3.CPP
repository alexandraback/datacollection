#include<fstream>
using namespace std;
FILE*fin=fopen("input.txt","r");
FILE*fout=fopen("output.txt","w");
int n,table[10][10]={{0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
char str[10010];
int mul(int a,int b)
{
	int sw=1;
	if(a<0)
	{
		a=-a;
		sw=-sw;
	}
	if(b<0)
	{
		b=-b;
		sw=-sw;
	}
	return sw*table[a][b];
}
int main()
{
	int i,x,whole,now,iend,out;
	__int64 j,k,y;
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;++i)
	{
		fscanf(fin,"%d%I64d%s",&x,&y,str);
		out=1;
		whole=1;
		for(j=1;j<=x;++j)whole=mul(whole,str[j-1]-'i'+2);
		now=1;
		for(j=1;j<=y;++j)
		{
			for(k=1;k<=x;++k)
			{
				now=mul(now,str[k-1]-'i'+2);
				if(now==2)
				{
					k++;
					if(k>x)k=1;
					goto startj;
				}
			}
			if(j>10)
			{
				out=0;
				goto end;
			}
		}
		iend=j;
startj:
		now=1;
		for(;j<=y;++j)
		{
			for(;k<=x;++k)
			{
				now=mul(now,str[k-1]-'i'+2);
				if(now==3)
				{
					k++;
					if(k>x)k=1;
					goto startk;
				}
			}
			k=1;
			if(j>iend+10)
			{
				out=0;
				goto end;
			}
		}
startk:
		now=1;
		for(;k<=x;++k)now=mul(now,str[k-1]-'i'+2);
		for(j++;j<=y;++j)
		{
			now=mul(now,whole);
			if(j%4==y%4)break;
		}
		if(now!=4)out=0;
end:
		fprintf(fout,"Case #%d: ",i);
		if(out)fprintf(fout,"YES\n");
		else fprintf(fout,"NO\n");
		fflush(fout);
	}
	//
	fcloseall();
	return 0;
}