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
int t,n;
int ans;
char in[1110];
int main(){
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		scanf("%d %s",&n,in);
		for(ans=0;ans<=n;ans++){
			int tmp = ans;
			bool bisa = 1;
			for(int i=0;i<=n;i++){
				if(tmp>=i){
					tmp+=in[i]-'0';
				}
				else	bisa=0;
			}
			if(bisa)	break;
		}
		printf("Case #%d: %d\n",z,ans);
	}
	return 0;
}