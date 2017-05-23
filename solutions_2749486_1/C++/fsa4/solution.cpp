#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <string>
#include <iostream>
#include <algorithm>

#include <vector>
#include <map>
#include <set>
#include <queue>

#define dbg(a) cout << a << endl

using namespace std;

typedef long long ll;

string resp;
int mov[5000];

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t;
	long long x, y, n, xy, fora, soma;
	bool norte, leste;
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		printf("Case #%d: ", caso);
		scanf("%lld %lld", &x, &y);
		resp = "";
		memset(mov, 0, sizeof(mov));

		if(x < 0){
			leste = false;
			x = -x;
		}else{
			leste = true;
		}
		if(y < 0){
			norte = false;
			y = -y;
		}else{
			norte = true;
		}
		
		xy = x+y;
		n = (sqrt(8.0*xy + 1) - 1.0)/2.0;
		if((n*(n+1))/2 < xy){
			n++;
		}
		
		soma = (n*(n+1))/2;
		fora = soma - xy;
		fora = fora/2;
		
		mov[fora] = norte ? 4 : 3;
		
		// 1 E
		// 2 W
		// 3 N
		// 4 S
		
		ll eixo = 0;		
		for(ll i = n; i > 0 && eixo < x; i--){
			if(i != fora && eixo+i <= x){
				eixo += i;
				mov[i] = leste ? 1 : 2;
				if(eixo == x){
					break;
				}
			}
		}

		for(ll i = 1; i <= n; i++){
			if(mov[i] == 0){
				mov[i] = norte ? 3 : 4;
			}
		}
		
		for(int i = 1; i <= n; i++){
			if(mov[i] == 1){
				resp += "E";
			}else if(mov[i] == 2){
				resp += "W";
			}else if(mov[i] == 3){
				resp += "N";
			}else{
				resp += "S";
			}
		}

		cout << resp << "\n";
	}

	return 0;
}
