#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cstdio>
using namespace std;

int k, n, nr[210], nd[22], nrel[22], el[22][210], last[2000000], elast[2000000], vver[2000000];
vector<int> rez;

void init() {
	rez.clear();
	int i, j;
	for(i = 1; i < 22; ++i) {
		for(j = 0; j < 201; ++j)
			el[i][j] = 0;
	}
	for(i = 0; i < 210; ++i)
		nr[i] = 0;
	for(i = 0; i < 2000000; ++i)
		last[i] = -1, vver[i] = -1;
}
int smax;
bool calcd(int conf) {
	int i, key[202], j;
	if(vver[conf] != -1)
		return vver[conf];
	if(conf == (1<<n) - 1)
		return 1;
	for(i = 0; i <= smax; ++i)
		key[i] = nr[i];
	
	for(i = 0; i < n; ++i)
		if(conf & (1<<i)) {
			key[nd[i + 1]]--;
			for(j = 0; j<= smax; ++j)
				key[j] += el[i + 1][j];
		}
		int vv = 0;
	for(i = 0; i < n; ++i)
		if(!(conf & (1<<i)) && key[nd[i + 1]] > 0) {
			int nconf =conf | (1<<i); 
			if(calcd(nconf) && !vv) {
				vv = 1;
				last[conf] = nconf;
				elast[conf] = i;
			}
			
		}
	return (vver[conf] = vv);
}

void sol(int pas) {
	cout << "Case #" << pas << ": ";
	int i, j;
	cin >> k >> n;
	
	init();
	smax = 0;
	for(i = 1; i <= k; ++i) {
		int t;
		cin >> t;
		smax = max(smax, t);
		nr[t]++;
	}
	for(i = 1; i <= n; ++i) {
		cin >> nd[i];
		smax = max(nd[i], smax);
		cin >> nrel[i];
		for(j = 1; j <= nrel[i]; ++j) {
			int t;
			cin >> t;
			smax = max(smax, t);
			el[i][t]++;
		}
	}
	
	calcd(0);
	
	int confc = 0;
	if(last[confc] == -1) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	int nr  = 0;
	while(confc != ((1<<n) - 1)) {
		cout <<elast[confc] + 1;++nr;
		/*if(elast[confc] == elast[last[confc]]) {
			cout << "\n" << elast[confc] << " " << confc << "\n";
			while(1);
		}*/
		confc = last[confc];
		if(confc != ((1<<n) - 1))
			cout << " ";
	}
	if(nr != n) {
		cout << "dasekdedwedwe\n\n";
	}
	
	cout << "\n";
}

int main() {
	
	freopen("ttt", "r", stdin);
	freopen("tttt", "w", stdout);
	
	int t;
	cin >> t;
	for(int i = 1;  i<= t; ++i)
		sol(i);
	
	return 0;
}
