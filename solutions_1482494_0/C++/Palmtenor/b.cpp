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
const int maxn=1001;
int n;
int a[maxn],b[maxn],stat[maxn];

void init(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	return;
}

void process(){
	int cur=0;
	int ans=0;
	memset(stat,0,sizeof(stat));
	while (cur<(n<<1)){
		bool flag=false;
		for (int i=1;i<=n;i++){
			if ((stat[i]==0)&&(cur>=b[i])){
				flag=true;
				stat[i]=2;
				cur=cur+2;
				ans++;
			}
			if ((stat[i]==1)&&(cur>=b[i])){
				flag=true;
				stat[i]=2;
				cur++;
				ans++;
			}
		}
		if (flag){
			continue;
		}
		int best,bestp;
		best=bestp=-1;
		for (int i=1;i<=n;i++){
			if (stat[i]!=0){
				continue;
			}
			if (a[i]>cur){
				continue;
			}
			if (best<b[i]){
				best=b[i];
				bestp=i;
			}
		}
		if (best==-1){
			break;
		}
		stat[bestp]=1;
		cur++;
		ans++;
	}
	if (cur<(n<<1)){
		puts("Too Bad");
	} else {
		printf("%d\n",ans);
	}
	return;
}

int main(){
	int tcase;
	scanf("%d",&tcase);
	for (int i=1;i<=tcase;i++){
		init();
		printf("Case #%d: ",i);
		process();
	}
	return 0;
}
