#include <bits/stdc++.h>

using namespace std;

#define EACH(i,c) for(__typeof((c).begin()) i = (c).begin();i!=(c).end();i++)
#define FOR(i,a,b)  for(int i=(a);i<(b);i++)
#define dbg(e)  cout<<(#e)<<" : "<<e<<endl
#define set(v,i) memset(v,i,sizeof(v))
#define all(x) x.begin(),x.end()
#define sz(x) int((x).size())
#define REP(i,n) FOR(i,0,n)
#define pb  push_back
#define mp make_pair

typedef long long ll;

long long compare(string x, string y) {
	long long a, b;
	istringstream iss1(x), iss2(y);
	iss1 >> a;
	iss2 >> b;
	long long diff = a - b;
	if(diff < 0) diff = -diff;
	return diff;
}

string decrement(string x, int ind, string input) {
	int zero = 1;
	for(int i = ind; i >= 0; i--) {
		if(input[i] != '?') break;
		if(x[i] != '0') {
			zero = 0;
			break;
		}
	}
	if(zero) return x;
	for(int i = ind; i >= 0; i--) {
		if(x[i] == '0') {
			x[i] = '9';
		}
		else {
			x[i]--;
			break;
		}
	}
	return x;
}

string increment(string x, int ind, string input) {
	int nine = 1;
	for(int i = ind; i >= 0; i--) {
		if(input[i] != '?') break;
		if(x[i] != '9') {
			nine = 0;
			break;
		}
	}
	if(nine) return x;
	for(int i = ind; i >= 0; i--) {
		if(x[i] == '9') {
			x[i] = '0';
		}
		else {
			x[i]++;
			break;
		}
	}
	return x;
}

int main() {
	int t;
	cin >> t;
	REP(tt, t) {
		string s1, s2;
		cin >> s1 >> s2;
		string bak1 = s1, bak2 = s2;
		int g1 = 0, g2 = 0;
		string ans1 = "", ans2 = "";
		int flag = 0;
		REP(i,sz(s1)) {
			// do it
			if(s1[i] == '?' && s2[i] == '?') {
				if(g1 == 0 && g2 == 0) {
					ans1 += "0";
					ans2 += "0";
				}
				else if(g1) {
					ans1 += "0";
					ans2 += "9";
				}
				else if(g2) {
					ans1 += "9";
					ans2 += "0";
				}
			}
			else if(s1[i] == '?' && s2[i] != '?') {
				if(g1 == 0 && g2 == 0) {
					ans1 += s2[i];
					ans2 += s2[i];
				}
				else if(g1) {
					ans1 += "0";
					ans2 += s2[i];
				}
				else if(g2) {
					ans1 += "9";
					ans2 += s2[i];
				}
			}
			else if(s1[i] != '?' && s2[i] == '?') {
				if(g1 == 0 && g2 == 0) {
					ans1 += s1[i];
					ans2 += s1[i];
				}
				else if(g1) {
					ans1 += s1[i];
					ans2 += "9";
				}
				else if(g2) {
					ans1 += s1[i];
					ans2 += "0";
				}
			}
			else {
				if(s1[i] > s2[i] && g2 != 1 && !flag) {
					flag = 1;
					g1 = 1;
				}
				if(s1[i] < s2[i] && g1 != 1 && !flag) {
					flag = 1;
					g2 = 1;
				}
				//dbg(g1); dbg(g2);
				
				ans1 += s1[i];
				ans2 += s2[i];

				if(g1) {
					int diff = s1[i] - s2[i];
					if(diff > 10 - diff) {
						string oans1 = ans1, oans2 = ans2;
						string incs2 = increment(ans2, i-1, s2);
						string decs1 = decrement(ans1, i-1, s1);
						ll diff1 = compare(ans1, incs2);
						ll diff2 = compare(decs1, ans2);
						if(diff1 == diff2) {
							if(decs1 < ans1) {
								ans1 = decs1;
							} else if(incs2 < ans2) {
								ans2 = incs2;
							}
						}
						else if(diff1 < diff2) {
							ans2 = incs2;
						}
						else {
							ans1 = decs1;
						}
						if(oans1 != ans1 || oans2 != ans2) {
							g1 = 0; g2 = 1;
						}
					}
				}
				else if(g2) {
					int diff = s2[i] - s1[i];
					if(diff > 10 - diff) {
						string oans1 = ans1, oans2 = ans2;
						string decs2 = decrement(ans2, i-1, s2);
						string incs1 = increment(ans1, i-1, s1);
						ll diff1 = compare(ans1, decs2);
						ll diff2 = compare(incs1, ans2);
						if(diff1 == diff2) {
							if(incs1 < ans1) {
								ans1 = incs1;
							} else if(decs2 < ans2) {
								ans2 = decs2;
							}
						}
						else if(diff1 < diff2) {
							ans2 = decs2;
						}
						else {
							ans1 = incs1;
						}
						if(oans1 != ans1 || oans2 != ans2) {
							g1 = 1;
							g2 = 0;
						}
					}
				}
				

			}
		}

		cout << "Case #" << tt+1 << ": " << ans1 << " " << ans2 << endl;
	}
}


