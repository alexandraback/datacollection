//

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <cmath>

using namespace std;

#define db(x) cout << #x " == " << x << endl
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back

int casos, n, inc[1050][1050], ninc[1050];
bool us[1050], mark[1050];
queue<int> starts;

bool dfs(int s){
	Fr(i,0,ninc[s]){
		if(mark[inc[s][i]]) return true;
		mark[inc[s][i]] = true;
		if(dfs(inc[s][i])) return true;
	}
	return false;
}

int main() {
	int _=1;
	for(scanf("%d",&casos); casos; --casos){
		printf("Case #%d: ",_++);
		memset(us,false,sizeof(us));
		
		scanf("%d",&n);
		Fr(i,1,n+1){
			scanf("%d",&ninc[i]);
	//		printf("%d ",ninc[i]);
			Fr(j,0,ninc[i]){
				scanf("%d",&inc[i][j]);
				us[inc[i][j]] = true;
	//			printf("%d ",inc[i][j]);
			}
	//		puts("");
		}
		Fr(i,1,n+1)
			if(!us[i]) starts.push(i);
		
		bool res = false;
		while(!starts.empty()){
			int s = starts.front(); starts.pop();
			memset(mark,false,sizeof(mark));
	//		printf("Starting from %d\n",s);
			if(dfs(s)){
				res = true;
				break;
			}
		}
		while(!starts.empty()) starts.pop();
		if(res) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
