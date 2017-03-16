#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int T,R,C,M;

/*
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
char ans[5][5];

int dfs(int r, int c) {
	int ret = 1;
	int cnt = 0;
	for(int i=0;i<8;++i) {
		int nr = r + dx[i];
		int nc = c + dy[i];
		if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
		if(ans[nr][nc] == '*') cnt++;
		
	}
	if(cnt == 0) {
		for(int i=0;i<8;++i) {
			int nr = r + dx[i];
			int nc = c + dy[i];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if(ans[nr][nc] != '*') ret += dfs(nr,nc);		
		}
	}
	else return 1;
}

bool done = 0;
void backtr(int r, int c, int cnt) {
	if(c == C) {
		backtr(r+1,0,cnt);
		return;
	}
	if(r == R){
		if(cnt == 0) {
			for(int i=0;i<R;++i) for(int j=0;j<C;++j) {
				if(!done && ans[i][j]=='.' && dfs(i,j) == R*C-M) {
					done = 1;
					ans[i][j]='c';
					for(int x=0;x<R;++x) {
						for(int y=0;y<C;++y) printf("%c",ans[x][y]);
						puts("");
					}
				}
			}
		}
	}
	else {
		ans[r][c] = '.';
		backtr(r,c+1,cnt);
		if(cnt)
			ans[r][c] = '*',
			backtr(r,c+1,cnt-1);
	}
}
*/

int main() {
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&T);
	for(int cs=1;cs<=T;++cs) {
		printf("Case #%d:\n",cs);
		scanf("%d%d%d",&R,&C,&M);

		//done = 0;
		//backtr(0,0,M);

		//continue;
				
		vector< string >  ans(R, string(C, '*'));
		vector< string > ans2(C, string(R, '*'));
		bool done = false;
		bool sw   = false;
		int n = R*C-M;

		if(n == 1) {
			ans[0][0] = 'c';
			for(int i=0;i<R;++i) printf("%s\n",ans[i].c_str());
			continue;
		}

		for(int z=1;z<=C;++z) {
			if( done ) continue;
			if(z == 1 && C > z) continue;
			int t = (n + z-1) / z;
			int rem = n % z;
			if(t > R || t < 2) continue;
			if(rem == 0) {
				done = true;
				for(int i=0;i<t;++i) for(int j=0;j<z;++j)
					ans[i][j] = '.';
			}
			else if(rem == 1) {
				if(t >= 4 && z > 2) {
					done = true;
					for(int i=0;i<t-1;++i) for(int j=0;j<z;++j)
						ans[i][j] = '.';
					ans[t-2][z-1] = '*';
					ans[t-1][0] = '.';
					ans[t-1][1] = '.';
				}
				else continue;
			}
			else {
				if(t >= 3) {
					done = true;
					for(int i=0;i<t-1;++i) for(int j=0;j<z;++j)
						ans[i][j] = '.';
					for(int j=0;j<rem;++j)
						ans[t-1][j] = '.';
				}
			}
		}
		swap(R,C);
		for(int z=1;z<=C;++z) {
			if( done ) continue;
			if(z == 1 && C > z) continue;
			int t = (n + z-1) / z;
			int rem = n % z;
			if(t > R || t < 2) continue;
			if(rem == 0) {
				done = true, sw = true;
				for(int i=0;i<t;++i) for(int j=0;j<z;++j)
					ans2[i][j] = '.';
			}
			else if(rem == 1) {
				if(t >= 4 && z > 2) {
					done = true, sw = true;
					for(int i=0;i<t-1;++i) for(int j=0;j<z;++j)
						ans2[i][j] = '.';
					ans2[t-2][z-1] = '*';
					ans2[t-1][0] = '.';
					ans2[t-1][1] = '.';
				}
				else continue;
			}
			else {
				if(t >= 3) {
					done = true, sw = true;
					for(int i=0;i<t-1;++i) for(int j=0;j<z;++j)
						ans2[i][j] = '.';
					for(int j=0;j<rem;++j)
						ans2[t-1][j] = '.';
				}
			}
		}

		ans[0][0] = 'c';
		ans2[0][0] = 'c';
		if(done) {
			if(!sw) {
				for(int i=0;i<ans.size();++i) printf("%s\n",ans[i].c_str());
			}
			else {
				for(int j=0;j<ans2[0].size();++j) {
					for(int i=0;i<ans2.size();++i) printf("%c",ans2[i][j]);
					puts("");
				}
			}
		}
		else printf("Impossible\n");
	}
}