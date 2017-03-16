// Problem B-small

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
#include <string.h>
#include <map>
#include <queue>
#include <stack>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<ii> vii;

int K, L, S;
char target[10];
char str[10];

void solve() {
	cin >> K >> L >> S;
	cin >> str >> target;
	
	int maxb = 0;
	ll tot = 0;
	int p = (int)pow(K, S);
	
	for (int i=0; i<p; i++) {
		int x = i;
		char prova[10];
		for (int j=0; j<S; j++) {
			prova[j] = str[x%K];
			x = x/K;
		}
		
		int occ = 0;
		for (int j=0; j<S-L+1; j++) {
			int ok = true;
			for (int k=j; k<j+L; k++)
				if (prova[k] != target[k-j])
					ok = false;
			if (ok) occ++;
		}
		
		maxb = max(maxb, occ);
		tot += occ;
	}
	
	double expval = (double)maxb - (tot*1.0/p);
	cout << setprecision(15) << expval << endl;
}

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
	
	return 0;
}
