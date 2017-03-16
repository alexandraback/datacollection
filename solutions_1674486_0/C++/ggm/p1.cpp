#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>

const int LEN = 1005;
using namespace std;

int N, done, start;
int record[LEN][LEN];
int tag[LEN];
vector<int> edge[LEN];

void dfs(int now) {

//	printf("start%d %d %d\n",start,now,tag[now]);

	if(tag[now] == 1) {
		done = 1;
	}

	if(done) return;

	tag[now] = 1;
	for(int i=0;i<edge[now].size(); i++) {
		dfs(edge[now][i]);	
	}
}

int main() {

	int T;
	scanf("%d",&T);

	for(int t=1;t<=T;t++) {
	
		scanf("%d",&N);

		for(int i=0;i<N;i++) {
			int m;
			scanf("%d",&m);
			edge[i].resize(m);
			for(int j=0;j<m;j++) {
				scanf("%d",&edge[i][j]);
				edge[i][j]--;
			}
		}
		
		memset(record,0,sizeof(record));
		done = false;

		for(int i=0;i<N;i++) {
			if(done==false) {
				memset(tag,0,sizeof(tag));
				start = i;
				dfs(i);
			}
		}

		if(done == true )
			printf("Case #%d: Yes\n",t);
		else
			printf("Case #%d: No\n",t);
	}

}
