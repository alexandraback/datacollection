#include<iostream>
#include<algorithm>

using namespace std;

bool check(string s){
	bool v[26] = {};
	char now = 0;
	for (string::iterator it=s.begin() ; it != s.end() ; ++it){
		if (*it != now){
			if (v[*it - 'a'])
				return false;
			v[*it - 'a'] = true;
			now = *it;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	int t, u;
	cin >> t;
	for (u = 1 ; u <= t ; ++u){
		int n, cnt = 0;
		int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		string s[10];
		cin >> n;
		for (int i = 0 ; i < n ; ++i)
			cin >> s[i];
		do {
			string ts;
			for (int i = 0 ; i < n ; ++i)
				ts += s[a[i]];
			if (check(ts))++cnt;

		} while (next_permutation(a, a + n));
		cout << "Case #" << u << ": " << cnt << endl;
	}
	return 0;
}
