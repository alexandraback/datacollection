#include<fstream>
using namespace std;
#include<stdio.h>
#include<string.h>
FILE*fin=fopen("input.txt","r");
FILE*fout=fopen("output.txt","w");
int n;
__int64 base[20]={1,10},pow10[20]={1};
char str[20],num[20];
int main()
{
	int i,j,len,t,flag;
	__int64 x,y,out;
	for(i=1;i<=14;++i)pow10[i]=pow10[i-1]*10;
	for(i=2;i<=14;++i)base[i]=pow10[i/2]-1+pow10[(i+1)/2]-1+base[i-1]+1;
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;++i)
	{
		fscanf(fin,"%s",str+1);
		len=strlen(str+1);
		if(len==1)sscanf(str+1,"%I64d",&out);
		else
		{
			sscanf(str+1,"%I64d",&x);
			flag=0;
			for(j=1;j<=14;++j)if(x==pow10[j])flag=1;
			if(str[len]!='0'||flag)
			{
				t=0;
				for(j=len/2;j>=1;--j)num[t++]=str[j];
				num[t]=0;
				sscanf(num,"%I64d",&x);
				sscanf(str+len/2+1,"%I64d",&y);
				out=x+y+base[len-1];
				if(x==1)out--;
			}
			else
			{
				sscanf(str+1,"%I64d",&x);
				sprintf(str+1,"%I64d",x-1);
				t=0;
				for(j=len/2;j>=1;--j)num[t++]=str[j];
				num[t]=0;
				sscanf(num,"%I64d",&x);
				sscanf(str+len/2+1,"%I64d",&y);
				out=x+y+base[len-1]+1;
				if(x==1)out--;
			}
		}
		fprintf(fout,"Case #%d: %I64d\n",i,out);
	}
	return 0;
}