#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#pragma warning(disable : 4996)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

bool was[1000006];
queue <pair <ull, int> > Q;
ull N;

ull revN(ull N) {
	ull tmp = 0;
	while(N > 0) {
		tmp *= 10;
		tmp += N % 10;
		N /= 10;
	}
	return tmp;
}

void Cl() {
	while(!Q.empty())
		Q.pop();
	for(int i = 0; i < 1000006; ++i)
		was[i] = false;
}


int main() {
	freopen("A-small-attempt0 (1).in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin >> T;
	int res = 100000;
	for(int i = 1; i <= T; ++i) {
		cin >> N;
		Cl();
		int res = 100000;
		Q.push(make_pair(1,1));
		was[1] = true;
		while(!Q.empty()) {
			pair <ull, int> pp = Q.front();
			Q.pop();
			if(pp.first == N) {
				res = pp.second;
				break;
			}
			if(!was[pp.first+1]) {
				was[pp.first+1] = true;
				Q.push(make_pair(pp.first+1, pp.second+1));
			}
			if(!was[revN(pp.first)]) {
				was[revN(pp.first)] = true;
				Q.push(make_pair(revN(pp.first), pp.second+1));
			}
		}
		cout << "Case #" << i << ": " << res << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}