#include<iostream>
#include<iomanip>
#include<queue>
#include<stack>
#include<sstream>
#include<algorithm>
#include<list>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<set>

#define Author "DemoVersion"
#define DBG(x) cout<<#x<<" = "<<x<<";\n"


using namespace std;
int dx[] = { 0,0,-1,1,1,-1,1,-1 };
int dy[] = { 1,-1,0,0,1,1,-1,-1 };
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> veci;
typedef vector<veci> vecveci;
/// Hey yo man, lets do some contest in 5:30 AM!

void solve() {
	int n,j,i;
	cin >> n;
	int arr[2555] = {0};
	int vint;

	for (j = 0;j < 2*n-1;j++) {

		for (i = 0;i < n;i++) {
			cin >> vint;
			arr[vint]++;
		}

	}
	int pr = 0;
	for (i = 0;i < 2555;i++) {
		if (arr[i] % 2 == 1) {
			if (pr)cout << ' ';
			cout << i;
			pr = 1;
		}
	}
}
int main() {
	int n, test, t, i, tmp;
	string inp;
	cin >> t;
	for (test = 1;test <= t;test++) {

		cout << "Case #" << test << ": ";
		solve();
		cout<< endl;
	}
	
	return 0;
}
