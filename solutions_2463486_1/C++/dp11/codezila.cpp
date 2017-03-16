/*
G-->    1        2         2         3            3           4          ........................................
	   (1)     (2,3)     (4,5)    (6,7,8)     (9,10,11)   (12,13,14,15)  .....................................
Appers  1        2         3         4            5             6 ...........................
Matlb 1 appear 1 times
Matlb (2,3) appear 2 times and cardinality of set is G[2]=2
Matlb (4,5) appear 3 times and cardinality of set is G[3]=2
Matlb (6,7,8) appear 4 times and cardinality of set is G[4]=3
Matlb (9,10,11) appear 5 times and cardinality of set is G[5]=3
Matlb (12,13,14,15) appear 6 times and cardinality of set is G[6]=4
*/
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
typedef unsigned long long ull;
#define REP(i,n) for(unsigned int i=0;i<(n);i++)
#define LOOP(i,x,n) for(int i=(x);i<(n);i++)
#define ALL(v) v.begin(),v.end()
#define FOREACH(it,v)   for(typeof((v).begin()) it=(v).begin();(it) != (v).end();it++)
#define i(x) scanf("%d",&x)
#define u(x) scanf("%u",&x)
#define l(x) scanf("%lld",&x)
#define ul(x) scanf("%Lu",&x)
ll S[41]={0,1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004,100000020000001};
int bs22(int low,int high,ll k)//returns the index of that number which is equal to or just smaller than it
{
	int mid=(low+high)/2;
	//printf("%d bs22 ",mid);
	if(S[high]<k || S[high]==k)
		return high;
	else if(S[mid]==k)
		return mid;
	else if((S[mid]<k) && S[mid+1]>k)
		return mid;
	else if(S[mid]<k)
		return bs22(mid+1,high,k);
	else
		return bs22(low,mid-1,k);
}
int main()
{
	int test;
	ll A,B,ans;
	scanf("%d",&test);
	for(int i=0;i<test;i++)
	{
		scanf("%lld%lld",&A,&B);
		ans=bs22(0,40,B)-bs22(0,40,A-1);
		printf("Case #%d: %lld\n",i+1,ans);
	}
	return 0;
}