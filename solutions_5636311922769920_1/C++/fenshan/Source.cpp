#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;

#define For(i, a) for (int i = 0; i < a; ++i)
#define FOR(i, v) for (int i = 0; i < v.size(); ++i)
#define sol(i) cout << "Case #" << i << ":";

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

int main(){
	int n, k, c, s, compulsory;
	lli x;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> k >> c >> s;
		compulsory = ceil((double)k / c);
		sol(i + 1);
		if (s < compulsory) cout << " IMPOSSIBLE";
		else {
			int cont = 1;
			For(j, compulsory){
				For(z, c){	
					if (z == 0){
						x = cont;
						if (cont < k) ++cont;
					}
					else{
						x = (lli)(x - 1)*k + cont;
						if (cont < k)	++cont;
					}
				}
				cout<< " " << x;
			}
		}
		cout << "\n";
	}
	return 0;
}