#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> ve;
int e, r, n, ans;
int v[20];
int get(){
	int ret = 0, ener = e;
	for(int i = 0;i < n; ++i){
		if(ener < ve[i]) return 0;
		ret += v[i] * ve[i];
		ener -= ve[i];
		ener += r;
		if(ener > e) ener = e;
	}
	return ret;
}
void dfs(int cnt,int depth){
	if(depth >= n){
		ans = max(ans, get());
		return ;
	}
	for(int i = cnt;i <= e; ++i){
		ve.push_back(i);
		dfs(0, depth + 1);
		ve.pop_back();
	}
}
int main()
{
	int cas;
	scanf("%d",&cas);
	for(int it = 1;it <= cas; ++it){
		scanf("%d%d%d",&e,&r,&n);
		ve.clear();
		for(int i = 0;i < n; ++i) scanf("%d",v+i);
		ans = 0;
		dfs(0, 0);
		printf("Case #%d: %d\n",it,ans);
	}
}
