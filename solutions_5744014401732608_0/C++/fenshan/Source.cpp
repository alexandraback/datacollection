#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;

#define For(i, a, b) for (int i = a; i < b; ++i)
#define FOR(i, v) for (int i = 0; i < v.size(); ++i)
#define sol(i) cout << "Case #" << i+1 << ": ";

typedef long long lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

bool ar[50][50];

int main(){
	int n, b;
	lli m;
	cin >> n;
	For(i, 0, n){
		cin >> b >> m;
		sol(i);
		if (m < pow(2, (b - 2))){
			cout << "POSSIBLE\n";
			int aux = m, cont = 1;
			while (aux != 0){
				++cont;
				aux >>= 1;
			}
			For(j, 0, b){
				For(z, 0, b){
					if (j == z - 1 || (z > j && z<cont))ar[j][z] = true;
					else ar[j][z] = false;
				}
			}
			int co = 1;
			while (m!=0){
				if (m % 2)ar[co][cont] = true;
				else ar[co][cont] = false;
				++co;
				m >>= 1;
			}

			For(j, 0, b){
				For(z, 0, b){
					cout << ar[j][z];
				}
				cout << "\n";
			}
		}
		else if (m == pow(2, (b - 2))){
			cout << "POSSIBLE\n";
			For(j, 0, b){
				For(z, 0, b){
					if (z > j)cout << '1';
					else cout << '0';
				}
				cout << "\n";
			}
		}
		else cout << "IMPOSSIBLE\n";		
	}
	return 0;
}