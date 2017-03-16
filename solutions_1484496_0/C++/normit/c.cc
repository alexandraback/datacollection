#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back

#define REP(i,n) for(int i=0; i < (n); ++i)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

int n;
int su[50];
int check[50];
bool found;

void go(int i, int s1, int s2)
{
	if(found) return;
	if(s1 != 0 && s1 == s2) {
		found = true;
		cout << endl;
		for(int j = 0; j < i; ++j) {
			if(check[j] == 1) cout << su[j] << " ";
		}
		cout << endl;
		for(int j = 0; j < i; ++j) {
			if(check[j] == 2) cout << su[j] << " ";
		}
		cout << endl;
		return;
	}
	else if (i < n){
		check[i] = 0;
		go(i+1, s1, s2);
		check[i] = 1;
		go(i+1, s1+su[i], s2);
		check[i] = 2;
		go(i+1, s1,s2+su[i]);
	}
}

void solve()
{
	
	cin >> n;
	REP(i,n)
		cin >> su[i];

	found = false;
	go(0, 0, 0);
	if(!found) cout << "Impossible" << endl;
}

int main(int argc, char *argv[])
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

