#include <bits/extc++.h>
#include <iostream>

using namespace std;

//#define NDEBUG
#ifdef NDEBUG
#define DEBUG if (false)
#else
#define DEBUG if (true)
#endif
#define WRITE(x) DEBUG { cout << (x) << endl; }
#define WATCH(x) DEBUG { cout << #x << " = " << (x) << endl; }
//#define ALL(x) (x).begin(), (x).end()
//#define FORN(i, a, b) for(typeof(b) i = (a); i < (b); ++i)
//#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ntc;
	cin >> ntc;
	for(int tc = 0; tc < ntc; tc++){
		int r, c, m;
		cin >> r >> c >> m;
		cout << "Case #" << (tc + 1) << ":\n";

		vector<vector<char>> conf(r, vector<char>(c, '.'));
		conf[r - 1][c - 1] = 'c';
		bool possible = true;

		if(r == 1 or c == 1){
			int num_mines = 0;
			for(int i = 0; i < r and num_mines < m; i++){
				for(int j = 0; j < c and num_mines < m; j++){
					conf[i][j] = '*';
					num_mines++;
				}
			}
		}else if(m == r * c - 1){
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					if(i < r - 1 or j < c - 1){
						conf[i][j] = '*';
					}
				}
			}
		}else{
			int need = r * c - m;
			for(int i = 0; i < r; i++){
				fill(conf[i].begin(), conf[i].end(), '*');
			}
			bool done = false;
			if(need % 2 == 0){
				int times = need / 2;
				if(times <= r and times != 1){
					for(int i = 0; i < times; i++){
						conf[i][0] = conf[i][1] = '.';
					}
					done = true;
				}else if(times <= c and times != 1){
					for(int j = 0; j < times; j++){
						conf[0][j] = conf[1][j] = '.';
					}
					done = true;
				}
			}

			if(not done){
				for(int start = 3; start <= need; start++){
					int times = (need + start - 1) / start;
					int last = need - (times - 1) * start;
					int past_to_last = start;
					if(times == 3 and last == 1) continue;
					if(last == 1){
						last++;
						past_to_last--;
					}
					if(times < 3) continue;
					if(times <= r and start <= c){
						for(int i = 0; i < times; i++){
							int size = start;
							if(i == times - 1){
								size = last;
							}else if(i == times - 2){
								size = past_to_last;
							}
							for(int j = 0; j < size; j++){
								conf[i][j] = '.';
							}
						}
						done = true;
						break;
					}else if(times <= c and start <= r){
						for(int j = 0; j < times; j++){
							int size = start;
							if(j == times - 1){
								size = last;
							}else if(j == times - 2){
								size = past_to_last;
							}
							for(int i = 0; i < size; i++){
								conf[i][j] = '.';
							}
						}
						done = true;
						break;
					}
				}
			}

			conf[0][0] = 'c';
			if(not done) possible = false;

		}

		if(possible){
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					cout << conf[i][j];
				}
				cout << '\n';
			}
		
			vector<vector<int>> val(r, vector<int>(c));
			int num_bombs = 0;
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					if(conf[i][j] == '*') num_bombs++;
					for(int mi = -1; mi < 2; mi++){
						for(int mj = -1; mj < 2; mj++){
							if(mi or mj){
								int ni = i + mi;
								int nj = j + mj;
								if(ni < 0 or ni >= r or nj < 0 or nj >= c) continue;
								if(conf[ni][nj] == '*') val[i][j]++;
							}
						}
					}
				}
			}
			
			assert(num_bombs == m);

			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					if(conf[i][j] == '.' and val[i][j] != 0){
						bool ok = false;
						for(int mi = -1; mi < 2; mi++){
							for(int mj = -1; mj < 2; mj++){
								if(mi or mj){
									int ni = i + mi;
									int nj = j + mj;
									if(ni < 0 or ni >= r or nj < 0 or nj >= c) continue;
									if(val[ni][nj] == 0) ok = true;
								}
							}
						}
						assert(ok);
					}
				}
			}

		}else{
			cout << "Impossible\n";
		}
	}
}
