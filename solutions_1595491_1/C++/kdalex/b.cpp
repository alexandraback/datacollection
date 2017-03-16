#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int t, n, s, p, cnt;
vector<int> ti;
int tg;


int add[2][3] ={{0, 1, 1}, {1, 1, 2}};
int mina[2][3] = {{0, 0, 0}, {-1, 0, 0}};

int main() {
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		cin >> n >> s >> p;
		cnt = 0;
		for(int i = 0; i < n; i++) {
			cin >> tg;
			if(((tg / 3) + add[0][tg % 3]) >= p && ((tg / 3) + mina[0][tg % 3] >= 0))
				cnt++;
			else {
				if(s > 0 && ((tg / 3) + add[1][tg % 3]) >= p && ((tg / 3) + mina[1][tg % 3] >= 0)) {
					cnt++;
					s--;
				}
			}
		}
		cout << "Case #" << tt << ": " << cnt << endl;
		
	}
	return 0;
}