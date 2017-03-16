//This template is CopyRight By WenX(R), SEU, P.R.China
//wenxiao1992@gmail.com
//2010-5-24
#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable: 4996)

//SYS
#include <iostream>
#include <string>/////////
#include <cstring>////////This two
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
#include <cassert>
//ALG
#include <list>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <algorithm>
///Unknown
#include <cstddef>
#include <cassert>///?
#include <sstream>///?
#include <functional>
#include <numeric>
#include <utility>
#include <climits>
#include <numeric>

using namespace std;

#define fori(n)	 for(i=0;i<n;i++)
#define forj(n)  for(j=0;j<n;j++)
#define fork(n)  for(k=0;k<n;k++)
#define fori1(n) for(i=1;i<=n;i++)
#define forj1(n) for(j=1;j<=n;j++)
#define fork1(n) for(k=1;k<=n;k++)

typedef vector<int> vi;
typedef vector<string> vs;

#define pub(x) push_back(x)
#define puf(x) push_front(x)
#define pob(x) pop_back(x)
#define pof(x) pop_front(x)

const double pi=acos(-1.0);
const double eps=1e-9;
const long dx[]={1,0,-1,0};
const long dy[]={0,1,0,-1};
#define zero(f){f>0?(f<eps):(f>-eps)}//ONLY for float and double

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline int countbit(T n)
{return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
template<class T> inline T gcd(T a,T b)//NOTES:gcd(
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)//NOTES:lcm(
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline bool isPrimeNumber(T n)//NOTES:isPrimeNumber(
  {if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}

#define MAXN 10005
#define MAXVI 10005
int sortedv[MAXN];
int v[MAXN];
long long ein[MAXN];
long long eout[MAXN];
long long ans;

int main(void)
{
	int cc,tt;
	int e,r,n;
	int i,j,k;
	scanf("%ld",&tt);
	for(cc=0;cc<tt;cc++){
		scanf("%d%d%d",&e,&r,&n);
		ans=0;
		for(i=0;i<n;i++){
			scanf("%d",&v[i]);
			ein[i]=e;
			eout[i]=0;
		}
		memcpy(sortedv,v,sizeof(v));
		sort(sortedv,sortedv+n);
		
		for(i=n-1;i>=0;i--){
			if(i!=0&&sortedv[i]==sortedv[i-1])
				continue;
			for(j=0;j<n;j++){
				

				if(v[j]==sortedv[i]){
					ans+=(ein[j]-eout[j])*v[j];

					k=j+1;
					while((k<n)&&(ein[k]>eout[j]+r*(k-j))){
						ein[k]=eout[j]+r*(k-j);
						k++;
					}

					k=j-1;
					while((k>=0)&&(eout[k]<ein[j]-(j-k)*r)){
						eout[k]=ein[j]-(j-k)*r;
						k--;
					}
				}
			}
		}

		printf("Case #%d: ",cc+1);
		printf("%lld\n",ans);
	}
}
