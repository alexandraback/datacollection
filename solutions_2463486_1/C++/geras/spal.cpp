// Author: Kamil Niziński
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define debug(fmt,...) //fprintf(stderr,fmt, ## __VA_ARGS__)
#define mp make_pair
#define ft first
#define sd second
#define psb push_back
using namespace std;
typedef long long int ll;
typedef long long unsigned llu;
typedef double dd;
typedef pair < int, int > pii;
ll P[]={
	1ll,4ll,9ll,121ll,484ll,10201ll,12321ll,14641ll,40804ll,44944ll,1002001ll,1234321ll,
	4008004ll,100020001ll,102030201ll,104060401ll,121242121ll,123454321ll,125686521ll,
	400080004ll,404090404ll,10000200001ll,10221412201ll,12102420121ll,12345654321ll,
	40000800004ll,1000002000001ll,1002003002001ll,1004006004001ll,1020304030201ll,
	1022325232201ll,1024348434201ll,1210024200121ll,1212225222121ll,1214428244121ll,
	1232346432321ll,1234567654321ll,4000008000004ll,4004009004004ll,100000020000001ll,
	100220141022001ll,102012040210201ll,102234363432201ll,121000242000121ll,
	121242363242121ll,123212464212321ll,123456787654321ll,400000080000004ll};
void solve(int nr) {
	ll A,B;
	scanf("%lld%lld",&A,&B);
	int p=0,q=47;
	while(P[p]<A) p++;
	while(P[q]>B) q--;
	printf("Case #%d: %d\n",nr,q-p+1);
}
int main() {
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++) solve(i);
	return 0;
}