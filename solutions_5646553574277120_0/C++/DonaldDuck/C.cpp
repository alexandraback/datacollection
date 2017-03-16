// Problem C-small

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

int C, D, V;
int d[10];

void solve() {
	cin >> C >> D >> V;
	assert(C == 1);
	
	for (int i=0; i<D; i++) cin >> d[i];
	
	bool ok[40];
	for (int i=0; i<40; i++) ok[i] = false;
	
	int res = 0;
	
	for (int i=0; i<(int)pow(2, D); i++) {
		int x = i;
		int sum = 0;
		for (int j=0; j<D; j++) {
			sum += (x%2)*d[j];
			x = x/2;
		}
		
		if (sum<=V) ok[sum] = true;
	}
	
	for (int i=1; i<=V; i++)
		if (!ok[i]) {
			res++;
			vector<int> update;
			for (int j=0; j<=V; j++) 
				if (ok[j] && j+i<=V )
					update.pb(i+j);
			while (!update.empty()) {
				ok[update[update.size()-1]] = true;
				update.pop_back();
			}
		}
	
	cout << res << endl;
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

