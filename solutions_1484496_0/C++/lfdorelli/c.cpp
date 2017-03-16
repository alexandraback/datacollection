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

int main (void)
{
	int T;
	cin >> T;
	map<int, vector< vector<int> > > v;

	int m[10000];
	for(int t = 1; t <= T; t++) {
		printf("Case #%d:\n", t);
		int n;
		cin >> n;
		v.clear();
		v[-1] = vector< vector<int> > ();

		for(int i = 0; i < n; i++) cin >> m[i];
		
		map<int, vector<vector<int> > >::iterator it, end;
		
		int proc = 1;
		for(int i = 0; proc && i < n; i++) {
			it = v.end(); it--;

			for(; proc && it != v.begin(); it--) {
			
				vector<int> u = * (it->second.begin());

				u.push_back(m[i]);

				v[m[i]+it->first].push_back(u);
				if(v[m[i]+it->first].size() == 2) {
					proc = 0;
					for(int k = 0; k < 2; k++) {
						for(int y = 0; y < v[m[i]+it->first][k].size(); y++) {
							printf("%d ", v[m[i]+it->first][k][y]);
						}
						printf("\n");
					}
				}
			}

			vector<int> H; 
			H.pb(m[i]);
			if(v.find(m[i]) == v.end())
				v[m[i]] = vector< vector<int> > ();
			v[m[i]].push_back( H );
		}
		if(proc) printf("Impossible\n");
	}
	return 0;
}
