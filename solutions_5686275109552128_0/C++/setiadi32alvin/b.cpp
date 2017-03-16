#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<utility>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>

#define LL long long
#define MP make_pair
#define PB push_back
#define ii pair<int,int>
using namespace std;
int t,n,ans;
int ar[1011];
int main(){
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		scanf("%d",&n);
		ans = 10000;
		int mx = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&ar[i]);
			mx = max(mx,ar[i]);
		}
		for(int i=1;i<=mx;i++){
			int tmp = 0;
			int tmax = 0;
			for(int j=0;j<n;j++){
				if(ar[j]<=i){
					tmax = max(tmax , ar[j]);
				}
				else{
					tmax = max(tmax,ar[j]%i);
					tmax = max(tmax,i);
					tmp+=(ar[j]-1)/i ;
				}
			}
			ans = min(ans,tmp+tmax);
		}
		printf("Case #%d: %d\n",z,ans);
	}
	return 0;
}