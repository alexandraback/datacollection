#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
const int MaxN= 22;
int T, N, a[MaxN], hsh[MaxN], flag, CaseCount;
vector<int> ans;
void dfs(int x, int s1, int s2){
	if(x <= N){
		if(!flag){
			hsh[x]= 1;
			dfs(x+1, s1+a[x], s2);
		}
		if(!flag){
			hsh[x]= 2;
			dfs(x+1, s1, s2+a[x]);
		}
		if(!flag){
			hsh[x]= 0;
			dfs(x+1, s1, s2);
		}
	}else{
		if(s1 == s2){
			ans.clear();
			for(int i= 1;i<= N;++ i) if(hsh[i] == 1) ans.push_back(a[i]);
			for(int i= 0;i< ans.size();++ i) printf(i+1 < ans.size() ? "%d " : "%d\n", ans[i]);
			ans.clear();
			for(int i= 1;i<= N;++ i) if(hsh[i] == 2) ans.push_back(a[i]);
			for(int i= 0;i< ans.size();++ i) printf(i+1 < ans.size() ? "%d " : "%d\n", ans[i]);
			flag= 1;
		}
	}
}
int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while(T --){
		scanf("%d", &N);
		for(int i= 1;i<= N;++ i)
			scanf("%d", a+i);
		printf("Case #%d: \n", ++CaseCount);
		flag= 0;
		dfs(1, 0, 0);
	}
//	system("pause");
	return 0;
}
