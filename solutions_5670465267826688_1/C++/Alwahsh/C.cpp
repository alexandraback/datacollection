#include <bits/stdc++.h>

using namespace std;
#define ll long long

string operator*(const string& s, unsigned int n) {
    stringstream out;
    while (n--)
        out << s;
    return out.str();
}

char muls[300][300];
bool negs[300][300];

bool valid(char c, bool neg, ll num) {
	if (c == '1') {
		if (neg && (num % 2 != 0)) {
			return true;
		}
		else
			return false;
	}
	if ((num%4 != 0) && (num%2 == 0))
		return true;
	else
		return false;
}

int main() {
	// why you make me write this Google... Why -_-!
	muls['1']['1'] = '1';
	muls['i']['1'] = 'i';
	muls['j']['1'] = 'j';
	muls['k']['1'] = 'k';
	muls['1']['i'] = 'i';
	muls['i']['i'] = '1';
	muls['j']['i'] = 'k';
	muls['k']['i'] = 'j';
	muls['1']['j'] = 'j';
	muls['i']['j'] = 'k';
	muls['j']['j'] = '1';
	muls['k']['j'] = 'i';
	muls['1']['k'] = 'k';
	muls['i']['k'] = 'j';
	muls['j']['k'] = 'i';
	muls['k']['k'] = '1';
	negs['i']['i'] = 1;
	negs['j']['i'] = 1;
	negs['j']['j'] = 1;
	negs['k']['j'] = 1;
	negs['i']['k'] = 1;
	negs['k']['k'] = 1;
	freopen("C-large.in","r",stdin);
	freopen("output_large.txt","w",stdout);
	int t;
	cin >> t;
	for (int cnt = 1; cnt <= t; cnt++) {
		cout << "Case #" << cnt << ": ";
		ll len,num;
		cin >> len >> num;
		string s,s2;
		cin >> s;
		s2 = s*9;
		char cur = '1';
		bool neg = 0;
		// see if the final thing is equal to -1.
		for (int i = 0; i < s.length(); i++) {
			char o = s[i];
			if (negs[cur][o])
				neg = !neg;
			cur = muls[cur][o];
		}
		if (!valid(cur,neg,num)) {
			cout << "NO" << endl;
			continue;
		}
		cur = '1';
		neg = 0;
		ll ind_k = -1;
		for (int i = s2.length()-1; i >= 0; i--) {
			char o = s2[i];
			if (negs[o][cur])
				neg = !neg;
			cur = muls[o][cur];
			if (cur == 'k' && !neg) {
				ind_k = i;
				break;
			}
		}
		if (ind_k == -1) {
			cout << "NO" << endl;
			continue;
		}
		cur = '1';
		neg = 0;
		ll ind_i = -1;
		for (int i = 0; i < s2.length(); i++) {
			char o = s2[i];
			if (negs[cur][o])
				neg = !neg;
			cur = muls[cur][o];
			if (cur == 'i' && !neg) {
				ind_i = i;
				break;
			}
		}
		if (ind_i == -1) {
			cout << "NO" << endl;
			continue;
		}
		ind_k+= (num*len-s2.length());
		if (ind_k-ind_i <= 1) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
	}
	return 0;
}
