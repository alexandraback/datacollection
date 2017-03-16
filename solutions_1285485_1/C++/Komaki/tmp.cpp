#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <sys/time.h>
using namespace std;
#define li        long long int
#define rep(i,to) for(int i=0;i<((int)(to));++i)
#define pb        push_back
#define sz(v)     ((int)(v).size())
#define bit(n)    (1ll<<(li)(n))
#define all(vec)  (vec).begin(),(vec).end()
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MP        make_pair
#define F         first
#define S         second


#define MAX 35
char mp[MAX][MAX];
int n, m, d;

int main(){
	int T;
	cin>>T;
	rep(play_turn, T){
		scanf("%d %d %d", &n, &m, &d);
		rep(i, n) scanf("%s", mp[i]);
		int res = 0;
		pair<int,int> base = MP(-1, -1);
		rep(i, n)rep(j, m)if(mp[i][j] == 'X') base = MP(i, j);
		for(int X = 1; X <= d; X++){
			for(int Y = 1; Y<= d; Y++){
				rep(_dx, 2){
					rep(_dy, 2){
						bool broken = false;
						if(d * d < X * X + Y * Y) break;
						int x = base.F * 2 + 1;
						int y = base.S * 2 + 1;
						int dx = _dx;
						int dy = _dy;
						int len = X * Y * 2;
						int cur_X = base.F;
						int cur_Y = base.S;
						for(int turn = 1; turn <= len && !broken; turn++){
							bool updated = false;
							bool touch_X = (turn % Y) == 0;
							bool touch_Y = (turn % X) == 0;
							if(touch_X){
								if(dx) x++;
								else x--;
								updated = true;
							}
							if(touch_Y){
								if(dy) y++;
								else y--;
								updated = true;
							}
							if(!updated) continue;
							if(turn == len) break;
							if(x == base.F * 2 + 1 && y == base.S * 2 + 1 && touch_X && touch_Y) broken = true;
							bool diag = false;
							bool mx = false;
							bool my = false;
							int next_X = cur_X + (dx ? 1 : -1);
							int next_Y = cur_Y + (dy ? 1 : -1);
							if(mp[next_X][next_Y] == '#') diag = true;
							if(mp[next_X][cur_Y ] == '#') mx = true;
							if(mp[cur_X ][next_Y] == '#') my = true;
							if(touch_X && touch_Y && x % 2 == 0 && y % 2 == 0){
								if(diag){
									if(!mx && !my) broken = true;
									if(mx) dx = !dx;
									if(my) dy = !dy;
								}
							}else if(touch_X && x % 2 == 0){
								if(mx) dx = !dx;
							}else if(touch_Y && y % 2 == 0){
								if(my) dy = !dy;
							}
							if(touch_X) cur_X = (x - (dx ? 0 : 1)) / 2;
							if(touch_Y) cur_Y = (y - (dy ? 0 : 1)) / 2;
						}
						if(!broken && base.F * 2 + 1 == x && base.S * 2 + 1 == y) res++;
					}
				}
			}
		}
		int dx[] = {1, 0, -1,  0};
		int dy[] = {0, 1,  0, -1};
		rep(i, 4){
			int x = base.F;
			int y = base.S;
			int cnt = 0;
			while(mp[x][y] != '#'){
				cnt++;
				x += dx[i];
				y += dy[i];
			}
			if(cnt * 2 - 1 <= d) res++;
		}
		
		printf("Case #%d: %d\n", play_turn + 1, res);
	}
}
