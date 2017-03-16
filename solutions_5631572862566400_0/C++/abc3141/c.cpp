#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;
int T;
int N;
int FR[1000];
bool F[1000];
int S[1000];
int num[1000];
int end[1000];
P dfs(int now,int cou){
	if(F[now])return P(now,cou);
	F[now]=true;
	return dfs(FR[now],cou+1);
}
int main()
{
	scanf("%d",&T);
	for(int cas=0;cas<T;cas++){
		scanf("%d",&N);
		int ans=0;
		for(int i=0;i<N;i++){
			scanf("%d",&FR[i]);FR[i]--;
		}
		for(int s=0;s<N;s++){
			for(int i=0;i<N;i++){
				F[i]=false;
			}
			P p=dfs(s,0);
			if(p.first==s){
				end[s]=FR[p.first];
				ans=max(ans,p.second);
				num[s]=p.second-2;
			}
			else{
				num[s]=p.second-2;end[s]=p.first;
			}
		}
		/*
		for(int i=0;i<N;i++){
			printf("%d %d\n",num[i],end[i]);
		}*/
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(i==j)continue;
				if(FR[end[i]]==end[j]&&end[i]==FR[end[j]])ans=max(ans,num[i]+num[j]+2);
			}
		}
		printf("Case #%d: %d\n",cas+1,ans);
	}
}

