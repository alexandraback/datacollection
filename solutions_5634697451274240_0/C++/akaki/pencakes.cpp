#include <bits/stdc++.h> 

using namespace std;

int i, j, k, l, m, n, t;
string s;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int test = 0; test < t; test++){
		cin >> s;
		cout << "Case #" << test + 1 << ": ";
		n = s.length();
		for (i = n - 1; i >= 0; i--){
			if (s[i] == '-'){
				break;
			} else
			{
				s.erase(s.begin() + i);
			}
		}
		if (s.length() == 0) {
			cout << 0 << "\n";
			continue;
		}
		vector <char> v;
		v.push_back(s[0]);
		for (i = 1; i < s.length(); i++){
			if (s[i] == '+' && s[i - 1] == '-'){
				v.push_back('+');
			} else
			if (s[i] == '-' && s[i - 1] == '+'){
				v.push_back('-');
			}
		}
		cout << v.size() << "\n";
	}
	return 0;
} 