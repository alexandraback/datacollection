#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef long long LL;

struct state {
	LL num, step;
	state(const LL& n, const LL& s) : num(n), step(s) {}
};

bool visited[100000000];

LL flip(LL num) {
	LL res = 0l;
	while (num) {
		res = res * 10 + (num % 10);
		num /= 10;
	}
	return res;
}

LL solve(const LL& obj) {
	queue<state> Q;
	memset(visited, false, sizeof(visited));
	
	Q.push(state(1, 1));
	
	while (!Q.empty()) {
		state s = Q.front();
		Q.pop();
		if (visited[s.num])
			continue;
		if (s.num == obj)
			return s.step;
		visited[s.num] = true;

		LL jmp = flip(s.num);
		if (jmp > s.num && !visited[jmp])
			Q.push(state(jmp, s.step+1));

		if (!visited[s.num+1])
			Q.push(state(s.num+1, s.step+1));
	}

	return obj;
}



int main() {
	int t;
	cin >> t;

	LL sz;
	for (int cs = 1; cs <= t; ++cs) {
		cin >> sz;
		cout << "Case #" << cs <<": " << solve(sz) << endl; 
	}

	return 0;
}