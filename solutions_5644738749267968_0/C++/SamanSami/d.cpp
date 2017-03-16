#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define sz(v) int(v.size())
typedef long long ll;
typedef pair<int,int> pii;

const int MAXn = 1010;
double a[MAXn], b[MAXn];
int n;

int play() {
	set<double> st;
	for(int i = 0; i < n; i++)
		st.insert(b[i]);
	int score = 0;
	for(int i = n-1; i >= 0; i--) {
		set<double>::iterator it = st.lower_bound(a[i]);
		if(it == st.end()) {
			score++;
			st.erase(st.begin());
		} else
			st.erase(it);
	}
	return score;
		
}

int playDayus() {
	int bi = 0;
	for(int i = 0; i < n; i++)
		if(a[i] > b[bi])
			bi++;
	return bi;
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < n; i++)
			cin >> b[i];
		sort(a, a + n);
		sort(b, b + n);
		cout << "Case #" << t << ": " << playDayus() << " " << play() << endl;
	}
	return 0;
}
