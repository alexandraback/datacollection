#include<iostream>
#include<string>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
#include<stack>
#include<vector>
#include<ctime>
#include<map>
#include<set> 
#include<cctype>
#include<cstdlib>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const int maxn = 10000000;
const int maxe = 2*maxn*maxn;
typedef unsigned long long ULL;
///////////////////////////////////////////////////////////////////////////////////
ULL r,t,a1;
inline ULL cal(ULL n){
	return n*a1 + ((n*(n-1))<<1);
}
int main(){
	//freopen("A-large.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;scanf("%d",&T);
	for(int ci = 1; ci <= T; ++ci){
		printf("Case #%d: ",ci);
		scanf("%llu%llu",&r,&t);
		a1 = 2*r+1;
		ULL L=0,R=min(t,(ULL)1e9);
		R = min(R,((ULL)1e19)/a1);
		while(L<=R){
			ULL mid = (L+R)>>1;
			cal(mid) <= t ? L=mid+1:R=mid-1;
		}
		printf("%llu\n",R);
	}
	return 0;
}