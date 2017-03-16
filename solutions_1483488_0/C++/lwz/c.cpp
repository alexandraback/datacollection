#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
int b[2000001],pow10[7]={1,10,100,1000,10000,100000,1000000},chtwo[7]={0,0,1,3,6,10,15};
int main()
{
	int a,s,c,c2,x,y,z,p,t2;
int N,T;
scanf("%d",&N);
for(T=1;T<=N;T++)
{
	scanf("%d%d",&x,&y);
	if( T>1 ) for(a=x;a<=y;a++) b[a]=0;
	c=0;
	for(a=x;a<=y;a++)
	{
		if( b[a]==1 ) continue;
//		c++;
		b[a]=1;
		z=a;
		t2=(int)log10((double)a);
		p=pow10[t2];
		c2=1;
		for(s=0;s<t2;s++)
		{
			if( z%10==0 ){ z=(z%10)*p+z/10; continue; }
			z=(z%10)*p+z/10;
			if( z<x || z>y ) continue;
			if( b[z]==1 ) break;
			b[z]=1;
//printf("%d %d\n",a,z);
			c2++;
		}
		c+=chtwo[c2];
	}
	printf("Case #%d: %d\n",T,c);
}
	return 0;
}
