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
#define sol(i) cout << "Case #" << i+1 << ":";;

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

int main(){
	int n, x, a;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> a;
		vector<bool> v(2500, false);
		for (int j = 0; j < 2 * a - 1; ++j){
			for (int z = 0; z < a; ++z){
				cin >> x;
				if (v[x - 1]) v[x - 1] = false;
				else v[x - 1] = true;
			}
		}
		sol(i);
		for (int j = 0; j < v.size(); ++j){
			if (v[j])cout << " " << j+1;
		}
		cout << "\n";
	}
	return 0;
}