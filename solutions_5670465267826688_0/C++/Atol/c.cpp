#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
#define sz(A) (int)(A).size()
#define FOR(A,B) for(int A=0; A < (int) (B);A++)
#define FOREACH(I,C) for(__typeof(C.begin()) I = (C).begin(); I != (C).end(); I++)
#define pb push_back
#define all(x) x.begin() , x.end()
#define mp make_pair

long long n, tam;
string s;
string leva[256][256];

void mapa() {
	leva['1']['1'] = "1";
	leva['1']['i'] = "i";
	leva['1']['j'] = "j";
	leva['1']['k'] = "k";

	leva['i']['1'] = "i";
	leva['i']['i'] = "-1";
	leva['i']['j'] = "k";
	leva['i']['k'] = "-j";

	leva['j']['1'] = "j";
	leva['j']['i'] = "-k";
	leva['j']['j'] = "-1";
	leva['j']['k'] = "i";

	leva['k']['1'] = "k";
	leva['k']['i'] = "j";
	leva['k']['j'] = "-i";
	leva['k']['k'] = "-1";
}

string mult_char(char a, char b) {
	return leva[a][b];
}

string mult(string a, char b) {
	if (a[0] == '-') {
		string aux = mult_char(a[1], b);
		if (aux[0] == '-') {
			return aux.substr(1);
		} else {
			return "-" + aux;
		}
	} else {
		return mult_char(a[0], b);
	}
}

bool solve_brute() {
	string ijk = "";
	FOR(i, n) {
		ijk += s;
	}

	int f = sz(ijk);
	string i = "1", j = "1", k = "1";
	FOR(it, f) {
		if (i != "i") {
			i = mult(i, ijk[it]);
		} else if (j != "j") {
			j = mult(j, ijk[it]);
		} else {
			k = mult(k, ijk[it]);
		}
	}

	return i == "i" && j == "j" && k == "k";
}

void solve() {
	cin >> tam >> n;
	cin >> s;
	mapa();

	if(solve_brute()) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main() {
  int num_testes;
  scanf("%d", &num_testes);
  for(int t = 1; t <= num_testes; t++) {
    printf("Case #%d: ", t);
    solve();
  }
  return 0;
}
