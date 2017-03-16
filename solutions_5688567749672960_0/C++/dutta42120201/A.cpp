#include <cstdio>
#include <iostream>
using namespace std;
long long rev(long long n)
{
	long long r=0;
	while(n!=0)
	{
		r=r*10+n%10;
		n/=10;
	}
	return r;
}
int main()
{
	long long t,T,n,i,count;
	FILE * fr=fopen("A-small-attempt1.in","r");
	FILE * fw=fopen("A.out","w");
	fscanf(fr,"%lld",&t);
	T=t;
	while(t--)
	{
		fscanf(fr,"%lld",&n);
		
		fprintf(fw, "Case #%lld: %lld\n",(T-t),a[n]);
	}
	fclose(fr);
	fclose(fw);
}