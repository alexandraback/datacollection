#include <iostream>
#include <set>
#include <string>
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int tests;
	cin >> tests;
	forn(test, tests){
		int x, y;
		cin >> x >> y;
		string ans = "";
		forn(i, abs(x)){
			if (x > 0){
				ans += 'W';
				ans += 'E';
			}
			else{
				ans += 'E';
				ans += 'W';
			}
		}
		forn(i, abs(y)){
			if (y > 0){
				ans += 'S';
				ans += 'N';
			}
			else{
				ans += 'N';
				ans += 'S';
			}
		}
		printf("Case #%d: %s\n", test + 1, ans.c_str());
	}
	return 0;
}