/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define MOD				1000000007
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 				printf("\n")
ll pow_mod(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
int main() {
	int t;
	cin >> t;
	for(int tcase = 1; tcase <= t; ++tcase) {
		string coder, jammer;
		cin >> coder >> jammer;
		int len1 = coder.length();
		int len2 = jammer.length();
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < len1; ++i) {
			if(coder[i] == '?') {
				cnt1 += 1;
			}
		}
		for(int i = 0; i < len2; ++i) {
			if(jammer[i] == '?') {
				cnt2 += 1;
			}
		}
		vector < int > coder_v;
		vector < string > v1;
		vector < int > jammer_v;
		vector < string > v2;
		if(cnt1 == 0) {
			int tmp = 0; 
			for(int i = 0; i < len1; ++i) {
				tmp = tmp * 10 + (coder[i] - '0');
			}
			coder_v.push_back(tmp);
			v1.push_back(coder);
		} else if(cnt1 == 1) {
			for(int i = 0; i < 10; ++i) {
				int tmp = 0;
				string tmp_str = "";
				for(int j = 0; j < len1; ++j) {
					if(coder[j] == '?') {
						tmp = tmp * 10 + i;
						tmp_str = tmp_str + (char)(i + '0');
					} else {
						tmp = tmp * 10 + (coder[j] - '0');
						tmp_str = tmp_str + coder[j];
					}
				}
				coder_v.push_back(tmp);
				v1.push_back(tmp_str);
			}
		} else if(cnt1 == 2) {
			for(int i = 0; i < 10; ++i) {
				for(int j = 0; j < 10; ++j) {
					int tmp = 0;
					string tmp_str = "";
					bool first = true;
					for(int k = 0; k < len1; ++k) {
						if(coder[k] == '?' && first) {
							tmp = tmp * 10 + i;
							first = false;
							tmp_str = tmp_str + (char)(i + '0');
						} else if(coder[k] == '?') {
							tmp = tmp * 10 + j;
							tmp_str = tmp_str + (char)(j + '0');
						} else {
							tmp = tmp * 10 + (coder[k] - '0');
							tmp_str = tmp_str + coder[k];
						}
					}
					coder_v.push_back(tmp);
					v1.push_back(tmp_str);
				}
			}
		} else {
			for(int i = 0; i < 10; ++i) {
				for(int j = 0; j < 10; ++j) {
					for(int k = 0; k < 10; ++k) {
						int tmp = 100 * i + 10 * j + k;
						string tmp_str = "";
						tmp_str = tmp_str + (char)(i + '0');
						tmp_str = tmp_str + (char)(j + '0');
						tmp_str = tmp_str + (char)(k + '0');
						coder_v.push_back(tmp);
						v1.push_back(tmp_str);
					}
				}
			}
		}
		if(cnt2 == 0) {
			int tmp = 0; 
			for(int i = 0; i < len2; ++i) {
				tmp = tmp * 10 + (jammer[i] - '0');
			}
			jammer_v.push_back(tmp);
			v2.push_back(jammer);
		} else if(cnt2 == 1) {
			for(int i = 0; i < 10; ++i) {
				int tmp = 0;
				string tmp_str = "";
				for(int j = 0; j < len2; ++j) {
					if(jammer[j] == '?') {
						tmp = tmp * 10 + i;
						tmp_str = tmp_str + (char)(i + '0');
					} else {
						tmp = tmp * 10 + (jammer[j] - '0');
						tmp_str = tmp_str + jammer[j];
					}
				}
				jammer_v.push_back(tmp);
				v2.push_back(tmp_str);
			}
		} else if(cnt2 == 2) {
			for(int i = 0; i < 10; ++i) {
				for(int j = 0; j < 10; ++j) {
					int tmp = 0;
					bool first = true;
					string tmp_str = "";
					for(int k = 0; k < len2; ++k) {
						if(jammer[k] == '?' && first) {
							tmp = tmp * 10 + i;
							first = false;
							tmp_str = tmp_str + (char)(i + '0');
						} else if(jammer[k] == '?') {
							tmp = tmp * 10 + j;
							tmp_str = tmp_str + (char)(j + '0');
						} else {
							tmp = tmp * 10 + (jammer[k] - '0');
							tmp_str = tmp_str + jammer[k];
						}
					}
					jammer_v.push_back(tmp);
					v2.push_back(tmp_str);
				}
			}
		} else {
			for(int i = 0; i < 10; ++i) {
				for(int j = 0; j < 10; ++j) {
					for(int k = 0; k < 10; ++k) {
						int tmp = 100 * i + 10 * j + k;
						string tmp_str = "";
						tmp_str = tmp_str + (char)(i + '0');
						tmp_str = tmp_str + (char)(j + '0');
						tmp_str = tmp_str + (char)(k + '0');
						jammer_v.push_back(tmp);
						v2.push_back(tmp_str);
					}
				}
			}
		}
		int res = INT_MAX;
		int coder_val = INT_MAX;
		int jammer_val = INT_MAX;
		int idx1, idx2;
		for(int i = 0; i < (int)(coder_v.size()); ++i) {
			for(int j = 0; j < (int)(jammer_v.size()); ++j) {
				// cout << coder_v[i] << " " << jammer_v[j] << endl;
				if(res > abs(coder_v[i] - jammer_v[j])) {
					res = abs(coder_v[i] - jammer_v[j]);
					coder_val = coder_v[i];
					jammer_val = jammer_v[j];
					idx1 = i;
					idx2 = j;
				} else if(res == abs(coder_v[i] - jammer_v[j])) {
					if(coder_val > coder_v[i]) {
						coder_val = coder_v[i];
						idx1 = i;
					} else if(jammer_val > jammer_v[j]) {
						jammer_val = jammer_v[j];
						idx2 = j;
					}
				}
			}
		}
		cout << "Case #" << tcase << ": " << v1[idx1] << " " << v2[idx2] << endl;
	}
	return 0;
}