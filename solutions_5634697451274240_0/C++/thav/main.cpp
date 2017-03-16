#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int cas = 1; cas <= t; cas++) {
		string pan;
		cin >> pan;
		int to = pan.size();
		while(to > 0 && pan[to - 1] == '+')
			to--;
		int ans = 0;
		for(int i = 0; i < to; i++) {
			if(i + 1 == to || pan[i] != pan[i + 1])
				ans++;
		}
		cout << "Case #" << cas << ": " << ans << '\n';
	}
}