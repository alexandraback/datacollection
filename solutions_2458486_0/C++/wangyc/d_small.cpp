#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;

bool f[2000000];
string route[2000000];
map<int, int> key, chest_key[200];
int chest_map[200][200];
int need_key[200], key_lab[200], eff_key[200];
int time, n, K, final_state, k;
ifstream read("d.in");
ofstream write("d.out");

void init(int K, int n)
{
	for (int i = 0; i < n; ++i)
		chest_key[i].clear();
	key.clear();
	memset(f, 0, sizeof(f));
	memset(key_lab, 0xff, sizeof(key_lab));
	memset(chest_map, 0, sizeof(chest_map));
	
	int x, y;
	for (int i = 0; i < K; ++i) {
		read >> x;
		++key[x];
	}
	for (int i = 0; i < n; ++i) {
		read >> need_key[i] >> y;
		eff_key[i] = need_key[i];
		for (; y; --y) {
			read >> x;
			++chest_key[i][x];
		}
	}
	
	sort(eff_key, eff_key + n);
	key_lab[eff_key[0]] = k = 0;
	for (int i = 1; i < n; ++i)
		if (eff_key[i] != eff_key[i - 1]) {
			eff_key[++k] = eff_key[i];
			key_lab[eff_key[k]] = k;
		}
	++k;
		
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < k; ++j)
			chest_map[i][j] = chest_key[i][eff_key[j]];
	
	for (int i = 0; i < n; ++i)
		need_key[i] = key_lab[need_key[i]];
}

void relax(int new_state, string old_route, int chest)
{
	string s(1, '1' + chest);
	string new_route = old_route + s;
	if (!f[new_state]) {
		f[new_state] = 1;
		route[new_state] = new_route;
	}
	else {
		if (new_route < route[new_state])
			route[new_state] = new_route;
	}
}

void dp()
{
	int max = 1 << n;
	f[0] = 1; route[0] = "";
	for (int state = 0; state < max; ++state) 
		if (f[state]) {
			int map[20];
			memset(map, 0, sizeof(map));
			for (int i = 0; i < k; ++i)
				map[i] += key[eff_key[i]];
			for (int i = 0; i < n; ++i)
				if (state & (1 << i)) {
					for (int j = 0; j < k; ++j)
						map[j] += chest_map[i][j];
					--map[need_key[i]];
				}
			for (int i = 0; i < n; ++i)
				if (!(state & (1 << i)) && map[need_key[i]]) {
					relax(state | (1 << i), route[state], i);
				}
		}
}

int main()
{
	read >> time;
	for (int ite = 0; ite < time; ++ite) {
		write << "Case #" << ite + 1 << ": ";
		read >> K >> n;
		final_state = (1 << n) - 1;
		init(K, n);
		dp();
		if (f[final_state]) {
			string s = route[final_state];
			for (int i = 0; i < s.size(); ++i)
				if (s[i] <= '9') write << s[i] << ' ';
				else write << int (s[i] - '0') << ' ';
			write << endl;
		}
		else {
			write << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}
