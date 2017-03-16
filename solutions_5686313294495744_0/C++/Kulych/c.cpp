#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define forn(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)

using namespace std;

int testc;
int main(){
	scanf("%d", &testc);
	for(int tc = 1; tc <= testc; tc++){
		vector<string> prv;
		vector<string> druh;
		int n;
		scanf("%d", &n);
		rep(i,n){
			string s1,s2;
			cin >> s1 >> s2;
			prv.push_back(s1);
			druh.push_back(s2);
		}
		int maxfake = 0;
		for(int i = 0; i<(1<<n);i++){
			int fake = 0;
			set<string> ft;
			set<string> sd;
			for(int j = 0; j < n; j++){
				if((1<<j & i) > 0){
					ft.insert(prv[j]);
					sd.insert(druh[j]);
				}
			}
			bool nejde = false;
			for(int j = 0; j < n && !nejde; j++){
				if((1<<j & i) > 0)
					continue;
				if(ft.count(prv[j]) > 0 && sd.count(druh[j]) > 0)
					fake++;
				else{
					nejde = true;
				}
			}
			if(nejde)
				continue;
			maxfake=max(maxfake,fake);
		}
		printf("Case #%d: %d\n", tc, maxfake);
		
	}
	return 0;
}
