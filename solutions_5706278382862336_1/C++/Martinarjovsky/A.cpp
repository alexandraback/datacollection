#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <sstream>
using namespace std;

ifstream fin ("A.in");
ofstream fout ("A.out");
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define abs(x) ((x)<0 ? -(x) : (x))

ll gcd (ll a, ll b) {
	ll t;
	while (!(b == 0)) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

bool check(ll Q) {
	ll pow = 0;
	while (Q % 2 == 0) {
		Q /= 2;
		pow++;
	}
	if (Q > 1) return false;
	if (pow > 40) return false;
	return true;
}

ll getrue (ll P, ll Q) {
	ll copQ = Q;
	ll pow = 0;
	while (copQ % 2 == 0) {
		copQ /= 2;
		pow++;
	}
	while (pow < 40) {
		P *= 2;
		pow++;
	}
	return P;
}

ll getans(ll P) {
	ll n = 0;
	while (P > 1) {
		P /= 2;
		n++;
	}
	return 40 - n;
}

int main() {
	ll T, P, Q, c, i;
	string S, A, B;
	fin >> T;
	for (c = 1; c <= T; c++) {
		fin >> S;
		A = "";
		B = "";
		for (i = 0; i < sz(S); i++) {
			if (S[i] != '/') {
				A += S[i];
			}
			else break;
		}
		for (i = i + 1; i < sz(S); i++) {
			B += S[i];
		}
		stringstream(A) >> P;
		stringstream(B) >> Q;
		ll temp = gcd(P,Q);
		P /= temp;
		Q /= temp;
		if (!check(Q)) {
			fout << "Case #" << c << ": impossible" << endl;
			continue;
		}
		ll trueP = getrue(P, Q);
		fout << "Case #" << c <<": " << getans(trueP) << endl;
	}
	return 0;
}
