#include <bits/stdc++.h>

using namespace std;

const int M[4][4] = {
{1, 2, 3, 4},
{2, -1, 4, -3},
{3, -4, -1, 2},
{4, 3, -2, -1}};

void solve(){
	int l, x;
	scanf("%d%d", &l, &x);
	string t;
	cin >> t;
	string s = "";
	for (int i = 0; i < x; i++)
		s += t;
	int state = 0;
	int cur = 1;
	for (auto c : s){
		int fl = 1;
		if (cur < 0)
			fl = -1;
		cur = abs(cur);
		cur = M[cur - 1][c - 'i' + 1];
		cur *= fl;
		if (state == 0 && cur == 2)
			state = 1;
		if (state == 1 && cur == 4)
			state = 2;
	}
	if (state == 2 && cur == -1){
		puts("YES");
	} else {
		puts("NO");
	}
}

int main(){

	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		printf("Case #%d: ", i + 1);
		solve();
		cerr << "Test #" << i + 1 << " completed\n";
	}

	return 0;
}