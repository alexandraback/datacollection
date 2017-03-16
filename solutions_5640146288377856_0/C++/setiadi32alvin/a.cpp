#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>

#define LL long long
#define ii pair<int,int>
using namespace std;
int ar[22][22];
int t,r,c,w;
int ans;
int main(){
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		printf("Case #%d: ",z);
		scanf("%d%d%d",&r,&c,&w);
		ans = 0;
		memset(ar,0,sizeof(ar));
		for(int i=1;i<=c;i++)
			if(i%w==0){
				for(int j=1;j<=r;j++){
					ans+=(ar[j][i]==0);
					ar[j][i]|=1;
				}
			}
		
		if(c%w!=0)	ans++;
		ans+=w-1;
		printf("%d\n",ans);
	}
	return 0;
}
