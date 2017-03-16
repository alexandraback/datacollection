#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

bool isvowel(char c) {
	return c == 'a' || c == 'u' || c == 'e' || c == 'i' || c== 'o';
}

bool iscons(char c) {
	return !isvowel(c);
}

bool check(string& s, ll start, int end, int n) {
	ll max_c_num = 0;
	bool last_cons = false;
	ll c_num = 0;
	for (ll i = start; i <= end; i++)
		if (isvowel(s[i])) {
			max_c_num = max(max_c_num, c_num);
			last_cons = false;
			c_num = 0;
		}
		else {
			last_cons = true;
			c_num ++;
		}
	max_c_num = max(max_c_num, c_num);
	return max_c_num >= n;
}

void preprocess(string& s, vector<ll>& cons_lens) {
	ll max_c_num = 0;
	bool last_cons = false;
	ll c_num = 0;
	cons_lens.resize(s.size());
	for (ll i = 0; i < s.size(); i++)
		if (isvowel(s[i])) {
			cons_lens[i] = 0;
			last_cons = false;
			c_num = 0;
		}
		else {
			last_cons = true;
			c_num ++;
			cons_lens[i] = c_num;
		}
}

void test(ll num) {
	cout << "Case #" << num << ": ";
	string name;
	ll n;
	cin >> name >> n;
	ll result = 0;
	/*for (ll i = 0; i < name.size(); i++)
		for (ll j = i; j < name.size(); j++)
			if(check(name, i, j, n)) {
				result++;
				cout << name.substr(i, j - i + 1) << endl;
			}*/
	vector<ll> lens;
	preprocess(name, lens);
	ll last_end = 0;
	for (ll i = 0; i < name.length(); i++) {
		if(lens[i] >= n) {
			ll last_start = max(last_end - n + 1, -1ll);
			ll start = i - n + 1;
			ll right = name.length() - i;
			ll left;
			if (last_end >= start)
				left = 1;
			else
				left = start - last_start;
			result += left * right;
			last_end = i;
		}
	}
	cout << result << endl;
}

int main() {
	ll t;
	cin >> t;
	for (ll i = 0; i < t; i++)
		test(i+1);
}
