#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#define MAXN 100050
#define LL long long
using namespace std;
bool bo[11];
int solve(int n){
	memset(bo,0,sizeof(bo));
	if(n==0)return -1;
	int cnt=0;
	int tar=0;

	int now=0;
	while(true){
		if(cnt>MAXN)return -1;
		now+=n;
		cnt++;
		int x=now;
		while(x){
			int y=x%10;
			if(!bo[y]){
				bo[y]=true;
				tar++;
			}
			x/=10;
		}
		if(tar==10)
			return cnt;
	}
	return -1;
}
int main() {
	freopen("A-large.in","r",stdin);
	freopen("A-large.txt","w",stdout);
	int tt,ri=0;
	scanf("%d",&tt);
	while(tt--){
		int n;
		scanf("%d",&n);
		int ans=solve(n);
		if(ans==-1)
		{
			printf("Case #%d: INSOMNIA\n",++ri);
			continue;
		}
		printf("Case #%d: %lld\n",++ri,(LL)n*ans);
	}
	return 0;
}
