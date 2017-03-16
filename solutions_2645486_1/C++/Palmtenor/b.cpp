#include <cstdio>
#include <cmath>
#include <cstring>
#include <memory.h>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const __int64 maxn=10001;
__int64 e,r,n;
__int64 v[maxn],rem[maxn],pos[maxn];
pair<int,int> a[maxn];

void init(){
	scanf("%I64d%I64d%I64d",&e,&r,&n);
	for (__int64 i=0;i<n;i++){
		scanf("%I64d",&v[i]);
		a[i]=make_pair(-v[i],i);
		rem[i]=pos[i]=r;
	}
	return;
}

__int64 dp(){
	__int64 ans=0;
	sort(a,a+n);
	rem[0]=pos[0]=e;
	for (__int64 i=0;i<n;i++){
		__int64 cur=a[i].second;
		for (__int64 k=cur;k>=0;k--){
			__int64 tcost=e-(cur-k)*r;
			if (tcost<=0){
				break;
			}
			tcost=min(tcost,pos[k]);
			if (rem[k]+tcost>pos[k]){
				ans+=(rem[k]-pos[k]+tcost)*v[cur];
				rem[k]=pos[k]-tcost;
			}
		}
	}
	return ans;
}

int main(){
	__int64 tcase;
	scanf("%I64d",&tcase);
	for (__int64 i=1;i<=tcase;i++){
		init();
		printf("Case #%I64d: %I64d\n",i,dp());
	}
	return 0;
}
