#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

#define For(i, a) for (int i = 0; i < a; ++i)
#define FOR(i, v) for (int i = 0; i < v.size(); ++i)
#define sol(sol, i) cout << "Case #" << i << ": " << sol << '\n';

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

bool fun(const vb &v){
	For(i, 10){
		if (!v[i])return false;
	}
	return true;
}

int main(){
	int n, num0, aux1;
	lli num, aux;
	cin >> n;
	For (i, n){
		vb v (10, false);
		cin >> num0; num = 0;
		if (!num0) { sol("INSOMNIA", i + 1); }
		else{
			while (!fun(v)){
				num += num0;
				aux = num;
				while(aux){
					aux1 = aux % 10;
					aux /= 10;
					v[aux1] = true;
				}
			}
			sol(num, i + 1);
		}
	}
	return 0;
}