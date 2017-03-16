#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	freopen("small.in", "r", stdin);
	freopen("small.txt", "w", stdout);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++){
		cout << "Case #" << tc << ": ";
		int n; string shy;
		cin >> n >> shy;

		int ans = 0;
		int stood = 0;
		for (int level = 0; level < shy.size(); level++){
			int here = shy[level] - '0';
			if (stood < level){
				ans += level - stood;
				stood = level;
			}
			stood += here;
		}
		cout << ans << endl;
	}
}