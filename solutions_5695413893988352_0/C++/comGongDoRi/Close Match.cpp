#include <stdio.h>
#include <string.h>

FILE* in=fopen("B-small-attempt0.in","r");
FILE* out=fopen("out.txt","w");

int check(int n,char* S,int l)
{
	while(l--)
	{
		if(S[l]!='?' && S[l]-'0'!=n%10) return 0;
		n/=10;
	}
	return 1;
}

int abs(int n)
{
	return n>0?n:-n;
}

int len(int k)
{
	return k?len(k/10)+1:0;
}

void solve()
{
	int i,a,b,aa,bb;
	char A[4],B[4];
	fscanf(in,"%s %s",A,B);
	int diff=1000;
	int l1=strlen(A),l2=strlen(B);
	for(a=0;a<1000;a++) for(b=0;b<1000;b++)
	{
		if(check(a,A,l1) && check(b,B,l2) && abs(a-b)<diff)
		{
			diff=abs(a-b);
			aa=a;
			bb=b;
		}
	}
	l1-=len(aa);
	if(aa==0) l1--;
	for(i=0;i<l1;i++) fprintf(out,"0");
	fprintf(out,"%d",aa);
	
	fprintf(out," ");
	
	l2-=len(bb);
	if(bb==0) l2--;
	for(i=0;i<l2;i++) fprintf(out,"0");
	fprintf(out,"%d",bb);
	
	fprintf(out,"\n");
}

int main()
{
	int i,t;
	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++)
	{
		fprintf(out,"Case #%d: ",i);
		solve();
	}
	return 0;
}
