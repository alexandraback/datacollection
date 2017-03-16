#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;

#define For(i, a) for (int i = 0; i < a; ++i)
#define FOR(i, v) for (int i = 0; i < v.size(); ++i)
#define sol(i) cout << "Case #" << i << ": ";

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

int main(){
	int n, k, c, s, sol;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> k >> c >> s;
		sol(i + 1);
		cout << 1;
		for (int j = 1; j < k; ++j){
			cout << " " << j + 1;
		}
		cout << "\n";
	}
	return 0;
}