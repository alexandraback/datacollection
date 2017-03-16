#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <deque>
using namespace std;
int n,m;
bool adj[55][55];
int code[55];
bool ok[55][55];
bool reach[55][55];
bool OK(vector<int> sequence) {
	int N = (int)sequence.size();
	for (int l=N-1; l>=0; l--) {
		int r=N-1;
		ok[l][r]=false;
		static bool sub[55];
		memset(sub,0,sizeof sub);
		// [l+1..r]
		sub[l+1] = true;
		for (int left=l+1; left<=r; left++) if (sub[left] && adj[sequence[l]][sequence[left]]) {
			for (int right=left; right<=r; right++) {
				if (ok[left][right]) {
					sub[right+1] = true;
				}
			}
		}
		if (sub[r+1]) {
			ok[l][r]=true;
			memset(reach[l],0,sizeof reach[l]);
			for (int i=0;i<N;i++) reach[l][sequence[i]] = true;
			for (int lastc=l+1; lastc<=N-1; lastc++) {
				if (sub[lastc] && adj[sequence[l]][sequence[lastc]] && ok[lastc][N-1]) {
					for(int x=0;x<n;x++)if(reach[lastc][x])reach[l][x]=true;
				}
			}
			// find others by BFS
			deque<int> Q;
			Q.push_back(sequence[l]);
			while (!Q.empty()) {
				int x=Q.front();
				Q.pop_front();
				for(int y=0;y<n;y++)if(adj[x][y] && !reach[l][y]) {
					reach[l][y]=true;
					Q.push_back(y);
				}
			}
		}
	}
	if (!ok[0][N-1]) return false;
	for (int x=0;x<n;x++) if (!reach[0][x]) return false;
	return true;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int tc=1;tc<=T;tc++) {
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++)scanf("%d",&code[i]);
		memset(adj,0,sizeof adj);
		for (int e=0;e<m;e++) {
			int x,y;
			scanf("%d%d",&x,&y);
			x--;
			y--;
			adj[x][y]=adj[y][x]=true;
		}
		memset(ok,0,sizeof ok);
		vector<int> answer;
		for (int iter=0; iter<n; iter++) {
			int nxt = -1;
			for (int x=0; x<n; x++) if (find(answer.begin(),answer.end(),x) == answer.end()) {
				vector<int> answer2 = answer;
				answer2.push_back(x);
				if (OK(answer2)) {
					if (nxt==-1 || code[x] < code[nxt]) nxt = x;
				}
			}
			answer.push_back(nxt);
			assert(OK(answer));
		}
		printf("Case #%d: ",tc);
		for (int i=0;i<n;i++) printf("%d",code[answer[i]]);
		printf("\n");
	}
}
