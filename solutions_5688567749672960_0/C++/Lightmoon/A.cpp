#include <bits/stdc++.h>

#define For(i,a,b) for (int i = (a); i <= (b); i++)
#define Ford(i,a,b) for (int i = (a); i >= (b); i--)
#define Rep(i,a) for (int i = 0; i < (a); i++)
#define Repd(i,a) for (int i = (int)(a) - 1; i >=0; i--)
#define PI (acos(0.0) * 2)
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define PII pair<int, int>
#define PIII pair<PII, int>
#define VI vector<int>
#define sz(a) ((int)a.size())
#define oo 1000000000
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(a,u,v) {cout << #a << " = "; For(_,u,v) cout << a[_] << ' '; cout << endl;}
#define MAXN 1000111
#define LL long long

using namespace std;

LL string2int(string s) {
	if (sz(s)==0) return 0;
	LL x;
	istringstream is(s);
	is >> x;
	return x;
}

string int2string(LL x) {
	ostringstream os;
	os << x;
	return os.str();
}

bool needRevert(string s) {
	int n = sz(s);
	if (n==0) return false;
	if (s[0]!='1') return true;
	For(i,1,n-1) if (s[i]!='0') return true;
	return false;
}

LL processHalf(string s, int split) {
	LL res = 0;
	string s1 = s.substr(0, split);
	string s2 = s.substr(split, split+10);
	res += string2int(s2);
	if (needRevert(s1)) {
		s1 = string(s1.rbegin(), s1.rend());
		res += string2int(s1);
	}
	return res;
}
LL process(string s, int n) {
	LL res = 0;
	if (n%2==0) {
		res = processHalf(s, n/2);
	} else {
		res += min(processHalf(s,n/2), processHalf(s,n/2+1));
	}
	return res;
}

LL calc(LL n) {
	if (n<=10) {
		return n;
	}
	LL res = 0;
	if (n%10==0) {
		res++;
		n--;
	}
	string s = int2string(n);
	int m = sz(s);
	LL pow10 = 1;
	string all9 = "9";
	For(i,2,m) {
		res += process(all9, i-1) + 1;
		all9 += '9'; 
	}
	res += process(s, m);
	return res;
}

int main() {
	int ntest;
	cin >> ntest;
	For(test,1,ntest) {
		LL n;
		cin >> n;
		LL result = calc(n);
		cout << "Case #" << test << ": " << result << endl;
	}
}