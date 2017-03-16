// adijimmy
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
#define MAX 1005
int arr[MAX],brr[MAX],D,P;
bool solve(int tim,int mid){
	int sz = 0;
	for(int i=0;i<D;i++){
		if(arr[i] > mid){
		  int transfer = arr[i]-mid;
		  sz += 1;
		  brr[sz] = transfer;
		}
	}
	int idx = 1;
	while(idx <= sz){
		if(tim==0 && brr[idx]>0) return false;
		if(mid >= brr[idx]) idx++;
		else brr[idx] -= mid;
		tim -=1 ;
	}
	return true;
}
int main(){
	int t;
	freopen("B-large.in","r",stdin);
	freopen("ans.txt","w",stdout);
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		scanf("%d",&D);
		for(int i=0;i<D;i++) scanf("%d",&arr[i]);
		int ans = INT_MAX;
		for(int tim=0;tim<=MAX;tim++){
			int l = 1;
			int h = MAX;
			while(l < h){
				int mid= (l+h)>>1;
				bool flag = solve(tim,mid);
				if(flag == false) l = mid+1;
				else h = mid;
			}
			ans = min(ans,tim+l);
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
