#include<cstdio>
#include<algorithm>
using namespace std;
int i[1000],b[1000];
double o[1000];
bool cmp1(int x,int y){ return i[x]<i[y]?true:false; }
int main()
{
int T,N;
scanf("%d",&N);
for(T=1;T<=N;T++)
{
	int a,n,rr,r,brk,p,x;
	double t,t2;
	scanf("%d",&n);
	rr=0;
	for(a=0;a<n;a++){ scanf("%d",&i[a]); rr+=i[a]; b[a]=a; }
	sort(b,b+n,cmp1);
	r=0;
	p=0;
	for(a=0;a<n;a++)
	{
		x=b[a];
		r+=i[x];
		t=((double)r+(double)rr)/((double)a+1.);
		brk=0;
		if( t<(double)i[x] )
		{
			t2=i[x];
			brk=1;
		}
		else if( a==n-1 || t<=(double)i[b[a+1]] )
		{
			t2=t;
			brk=1;
		}
		if( brk )
		{
			while( p<=a ){ o[b[p]]=(t2-(double)i[b[p]])/(double)rr; p++; }
			continue;
		}
	}
	printf("Case #%d:",T);
	for(a=0;a<n;a++) printf(" %lf",o[a]*100.);
	printf("\n");
}
	return 0;
}
