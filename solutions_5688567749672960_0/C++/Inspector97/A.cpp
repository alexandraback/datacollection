#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<string>
#include<sstream>

using namespace std;

#pragma warning(disable : 4996)

int rev(int a) {
	stringstream ss;
	ss<<a;
	string s;
	ss>>s;
	reverse(s.begin(), s.end());
	stringstream sss;
	sss<<s;
	sss>>a;
	return a;
}

vector<long long> c(1000055, 1e18);

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	c[1]=1;
	for (int i = 1; i < 1000005; i++) {
		int t1 = i+1, t2 = rev(i);
		c[t1] = min(c[t1], c[i]+1);
		if (t2 <= 1000005)
			c[t2] = min(c[t2], c[i]+1);
	}
	int T, TT = 0;
	cin >> T;
	while (T-- && ++TT) {
		cout << "Case #" << TT << ": ";
		int n;
		cin >> n;
		cout << c[n] << "\n";
		cerr << TT << endl;
	}
	return 0;
}