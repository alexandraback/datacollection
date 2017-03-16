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
ll array[10000],comb[1001][1001],h;
int index[10000];
void constant()
{
	array[0]=0;
	int i,j;
	for(i=1,j=1;i<10000;i+=2,j++)
	{	
		array[j]=((ll)i*((ll)i+1))/2;
		index[j]=i;
	}
	//printf("%d is j\n",j);
	for(int i=0;i<1001;i++)
		comb[i][i]=1,comb[i][0]=1;
	
}
int bs22(int low,int high,int k)//returns the index of that number which is equal to or just smaller than it
{
	int mid=(low+high)/2;
	//printf("%d bs22 ",mid);
	if(array[high]<k || array[high]==k)
		return high;
	else if(array[mid]==k)
		return mid;
	else if((array[mid]<k) && array[mid+1]>k)
		return mid;
	else if(array[mid]<k)
		return bs22(mid+1,high,k);
	else
		return bs22(low,mid-1,k);
}
int main()
{
	int test,n,x,y,ind,height;
	double p,val,cons=1/(double)2,res;
	scanf("%d",&test);
	constant();
	for(int i=1;i<=test;i++)
	{
		scanf("%d%d%d",&n,&x,&y);
		if(y<0)
		{
			printf("Case #%d: 0\n",i);
			continue;
		}
		ind=bs22(0,4000,n);
		//printf("%d is ind\n",ind);
		if(y-x-index[ind]<0 && x+y-index[ind]<0)
		{
			printf("Case #%d: 1\n",i);
			continue;
		}
		else if(!(y-x-index[ind+1]<0 && x+y-index[ind+1]<0))
		{
			printf("Case #%d: 0\n",i);
			continue;
		}
		else
		{
			p=1;
			val=0;
			height=y+1;
			n=n-array[ind];
			if(n-height<0 || height>index[ind+1])
				printf("Case #%d: 0\n",i);
			else
			{
				for(int j=0;j<height;j++)
					p=p*cons;
				res=p;
				val=p;
				for(int j=1;j<=n-height;j++)
				{
					res=(res*cons*(height+j-1))/(double)j;
					val=val+res;
				}	
				printf("Case #%d: %.8lf\n",i,val);
			}
		}
	}
	return 0;
}