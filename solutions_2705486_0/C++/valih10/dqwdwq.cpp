#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cstdio>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;

const int N = 521196;
const int inf = 1000000;

char a[N][15], s[4100];
int len[N], d[4100][6], n;

void sol(int c) {
	cout << "Case #" <<c << ": ";
	int i, j, k, l;
	cin.getline(s, 4100);
	n = strlen(s);
	
	for(i = 0; i < 4100; ++i)
		for(j = 0; j < 6; ++j)
			d[i][j] = inf;
	
	d[0][5] = 0;
	
	for(i = 0; i < n; ++i)
		for(j = 0; j < 6; ++j) if(d[i][j] != inf) {
			
			for(k = 0; k < N; ++k) if(len[k] + i <= n) {
				int pozwrong = -1, vv = 0, nr = 0;
				
				for(l = 0; l < len[k]; ++l)
					if(s[i + l] != a[k][l]) {
						if(pozwrong == -1) {
							if(l + j < 5) {
								vv = 1;
								break;
							}
							pozwrong = l;nr = 1;
						}
						else {
							if(l - pozwrong < 5) {
								vv = 1;
								break;
							}
							pozwrong = l;nr++;
						}
					}
				if(vv)
					continue;
				
				if(pozwrong == -1) {
					d[i + len[k]][min(5, j + len[k])] = min(d[i + len[k]][min(5, j + len[k])], d[i][j]);
				}
				else if(pozwrong + j >= 5) {
					d[i + len[k]][min(5, len[k] - pozwrong)] = min(d[i + len[k]][min(5, len[k] - pozwrong)], d[i][j] + nr);
				}
			}
		}
	
	int rez = inf;
	for(i = 0; i < 6; ++i)
		rez = min(rez, d[n][i]);
	cout << rez << "\n";
}

int main() {
	
	freopen("ttt", "r", stdin);
	freopen("out", "w", stdout);
	
	int t;
	
	ifstream in("t");
	
	for(int i = 0; i < N; ++i) {
		in.getline(a[i], 15);
		len[i] = strlen(a[i]);
	}
	
	cin >> t;
	cin.get();
	
	for(int i = 1; i <= t; ++i)
		sol(i);
	return 0;
}
