#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define rep(i,n) fr(i,0,n)

char ma[20][20];
int dx[] = {1, 0, 1, 1};
int dy[] = {0, 1, 1, -1};

int main(){
	int t;
	scanf("%d", &t);
	
	rep(cas, t){
		rep(i, 4) scanf("%s", ma[i]);
		
		int win = -1;
		bool temPonto = false;
		rep(i, 4){
			rep(j, 4){
				if(ma[i][j] == '.') temPonto = true;
				rep(d, 4){
					int cnt[] = {0,0};
					rep(k, 4){
						int nx = i + k*dx[d], ny = j + k*dy[d];
						if(nx >= 0 && nx < 4 && ny >= 0 && ny < 4){
							if(ma[nx][ny] == 'O') ++cnt[0];
							if(ma[nx][ny] == 'X') ++cnt[1];
							if(ma[nx][ny] == 'T') ++cnt[0], ++cnt[1];
						}
					}
					if(cnt[0] == 4) win = 'O';
					if(cnt[1] == 4) win = 'X';
				}
			}
		}
		printf("Case #%d: ", 1+cas);
		if(~win) printf("%c won\n", char(win));
		else if(temPonto) printf("Game has not completed\n");
		else printf("Draw\n");
	}
}
