#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
	string name[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	
	string S;
	vector<int> V(1000, 0);
	cin >> S;
	for(char c : S)
		++V[c];
	
	string ans;
	auto f = [&](int n) {
		for(char c : name[n]){
			--V[c];
			assert(V[c] >= 0);
		}
		ans.push_back(n + '0');
	};
	while(V['G']) f(8);
	while(V['U']) f(4);
	while(V['W']) f(2);
	while(V['X']) f(6);
	while(V['Z']) f(0);
	while(V['F']) f(5);
	while(V['H']) f(3);
	while(V['O']) f(1);
	while(V['S']) f(7);
	while(V['N']) f(9);
	sort(ans.begin(), ans.end());
	printf("Case #%d: %s\n", t, ans.c_str());
}

int main() {	
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t)
		solve(t);
}
