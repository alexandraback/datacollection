#include <iostream>
#include <string>
#include <map>
#include <set>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define sz(s) (int)(s).size()
using namespace std;
map<char, char> m;
int d[200][200];
bool canSb(int x, int p){
	int part = x/3;
	for(int a = max(part - 3, 0); a <= min(10, part + 3); a++)
		for(int b = max(part - 3, 0); b <= a; b++)
			for(int c = max(part - 3, 0); c <= b; c++)
				if(a - c == 2 && a >= p && a + b + c == x)
					return true;
	return false;
}
bool canSm(int x, int p){
	int part = x/3;
	for(int a = max(part - 3, 0); a <= min(10, part + 3); a++)
		for(int b = max(part - 3, 0); b <= a; b++)
			for(int c = max(part - 3, 0); c <= b; c++)
				if(a - c == 2 && a < p && a + b + c == x)
					return true;
	return false;
}
bool ncanSb(int x, int p){
	int part = x/3;
	for(int a = max(part - 3, 0); a <= min(10, part + 3); a++)
		for(int b = max(part - 3, 0); b <= a; b++)
			for(int c = max(part - 3, 0); c <= b; c++)
				if(a - c < 2 && a >= p && a + b + c == x)
					return true;
	return false;
}
bool ncanSm(int x, int p){
	int part = x/3;
	for(int a = max(part - 3, 0); a <= min(10, part + 3); a++)
		for(int b = max(part - 3, 0); b <= a; b++)
			for(int c = max(part - 3, 0); c <= b; c++)
				if(a - c < 2 && a < p && a + b + c == x)
					return true;
	return false;
}
int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	forn(step, t){
		int n, s, p;
		cin >> n >> s >> p;
		memset(d, -1, sizeof d);
		forn(i, n){
			int x;
			cin>> x;
			if(i == 0){
				if(canSb(x, p))
					d[i][1] = 1;
				if(canSm(x, p))
					d[i][1] = max(d[i][1], 0);
				if(ncanSb(x, p))
					d[i][0] = max(d[i][0], 1);
				if(ncanSm(x, p))
					d[i][0] = max(d[i][0], 0);
				continue;
			}
			forn(j, s+1){
				if(d[i - 1][j] != -1){ 
					if(canSb(x, p)){
						d[i][j + 1] = max(d[i][j + 1], d[i - 1][j] + 1);		
					}
					if(canSm(x, p)){
						d[i][j + 1] = max(d[i][j + 1], d[i - 1][j]);
					}
					if(ncanSb(x, p)){
						d[i][j] = max(d[i][j], d[i - 1][j] + 1);
					}
					if(ncanSm(x, p)){
						d[i][j] = max(d[i][j], d[i - 1][j]);
					}
				}
			}
			
		}
		if(d[n - 1][s] == -1)
				throw;
			cout << "Case #" << step + 1 << ": " << d[n - 1][s] << endl;
	}
	return 0;
}