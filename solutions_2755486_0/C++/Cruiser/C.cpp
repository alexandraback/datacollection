#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <ctime>
#include <queue>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for(int i = a; i < (int)(b); ++i)
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define ll long long

struct attack{
	int day, w, e, strength;
};

bool operator<(const attack& a, const attack& b) {
	return a.day > b.day;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int t;
	cin >> t;
	forn(tt, t){
		int N, n[123], d[123], w[123], e[123], s[123], delp[123], deld[123], dels[123];
		cin >> N;
		priority_queue<attack> q;
		forn(i, N) {
			cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> deld[i] >> delp[i] >> dels[i];
			forn(j, n[i]) {
				attack a;
				a.day = d[i] + j * deld[i];
				a.e = e[i] + j * delp[i];
				a.w = w[i] + j * delp[i];
				a.strength = s[i] + j * dels[i];
				
				q.push(a);
			}
		}
		attack a = {1234567890, 0, 0, 0};
		q.push(a);
		map<int, int> b;
		int day = 0;
		set<pair<pair<int, int>, int> > paint;
		int res = 0;
		while(q.size()) {
			attack a = q.top();
			//printf("att %d %d %d %d\n", a.day, a.w, a.e, a.strength);
			q.pop();
			if (a.day > day) {
				day = a.day;
				
				for(set<pair<pair<int, int>, int > >::iterator i = paint.begin(); i != paint.end(); i++){
					bool fail = 1;
					for(int j = (*i).first.first; j < (*i).first.second; j++) {
						if (!b.count(j))b[j] = 0;
						if (b[j] < (*i).second){
							fail = 0;
							break;
						}
					}
					//printf("att %d->%d is %s\n", (*i).first.first, (*i).first.second, (fail ? "FAILED" : "OK"));
					if (!fail)
						++res;					
				}
				
				for(set<pair<pair<int, int>, int> >::iterator i = paint.begin(); i != paint.end(); i++){
					for(int j = (*i).first.first; j < (*i).first.second; j++) {
						if (b[j] < (*i).second)
							b[j] = (*i).second;
					}
				}

				paint.clear();
			}
			paint.insert(mp(mp(a.w, a.e), a.strength));
		}
		cout << "Case #" << (tt + 1) << ": " << res << endl;
		
	}
	
	return 0;
}