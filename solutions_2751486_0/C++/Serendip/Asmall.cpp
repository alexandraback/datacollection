#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include <set>
#include <vector>
#include <algorithm>
#include<string.h>
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
bool dp[1000005];
char str[1000005];
int main()
{
	initefile();
	int T;
	fscanf(fin,"%d",&T);
	for(int curt=1;curt<=T;++curt)
	{
		int n;
		fscanf(fin,"%s%d",str,&n);
		int i,j,k;
		for(i=0;i<strlen(str);++i)
		{
			char tmpc = str[i];
			if(tmpc!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u')
			{
				dp[i]=true;
			}
			else 
			{
				dp[i]=false;
			}
		}
		__int64 sum=0,curdp = 0,cur1=0,dpre =0;
		for(i=0;i<n;++i)
		{
			if(dp[i])
			{
				++cur1;
			}
			else
				cur1=0;
		}
		if(cur1==n)
			++sum,dpre++;
		for(;i<strlen(str);++i)
		{
			if(dp[i])
			{
				++cur1;
				if(cur1>=n)
				{
					dpre = i-n+2;
					sum=sum+dpre;
					
				}
				else
				{
					sum+=dpre;
				}
			}
			else
			{
				sum+=dpre;
				cur1=0;
			}
		}
		fprintf(fout,"Case #%d: %I64d\n",curt,sum);
	}
	outfile();
	return 1;
}