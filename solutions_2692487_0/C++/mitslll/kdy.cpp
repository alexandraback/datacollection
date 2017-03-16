#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> v;
int mins;
void dfs(int now,int n,int cnt){
	if(cnt >= mins)	return;
	if(n==v.size()){
		mins = cnt;
		return;
	}
	if(v[n] < now)	dfs(now + v[n],n+1,cnt);
	dfs(now *2 - 1,n,cnt+1);
	dfs(now,n+1,cnt+1);
}
void process(){
	v.clear();
	int now, n;
	scanf("%d %d",&now,&n);
	mins = n+1;
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	dfs(now,0,0);
	printf("%d\n",mins);
}
int main(){
	int t;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		process();
	}
	return 0;
}