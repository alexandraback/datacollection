#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const int N=1004;
vector<int> Map[N];
int n;
bool visit[N],is_ok,v2[N];

void dfs(int x)
{
	if(is_ok) return;
	if(v2[x]){
		is_ok=true;
		return;
	}
	v2[x]=true;
	for(int i=0;i<Map[x].size() && !is_ok;i++){
		dfs(Map[x][i]);
	}
}
void debug()
{
	for(int i=0;i<n;i++){
		printf("%d:",i);
		for(int j=0;j<Map[i].size();j++) printf(" %d",Map[i][j]);
		printf("\n");
	}
}
int main(){
	freopen("data_A.txt","r",stdin);
	freopen("result_A.txt","w",stdout);
	int cases,cnt=0;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		int x,num;
		memset(visit,0,sizeof(visit));
		for(int i=0;i<n;i++){
			Map[i].clear();
			scanf("%d",&num);
			while(num--){
				scanf("%d",&x);
				Map[i].push_back(x-1);
				visit[x-1]=true;
			}
		}
		//debug();
		is_ok=false;
		for(int i=0;i<n&&!is_ok;i++){
			if(!visit[i]){
				memset(v2,0,sizeof(v2));
				dfs(i);
			}
		}
		if(is_ok) printf("Case #%d: Yes\n",++cnt);
		else printf("Case #%d: No\n",++cnt);
	}
	return 0;
}
