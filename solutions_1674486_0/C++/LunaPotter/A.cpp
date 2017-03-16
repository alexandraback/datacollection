/*************************************************************************
    > File Name: A.cpp
    > Created Time: 日  5/ 6 17:03:56 2012
 ************************************************************************/

#include<iostream>
using namespace std;

int map[1024][16];

int main() {
	int Ncase;
	cin >> Ncase;
	for(int T = 1; T <= Ncase; T ++) {
		int n;
		bool found = false;
		cout << "Case #" << T << ": ";
		cin >> n;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++) map[i][j] = false;
		for(int i = 1; i <= n; i ++) {
			cin >> map[i][0];
			for(int j = 1; j <= map[i][0]; j ++) {
				cin >> map[i][j];
			}
		}
		for(int i = 1; i <= n; i ++) {
			int head, tail, list[1024], count[1024];
			head = -1;
			tail = 0;
			for(int x = 1; x <= n; x ++) count[x] = 0;
			list[0] = i;
			while(head < tail) {
				int x = list[++ head];
				for(int j = 1; j <= map[x][0]; j ++) {
					int y = map[x][j];
					if(count[y] == 0) {
						list[++ tail] = y;
						count[y] = 1;
					} else {
						found = true;
						break;
					}
					if(found) break;
				}
				if(found) break;
			}
			if(found) break;
		}
		if(found) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
