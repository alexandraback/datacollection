#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int main() 
{
	FILE *fin1 = fopen("point.in","r+");
	FILE *fin2 = fopen("point.out","w+");

	unsigned long long int M[]={1,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296,8589934592,17179869184,34359738368,68719476736,137438953472,274877906944,549755813888,1099511627776,2199023255552,4398046511104,8796093022208,17592186044416,35184372088832,70368744177664,140737488355328,281474976710656,281474976710656*2};

	int t=0;
	fscanf(fin1, "%d",&t);
	int u=1;
	while(t-->0)
	{
		int b=0;
		unsigned long long int m=0;
		fscanf(fin1, "%d%lld",&b,&m);

		if(M[b-1]>=m)
		{
			fprintf(fin2,"Case #%d: POSSIBLE\n", u);u++;
		}
		else
		{
			fprintf(fin2,"Case #%d: IMPOSSIBLE\n", u);u++;
			continue;
		}

		char** ch=new char *[b];

		ch[0] = new char [b];
		for(int j=0;j<b;j++)
		{
			ch[0][j]='0';
		}

		for(int i=1;i<b-1;i++)
		{
			ch[i] = new char [b];
			ch[i][0]='0';
			for(int j=1;j<i;j++)
			{
				ch[i][j]='1';
			}

			for(int j=i;j<b;j++)
			{
				ch[i][j]='0';
			}

			ch[i][b-1]='1';
		}

		int end=b-1;
		ch[end] = new char [b];
		for(int j=0;j<b;j++)
		{
			ch[end][j]='0';
		}

		for(int i=b-2;i>0;i--)
		{
			if(M[i]<=m)
			{
				m-=M[i];
				ch[0][i]='1';
			}
		}

		if(0<m)
		{
			ch[0][b-1]='1';
		}
		

		for(int i=0;i<b;i++)
		{
			for(int j=0;j<b;j++)
			{
				fprintf(fin2,"%c", ch[i][j]);
			}
			fprintf(fin2,"\n");
		}
	}
	return 0;
}