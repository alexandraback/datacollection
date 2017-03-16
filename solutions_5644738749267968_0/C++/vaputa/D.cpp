#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

double naomi[1 << 10], ken[1 << 10];
int n, T;

int main(){
	cin >> T;
	for (int testcase = 1; testcase <= T; ++testcase){
		int ans1 = 0, ans2 = 0;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> naomi[i];
		for (int i = 0; i < n; ++i)
			cin >> ken[i];
		sort(naomi, naomi + n);
		sort(ken, ken + n);

		int naomiFirst = 0, naomiLast = n -1;
		for (int i = n- 1; i >= 0; --i)
			if (naomi[naomiLast] > ken[i]){
				++ans1;
				--naomiLast;
			}

		int kenFirst = 0, kenLast = n - 1;
		for (int i = n - 1; i >= 0; --i)
			if (ken[kenLast] > naomi[i])
				--kenLast;
			else 
				++ans2;


		cout << "Case #" << testcase << ": " << ans1 << " " << ans2 << endl;
	}
	return 0;
}