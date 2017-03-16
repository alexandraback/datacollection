#include <bits/stdc++.h>
using namespace std;

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

#define mp make_pair
#define pb push_back
#define put(x) { cout << #x << " = "; cout << (x) << endl; }

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef double db;

const int M = 2e3 + 15;
const int Q = 1e9 + 7;


const int ALP = 300;


string srez(string s, int i, int j) {
    string res;
	for (int k = i; k < j; k++)
		res += s[k];
	return res;
}	

string big(string s) {
	string res;
	for (int i = 0; i < (int)s.size(); i++)
		res += (s[i] == '?') ? '9' : s[i];
	return res;	
}

string small(string s) {
	string res;
	for (int i = 0; i < (int)s.size(); i++)
		res += (s[i] == '?') ? '0' : s[i];
	return res;	
}

ll num(string s) {
	ll res = 0;
	for (int i = 0; i < (int)s.size(); i++)
		res = res * 10 + s[i] - '0';
	return res;
}

bool can(char x, int d) {
	if (x == '?') return true;
	return d + '0' == x;
}

int main(){
    srand(time(NULL));
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int T;
	cin >> T;
	for (int TT = 0; TT < T; TT++) {
		string C, J;
		cin >> C >> J;
		int n = (int)C.size();
		string curpref = "";
		ll rc = -1, rj = -1;
		string prc = "", prj = "";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k =0; k < 10; k++) {
					if (j == k) continue;
					if (!can(C[i], j) || !can(J[i], k)) continue;
					string resC, resJ;
					if (j > k) {
						resC = curpref + (char)(j + '0') + small(srez(C, i + 1, n));
						resJ = curpref + (char)(k + '0') + big(srez(J, i + 1, n));
					} else {
						resC = curpref + (char)(j + '0') + big(srez(C, i + 1, n));
						resJ = curpref + (char)(k + '0') + small(srez(J, i + 1, n));
					}
					ll resC_ = num(resC), resJ_ = num(resJ);
					if ((rc == -1 && rj == -1) || abs(resC_ - resJ_) < abs(rc - rj) || (abs(resC_ - resJ_) == abs(rc - rj) && resC_ < rc) ||(abs(resC_ - resJ_) == abs(rc - rj) && resC_ == rc && resJ_ < rj)) {
						rc = resC_;
						rj = resJ_;
						prc = resC;
						prj = resJ;
					}	
				}
			}
			if (C[i] == '?' && J[i] == '?') 
				curpref += '0';
			else if (C[i] == '?')
				curpref += J[i];
			else if (J[i] == '?')
				curpref += C[i];
			else if (C[i] == J[i])
				curpref += C[i];
			else
				break;	
		}
		if ((int)curpref.size() == n) {
			rc = rj = num(curpref);
			prc = prj = curpref;
		}	
		assert(rc != -1 && rj != -1);
		cout << "Case #" << TT + 1 << ": " << prc << " " << prj << "\n";
		cerr << TT << endl;
	}
		
    return 0;
}   