#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

pair<int, int> c[102][102];
int gox[] = {1, 0, -1, 0};
int goy[] = {0, -1, 0, 1};

int main(){
	int tc, tcn;
	cin >> tcn;
	for(tc=0; tc<tcn; ++tc){
		int s = 0;
		int h, n, m;
		memset(c, 0, sizeof(c));
		
		cin >> h >> n >> m;
		for(int j=0; j<n; ++j)
			for(int i=0; i<m; ++i)
				cin >> c[j+1][i+1].first;
		for(int j=0; j<n; ++j)
			for(int i=0; i<m; ++i)
				cin >> c[j+1][i+1].second;

		set<pair<int, int> > pos[101];
		pos[0].insert(make_pair(1, 1));
		for(;; ++s){
			//fprintf(stderr, "%d\n", s);
			while(!pos[s%101].empty()){
				int x = pos[s%101].begin()->first;
				int y = pos[s%101].begin()->second;
				
				int ch = max(h, c[y][x].second);
				
				//fprintf(stderr, "%d %d %d\n", x, y, ch);

				pos[s%101].erase(pos[s%101].begin());
				if(x == m && y == n)
					goto ende;
				pos[(s+1)%101].insert(make_pair(x, y));
				for(int k=0; k<4; ++k){
					int nx = x + gox[k];
					int ny = y + goy[k];
					
					if(ch + 50 <= c[ny][nx].first && c[ny][nx].second + 50 <= c[ny][nx].first && c[ny][nx].second + 50 <= c[y][x].first){
						
						//fprintf(stderr, " go %d %d\n", nx, ny);
						
						if(h - c[y][x].second >= 20){
							pos[(s+10)%101].insert(make_pair(nx, ny));
						}else{
							pos[(s+100)%101].insert(make_pair(nx, ny));
						}
					}
				}
			}
			if(s >= 100*100*10){
				if(h)
					--h;
			}
		}
ende:
		s = max(s - 100*100*10, 0);
		printf("Case #%d: %d.%d\n", tc+1, s/10, s%10);
	}
}
