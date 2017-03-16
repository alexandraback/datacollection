#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
#define llu long long unsigned
#define ld long
#define F first
#define S second
#define ll long long
using namespace std;
#define si(x) scanf("%d",&x)
#define sdb(x) scanf("%lf",&x)
#define sll(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define pi(x) printf("%d", x);
char pattern[1000],input[1000],lps[1000];

void prefixfunc()
{
	int i,j=0;
	int len=strlen(pattern);
	lps[0]=0;
	for(i=1;i<len;i++)
	{
		if(pattern[i]==pattern[j])
		{
			j++;
			lps[i]=j;
		}
		else if(j!=0)
		{
			j=lps[j-1];
			i--;
		}
		else
		{
			lps[i]=0;
		}
	}
}
int kmp()
{
	int i=0,j=0,N=strlen(input),M=strlen(pattern),ans=0;
	
    while(i<N)
    {
      if(pattern[j]==input[i])
      {
       	 j++;
         i++;
      }
      if(j==M)
      {
      	ans++;
        j=lps[j-1];
      }
      else if(i<N&&pattern[j]!=input[i])
      {
        if(j!=0)
        	j=lps[j-1];
        else
         	i++;
      }
    }
    return ans;
}
int mark[30],counter[30],co=1;
char index1[30];
char str1[30];
int main()
{
	int t;
	si(t);
	while(t--)
	{
		int size=0,temp,i,j,k,l,s,repet=0,temp2;
		double maxx;
		double ans=0;
		si(k);si(l);si(s);
		scanf("%s",str1);
		scanf("%s",pattern);
		prefixfunc();
		for(i=0;i<k;i++)
		{
			if(mark[str1[i]-65]==0) index1[size++]=str1[i];
			mark[str1[i]-65]==1;
		}
		maxx=pow(size,s);
		for(i=0;i<maxx;i++)
		{
			temp=i;
			for(j=0;j<s;j++)
			{
				input[s-1-j]=index1[temp%size];
				temp=temp/size;
			}
			input[s]='\0';
			temp2=kmp();
			repet=max(repet,temp2);
			counter[temp2]++;
		}
		for(i=0;i<=s;i++)
		{
			ans=ans+counter[i]*(repet-i);
		}
		printf("Case #%d: ", co++);
		printf("%0.8lf\n",(double)ans/maxx);
		for(i=0;i<30;i++)
		{
			mark[i]=0;
			counter[i]=0;
		} 
	}

	
}

