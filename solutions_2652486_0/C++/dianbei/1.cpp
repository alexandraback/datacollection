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

int a[10];
int N,M,K;
vector<int> st;
set<int> S;
int dfs(int k)
{
	if(k>=N){
		S.clear();
		for(int i=0;i<(1<<N);i++){
			int sum=1;
			for(int j=0;j<N;j++){
				if((i>>j)&1) sum*=st[j];
			}
			S.insert(sum);
		}
		for(int i=0;i<K;i++)
			if(S.find(a[i])==S.end()) return 0;
		for(int i=0;i<st.size();i++)
			printf("%d",st[i]);
		puts("");
		return 1;
	}
	for(int i=2;i<=M;i++){
		st.push_back(i);
		if(dfs(k+1)) return 1;
		st.pop_back();
	}
	return 0;
}
int main() {
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T,R,ri=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&R,&N,&M,&K);
		printf("Case #%d:\n",ri++);
		for(int i=0;i<R;i++){
			for(int j=0;j<K;j++){
				scanf("%d",&a[j]);
			}
			st.clear();
			int t=dfs(0);
			if(t==0){
				for(int i=0;i<N;i++)
					printf("2");
				puts("");
			}
		}
	}
}
