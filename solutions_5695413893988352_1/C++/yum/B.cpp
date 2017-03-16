#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<int(b);i++)
typedef long long LL;
typedef pair<int,int> PT;
typedef vector<int> VI;
typedef vector<VI> VVI;
template<typename T> ostream& operator<<(ostream& s, vector<T>& v)
{ s << '{'; FOR(i,0,v.size()) s << (i ? "," : "") << v[i]; return s << '}'; }
template<typename S, typename T> ostream& operator<<(ostream &s, pair<S,T> const& p)
{ return s << '(' << p.first << ',' << p.second << ')'; }

string C, J;
int N, PF;
LL val(string const& s, bool doMax) {
	LL v = 0;
	FOR(n,0,N) {
		v *= 10;
		if (s[n] != '?') v += s[n]-'0';
		else if (doMax) v += 9;
		else v += 0;
	}
	return v;
}

LL bestC, bestJ;
void doIt(string const& C, string const& J) {
	LL cv, jv;
	char lc = PF ? C[PF-1] : '0';
	char lj = PF ? J[PF-1] : '0';
	FOR(x,0,2) FOR (y,0,2) {
		cv = val(C, x);
		jv = val(J, y);
		LL md = abs(cv-jv);
		LL td = abs(bestC-bestJ);
		if (bestC == -1 || md < td || (md==td && cv<bestC) || (md==td && cv==bestC && jv<bestJ)) {
			bestC = cv;
			bestJ = jv;
		}
	}
}

void tryMLP(bool doSwap, bool f) {
	string C2 = C, J2 = J;
	if (doSwap) swap(C2,J2);
	bool mode = true;
	for (int n = PF-1; n >= 0; n--) {
		if (mode) {
			if (C2[n] != '?' && J2[n] != '?') {
			} else if (C2[n] != '?') {
				J2[n] = (C2[n]-'0'+1)%10 + '0';
				if (J2[n] != '0') mode = false;
			} else if (J2[n] == '0') {
				C2[n] = '9';
				J2[n] = '0';
			} else if (J2[n] == '?') {
				C2[n] = f ? '0' : '9';
				J2[n] = f ? '1' : '0';
				if (J2[n] != '0') mode = false;
			} else {
				C2[n] = J2[n]-1;
				mode = false;
			}
		} else if (C2[n] != '?') {
			J2[n]=C2[n];
		} else if (J2[n] != '?') {
			C2[n] = J2[n];
		} else {
			C2[n]=J2[n]='0';
		}
	}
	if (doSwap) swap(C2,J2);
	//cout << "Trying " << C2 << " " << J2 << endl;
	doIt(C2,J2);
}

int main() {
	int TC;
	cin >> TC;
	FOR(tc,1,TC+1) {
		cin >> C >> J;
		N = (int)C.size();
		PF = 0;
		FOR(n,0,N) if (C[n] == J[n] || C[n] == '?' || J[n] == '?') PF++; else break;

		bestC = -1;
		tryMLP(false, true);
		tryMLP(true, true);
		tryMLP(false, false);
		tryMLP(true, false);

		FOR(n,0,PF-1) {
			if (C[n] != '?') J[n]=C[n];
			else if (J[n] != '?') C[n]=J[n];
			else C[n]=J[n]='0';
		}

		char lc = PF ? C[PF-1] : '0';
		char lj = PF ? J[PF-1] : '0';
		if (lc != '?' && lj != '?') doIt(C,J);
		else if (C[PF-1] != '?' && J[PF-1] == '?') {
			FOR(c,max(int('0'),C[PF-1]-1),min('9'+1,C[PF-1]+2)) {
				J[PF-1]=c;
				doIt(C,J);
			}
		} else if (C[PF-1] == '?' && J[PF-1] != '?') {
			FOR(c,max(int('0'),J[PF-1]-1),min('9'+1,J[PF-1]+2)) {
				C[PF-1]=c;
				doIt(C,J);
			}
		} else {
			C[PF-1]=J[PF-1]='0';
			doIt(C,J);
			C[PF-1]='1';
			J[PF-1]='0';
			doIt(C,J);
			C[PF-1]='0';
			J[PF-1]='1';
			doIt(C,J);
		}

		cout << "Case #" << tc << ": " << setw(N) << setfill('0') << bestC << ' ' << setw(N) << bestJ << endl;
	}
}
