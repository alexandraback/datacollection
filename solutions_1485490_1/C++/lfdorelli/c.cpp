#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>

using namespace std;

typedef long long int LL;
typedef pair<int,int> pii;

#define F first
#define S second
#define pb push_back
#define mp make_pair

map<pair<LL,LL>, LL> pd[101][101];
int toys[101];
int box[101];
LL qt_toys[101];
LL qt_box[101];
int n, m;

// qual ta em i, qual ta em j, quantos usei em i, quantos usei em j
LL solve(int i, int j, LL iconst, LL jconst) {
	if(i == n || j == m) return 0;
	
	map< pair<LL,LL>, LL>::iterator it;
	// Se já calculei
	it = pd[i][j].find( mp(iconst, jconst) );
	if( it != pd[i][j].end() ) {
		return it->second;
	}
	
	LL dansw = 0;
	// Se o tipo bate e eu ainda tenho para usar
	if(box[i] == toys[j]) { 
		
		LL v = min(iconst, jconst);
		dansw =  max( dansw, v+solve(i, j+1, iconst - v, qt_toys[j+1]) );
		dansw =  max( dansw, v+solve(i+1, j, qt_box[i+1], jconst - v) );
	} else {
		dansw = max(dansw, solve(i+1, j, qt_box[i+1], jconst));
		dansw = max(dansw, solve(i, j+1, iconst, qt_toys[j+1]));
	}

	pd[i][j][mp(iconst, jconst)] = dansw;
	return dansw;
}

int main (void)
{
	int T;
	cin >> T;

	for(int t = 0; t < T; t++) {
		cin >> n >> m;
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) pd[i][j].clear();
		
		printf("Case #%d: ", t+1);
		for(int i = 0; i < n; i++) cin >>  qt_box[i] >> box[i]; // >> qt_box[i];
		for(int i = 0; i < m; i++) cin >>  qt_toys[i] >> toys[i];
		cout << solve(0, 0, qt_box[0], qt_toys[0]) << endl;
	}
	return 0;
}
