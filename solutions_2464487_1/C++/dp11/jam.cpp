#include"stdio.h"
#include"vector"
#include"set"
#include"map"
#include"assert.h"
#include"algorithm"
#include"math.h"
#include"stdlib.h"
#include"string.h"
#include"string"
using namespace std;
typedef unsigned int ui;
typedef long long int ll;
typedef unsigned long long int ull;
#define REP(i,n) for(unsigned int i=0;i<(n);i++)
#define LOOP(i,x,n) for(int i=(x);i<(n);i++)
#define ALL(v) v.begin(),v.end()
#define FOREACH(it,v)   for(typeof((v).begin()) it=(v).begin();it != (v).end();it++)
#define i(x) scanf("%d",&x)
#define u(x) scanf("%u",&x)
#define l(x) scanf("%lld",&x)
#define ul(x) scanf("%lld",&x)
int main()
{
	double sqr;
	int test;i(test);
	double r,t,x,y,z,m;
	for(int i=1;i<=test;i++)
	{
		printf("Case #%d: ",i);
		scanf("%lf%lf",&r,&t);
		x=r*2-1;
		x=x*x;
		y=t*8;
		x=x+y;
		z=sqrt(x);
		m=r*2-1;
		z=z-m;
		z=z/4;
		printf("%lld\n",(ll)z);
	}
	return 0;
}