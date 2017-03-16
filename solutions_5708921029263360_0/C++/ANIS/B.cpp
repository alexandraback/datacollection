#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

#define endl "\n"
#define fr first
#define se second

using namespace std;

int main() { ios::sync_with_stdio(0); cin.tie(0);
	int T, X = 1;
	cin >> T;
	while(T--) {
		int a, b, c, k;
		cin >> a >> b >> c >> k;
		map< pair <int, int> , int> mp1;
		map< pair <int, int> , int> mp2;
		map< pair <int, int> , int> mp3;
		int ans = 0;
		vector < pair < pair <int, int>, int> >  v;
		for(int i=1; i<=a; i++) {
			for(int j=1; j<=b; j++) {
				for(int kk=1; kk<=c; kk++) {
					if( mp1[make_pair(i, j)] < k && mp2[make_pair(i, kk)] < k && mp3[make_pair(j, kk)] < k ) {
						mp1[make_pair(i, j)]++;
						mp2[make_pair(i, kk)]++;
						mp3[make_pair(j, kk)]++;
						v.push_back(make_pair(make_pair(i, j), kk)); // cout << i << " " << j << " " << kk << endl;
						ans++;
					}
				}
			}
		}
		cout << "Case #" << X++ << ": " << ans << endl;
		for(int i=0; i<v.size(); i++) cout << v[i].fr.fr << " " << v[i].fr.se << " " << v[i].se << endl;
	}
	return 0;
}