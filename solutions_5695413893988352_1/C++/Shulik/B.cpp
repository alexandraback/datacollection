#include <bits/stdc++.h>
#include <iomanip>

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

int ab(int x){
	return x < 0 ? -x : x;
}

ll abl(ll x){
	return x > 0 ? x : -x;
}

ll to_ll(string s, bool mx, int i = 0, ll ret = 0){
	for(; i < s.size(); i++){
		char x = s[i];
		if(x == '?'){
			x = mx ? '9' : '0';
		}
		ret*=10;
		ret+=(x-'0');
	}
	return ret;
}

ll pw(int e){
	ll ret = 1;
	REP(i, e)ret*=10;
	return ret;
}

bool pos_p(string &s, vector<char> &res, int i){
	if(i < 0)return false;
	if(s[i] != '?')return false;
	if(res[i] > '0')return true;
	return pos_p(s, res, i-1);
}
bool pos_m(string &s, vector<char> &res, int i){
	if(i < 0)return false;
	if(s[i] != '?')return false;
	if(res[i] < '9')return true;
	return pos_m(s, res, i-1);
}

void chng_p(vector<char> &s, int i){
	if(s[i] > '0')s[i]--;
	else{
		s[i] = '9';
		chng_p(s, i-1);
	}
}
void chng_m(vector<char> &s, int i){
	if(s[i] < '9')s[i]++;
	else{
		s[i] = '0';
		chng_m(s, i-1);
	}
}

void testcase(int T){
	vector<char> res[3];
	string s[3];
	cin >> s[0] >> s[1];

	res[0].resize(s[0].size());
	res[1].resize(s[0].size());

	REP(i, s[0].size()){
		res[0][i] = s[0][i];
		res[1][i] = s[1][i];
	}

	int state = 0; // -1 => min res[0]

	REP(i, s[0].size()){
		if(s[0][i] != '?' && s[1][i] != '?'){
			if(s[0][i] == s[1][i])continue;
			if(state == 0){
				if(i == 0 || ab(s[0][i] - s[1][i]) < 5){
					state = s[0][i] < s[1][i] ? 1 : -1;
				} else{
					int sw = 0;
					if(s[0][i] > s[1][i]){
						sw = 1;
					}
					int can = 5;
					if(ab(s[(0+sw) % 2][i] - s[(1+sw) % 2][i]) == 5){
						ll nmn = to_ll(s[(0+sw) % 2], false, i, 1),
						nmx = to_ll(s[(0+sw) % 2], true, i),
						mmn = to_ll(s[(1+sw) % 2], false, i),
						mmx = to_ll(s[(1+sw) % 2], true, i);


						ll aa = abl(nmx - mmn),
						bb = abl(nmn - mmx);
						if(aa == bb){
							can = 0;
						}
						if(aa < bb){
							can = -1;
						}
						if(aa > bb){
							can = 5;
						}
					}
					if(pos_p(s[(1+sw) % 2], res[(1+sw) % 2], i-1) && can >= 0){
						chng_p(res[(1+sw) % 2], i-1);
						state = -1;
					} else if(pos_m(s[(0+sw) % 2], res[(0+sw) % 2], i-1) && ((can > 0))){
						chng_m(res[(0+sw) % 2], i-1);
						state = -1;
					} else{
						state = 1;
					}
					if(sw == 1)state*=-1;
				}
			}
			continue;
		}
		if(s[0][i] == '?' && s[1][i] == '?'){
			if(state == 0)res[0][i] = res[1][i] = '0';
			else if(state == -1){
				res[0][i] = '0';
				res[1][i] = '9';
			} else{
				res[0][i] = '9';
				res[1][i] = '0';
			}
			continue;
		}
		if(state == 0){
			char x = s[0][i];
			if(x == '?')x = s[1][i];
			res[0][i] = res[1][i] = x;
		}
		if(state == -1){
			if(s[0][i] == '?')res[0][i] = '0';
			if(s[1][i] == '?')res[1][i] = '9';
		}
		if(state == 1){
			if(s[0][i] == '?')res[0][i] = '9';
			if(s[1][i] == '?')res[1][i] = '0';
		}
	}
	cout << "Case #" << T << ": " << string(res[0].begin(), res[0].end()) << " " << string(res[1].begin(), res[1].end()) << endl;
}

int main(){
	int T;
	cin >> T;
	REP(i, T)testcase(i+1);


	return 0;
}
