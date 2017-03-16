#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int prime[168] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
int b[101];
int s[101];
int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
//	freopen("C-small-attempt0.in","r",stdin);
//	freopen("C-small-attempt0.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T>0)
	{
		T--;
		int n,j;
		scanf("%d%d",&n,&j);
		printf("Case #1: \n");
	/*	n=16;
		j=50;
		b[1]=1;
		b[16]=1;
		int i,ii,t;
		int k;
		while(b[1]==1)
		{
			bool flag1=true;
			int sx=0;
			for(ii=2;ii<=10;ii++)
			{
				for(t=1;t<=167;t++)
				{
					int p=1;
					int ss=0;
					for(i=16;i>=1;i--)
					{
						ss=(ss+p*b[i])%prime[t];
						p=p*ii%prime[t];
					}
					if(ss==0)
					{
						sx++;
						s[ii]=t;
						break;
					}
				}
				if(sx!=ii-1)
				{
					flag1=false;
					break;
				}
			}
			if(flag1)
			{
				for(i=1;i<=16;i++)
					printf("%d",b[i]);
				printf(" ");
				for(i=2;i<=9;i++)
					printf("%d ",prime[s[i]]);
				printf("%d\n",prime[s[i]]);
				j--;
				if(j==0)
					break;
			}
			k=15;
			while(b[k]==1)
			{
				b[k]=0;
				k--;
			}
			b[k]++;
		}*/
		n=32;
		j=500;
		b[1]=1;
		b[32]=1;
		int i,ii,t;
		int k;
		while(b[1]==1)
		{
			bool flag1=true;
			int sx=0;
			for(ii=2;ii<=10;ii++)
			{
				for(t=1;t<=167;t++)
				{
					int p=1;
					int ss=0;
					for(i=32;i>=1;i--)
					{
						ss=(ss+p*b[i])%prime[t];
						p=p*ii%prime[t];
					}
					if(ss==0)
					{
						sx++;
						s[ii]=t;
						break;
					}
				}
				if(sx!=ii-1)
				{
					flag1=false;
					break;
				}
			}
			if(flag1)
			{
				for(i=1;i<=32;i++)
					printf("%d",b[i]);
				printf(" ");
				for(i=2;i<=9;i++)
					printf("%d ",prime[s[i]]);
				printf("%d\n",prime[s[i]]);
				j--;
				if(j==0)
					break;
			}
			k=31;
			while(b[k]==1)
			{
				b[k]=0;
				k--;
			}
			b[k]++;
		}
	}
	return 0;
}
