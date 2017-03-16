#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <set>
#include <iostream>
using namespace std;

typedef long long ll;
const ll inf=1LL<<50;
ll r,t;

int solve(ll n)
{
	if(n==0) return 1;
	ll tt=t/n;
	if(tt>=2*r+2*n-1) return 1;
	return 0;
}
int main() {
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);
	int T,ri=1;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d%I64d",&r,&t);
		ll left=0,right=inf,mid,ans;
		while(left<=right){
			mid=(left+right)/2;
			if(solve(mid)){
				left=mid+1;
				ans=mid;
			}else
				right=mid-1;
		}
		printf("Case #%d: %I64d\n",ri++,ans);
	}
}
