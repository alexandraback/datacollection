#include <bits/stdc++.h>

using namespace std;

string operator*(const string& s, unsigned int n) {
    stringstream out;
    while (n--)
        out << s;
    return out.str();
}

bool ks[10005];
char muls[300][300];
bool negs[300][300];


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
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin >> t;
	for (int cnt = 1; cnt <= t; cnt++) {
		cout << "Case #" << cnt << ": ";
		memset(ks,0,sizeof ks);
		int len,num;
		cin >> len >> num;
		string s;
		cin >> s;
		s = s*num;
		// calculate possible Ks.
		char cur = '1';
		bool neg = 0;
		for (int i = s.length()-1; i > 0; i--) {
			char o = s[i];
			if (negs[o][cur])
				neg = !neg;
			cur = muls[o][cur];
			if (cur == 'k' && !neg) {
				ks[i] = true;
			}
		}
		// get at the first i.
		int start = -1;
		cur = '1';
		neg = 0;
		for (int i = 0; i < s.length(); i++) {
			char o = s[i];
			if (negs[cur][o])
				neg = !neg;
			cur = muls[cur][o];
			if (cur == 'i' && !neg) {
				start = i+1;
				break;
			}
		}
		if (start == -1) {
			cout << "NO" << endl;
			continue;
		}
		cur = '1';
		neg = 0;
		bool done = false;
		for (int i = start; i < s.length(); i++) {
			char o = s[i];
			if (negs[cur][o])
				neg = !neg;
			cur = muls[cur][o];
			if (cur == 'j' && !neg && ks[i+1]) {
				cout << "YES" << endl;
				done = true;
				break;
			}
		}
		if (!done)
			cout << "NO" << endl;
	}
	return 0;
}
