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

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for(int i = a; i < (int)(b); ++i)
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define ll long long



int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int t;
	cin >> t;
	forn(tt, t){
		int x, y;
		cin >> x >> y;
		printf("Case #%d: ", tt + 1);
		forn(i, abs(x)) {
			if (x < 0)
				printf("EW");
			else
				printf("WE");
		}
		forn(i, abs(y)) {
			if (y < 0)
				printf("NS");
			else
				printf("SN");
		}
		puts("");
	}
	
	return 0;
}