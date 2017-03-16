#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 105;
const int MAXM = 105;

int cases, N, M;
int Gr[MAXN][MAXM], Now[MAXN][MAXM];
bool Flag[MAXN][MAXM];
vector< pair< int, pair<int, int> > > gao;

int main(){
	scanf("%d", &cases);
	for(int xx = 1; xx <= cases; ++xx){
		scanf("%d%d", &N, &M);
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				scanf("%d", &Gr[i][j]);
		gao.clear();
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j){
				gao.push_back(make_pair(-Gr[i][j], make_pair(i, j)));
			}
		sort(gao.begin(), gao.end());
		memset(Now, 0, sizeof(Now));
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				Now[i][j] = -gao[0].first;
		memset(Flag, false, sizeof(Flag));
		Flag[gao[0].second.first][gao[0].second.second] = true;
		for(int i = 1; i < gao.size(); ++i){
			int x = gao[i].second.first, y = gao[i].second.second;
			int v = -gao[i].first;
			if(Now[x][y] == v){
				Flag[x][y] = true;
				continue;
			}
			bool ok = true;
			for(int i = 0; i < N; ++i)
				if(Flag[i][y] && Now[i][y] > v) ok = false;
			if(ok){
				for(int i = 0; i < N; ++i)
					Now[i][y] = v;
			}
			ok = true;
			for(int i = 0; i < M; ++i)
				if(Flag[x][i] && Now[x][i] > v) ok = false;
			if(ok){
				for(int i = 0; i < M; ++i)
					Now[x][i] = true;
			}
			Flag[x][y] = true;
		}
		bool check = true;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				if(Now[i][j] != Gr[i][j]) check = false;
		if(check) printf("Case #%d: YES\n", xx);
		else printf("Case #%d: NO\n", xx);
	}
}
