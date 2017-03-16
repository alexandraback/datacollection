#include "tem.h"
#include "bignum.h"
#ifdef ProbA

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



typedef struct level
{
    int p1;
	int p2;
	int lvs;
}level;

level lv1[1111],lv2[1111],lvsorts[1111];
int lvstbegin,lvstend;

/*这个comparison函数很重要.如果希望升序排序,就是"<",降序排列就是">"号,这样便于直观记忆.如果希望用elem2作为比较标准
就把elem1改为elem2,这样结构体就以elem2为比较标准排序了.*/ 
bool cmp1(level a,level b){
	if(a.p1==b.p1)
		return a.p2>b.p2;
	else
		return a.p1<b.p1;
}
bool cmp3(level a,level b){
	return a.p2>b.p2;
}
bool cmp2(level a,level b){
    return a.p2<b.p2;
}
int lvstate[1111];
int n,stars;
int plv2,plv1;
int ans;


int main(void)
{
	int cc,tt,i;
	scanf("%d",&tt);
	for(cc=0;cc<tt;cc++){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d%d",&lv1[i].p1,&lv1[i].p2);
			lv2[i].p1=lv1[i].p1;
			lv2[i].p2=lv1[i].p2;
			lv2[i].lvs=lv1[i].lvs=i;
		}
		sort(lv1,lv1+n,cmp1);
		sort(lv2,lv2+n,cmp2);
		stars=0;
		plv2=plv1=0;
		ans=0;
		lvstbegin=lvstend=0;
		memset(lvstate,0,sizeof(lvstate));
		while(stars<2*n){
			while((lv1[plv1].p1<=stars)&&(plv1<n)){
				lvsorts[lvstend].p1=lv1[plv1].p1;
				lvsorts[lvstend].p2=lv1[plv1].p2;
				lvsorts[lvstend].lvs=lv1[plv1].lvs;
				plv1++;lvstend++;
			}
			if((lv2[plv2].p2<=stars)&&(plv2<n)){
				ans++;
				stars+=2-lvstate[lv2[plv2].lvs];
				lvstate[lv2[plv2].lvs]=2;
				plv2++;
			}else if(lvstend>lvstbegin){
				sort(lvsorts+lvstbegin,lvsorts+lvstend,cmp3);
				if(lvstate[lvsorts[lvstbegin].lvs]!=0){
					lvstbegin++;
					continue;
				}
				ans++;
				lvstate[lvsorts[lvstbegin].lvs]=1;
				lvstbegin++;
				stars++;
				/*if(lvstate[lv1[plv1].lvs]!=0){
					plv1++;
					continue;
				}
				ans++;
				stars+=1-lvstate[lv1[plv1].lvs];
				lvstate[lv1[plv1].lvs]=1;
				plv1++;*/
			}else
				break;
		}
		if(stars<2*n)
			printf("Case #%d: Too Bad\n",cc+1);
		else
			printf("Case #%d: %d\n",cc+1,ans);
	}
}

#endif