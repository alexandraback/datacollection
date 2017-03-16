/*
                                                     _     
                       o                            | |    
_|_       __,   _  _       __   ,_    __,   __, _|_ | |    
 |  |  |_/  |  / |/ |  |  /    /  |  /  |  /  |  |  |/ \   
 |_/ \/  \_/|_/  |  |_/|_/\___/   |_/\_/|_/\_/|_/|_/|   |_/
                                                           
                                                           
*/
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define mfor(i,e)	for(int i = 0; i < e; i++)
#define mford(i,s,e)	for(int i = s; i > e; i--)
//#define FORE(i,s,e)	for(typeof(s) i = s; i != e; ++i)
#define mfori(i,s,e)	for(int i = s; i < e; i++)
#define in(x)		(x = getc(stdin))
#define MP			make_pair
#define out(x)		putc(x, stdout)
#define pb			push_back

template <class _T> _T MAX(_T a, _T b){ return a > b ? a : b; }
template <class _T> _T MIN(_T a, _T b){ return a < b ? a : b; }
template <class _T> _T GCD(_T a, _T b){ return b ? gcd(b, a % b) : a; }


ll sq (ll n)	{
ll i;
for(i=1;1;i++)
{
if((i+1)*(i+1) > n) return i;
}
}

int main(void){
	ll tt,test;
	ll r,t,n,a,b,c,i,j,d;
	 scanf("%lld",&test);
	for(tt=0;tt<test;tt++)	{
	scanf("%lld %lld",&r,&t);
	//a=(8*r)+1;
	//b=(4*r*r)+(14*r)+3;
	//c=-2*t;
a=2;
b=2*r-1;
c=-t;
d=(b*b)-(4*a*c);
d=sq(d);
d=-b+d;
d=d/(2*a);
printf("Case #%lld: %lld\n",tt+1,d);
}
//	printf("%lld +- root%lld by %lld\n",-b,d,2*a);
	return 0;
}
