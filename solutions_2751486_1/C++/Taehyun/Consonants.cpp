#include<stdio.h>
#include<string.h>
FILE*in=fopen("input.txt","r");
FILE*out=fopen("output.txt","w");
int T;
int t;
int N;
int M;
char A[2000001];
int S[2000001];
bool Vowel[300];
long long Ans;
int main()
{
	fscanf(in,"%d",&T);
	int i,last;
	Vowel['a']=Vowel['e']=Vowel['i']=Vowel['o']=Vowel['u']=1;
	for(t=1;t<=T;t++)
	{
		Ans=0;
		fscanf(in,"%s %d",&A[1],&M);
		N=strlen(&A[1]);
		for(i=1;i<=N;i++)
		{
			if(Vowel[A[i]]) S[i]=0;
			else S[i]=S[i-1]+1;
		}
		last=0;
		for(i=1;i<=N;i++)
		{
			if(S[i]==M)
			{
				if(last==0) Ans+=(long long)(i-M+1)*(long long)(N-i+1);
				else Ans+=(long long)(i-M+1-last)*(long long)(N-i+1);
				last=i-M+1;
			}
			else if(S[i]>M)
			{
				Ans+=(long long)(N-i+1);
				last=i-M+1;
			}
		}
		fprintf(out,"Case #%d: %lld\n",t,Ans);
	}
}