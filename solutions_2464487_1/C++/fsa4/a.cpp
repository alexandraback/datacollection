#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <string>
#include <iostream>
#include <algorithm>

#include <vector>
#include <map>
#include <queue>

#define dbg(a) cout << a << endl

using namespace std;
typedef long long ll;
/*
int dig(ll a){
	int re = 0;
	while(a > 0){
		a /= 10;
		re++;
	}

	return re;
}
*/
int main(){

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
/*
	ll sum1 = 0, sum2 = 0;
	int r = 1;

	for(int i = 0; i < 1000; i++){
		sum1 += (r+2*i)*(r+2*i);
		sum2 += (r+2*i+1)*(r+2*i+1);
		cout << i+1 << " -- " << sum2-sum1 << endl;
	}

*/

	int ca;
	scanf("%d", &ca);

	ll ini, fim, mid, resp = -7, temp, r, t;

	for(int caso = 1; caso <= ca; caso++){
		scanf("%lld %lld", &r, &t);
		//cout << r << "     " << t << endl;
		ini = 0;
		fim = 1e9;
		while(ini <= fim){
			mid = (ini+fim)/2;
			if(t / (2*r + 1 + 2*mid) < (mid+1)){
				//cout << " a " <<  dig(2*r + 1 + 2*mid) << " ----- " << mid+1 << endl;
				temp = 3e18;
			}else{
				temp = (2*r + 1 + 2*mid)*(mid+1);
			}
			if(temp <= t){
				ini = mid+1;
				resp = mid;
			}else{
				fim = mid-1;
			}
		}


		printf("Case #%d: %lld\n", caso, resp+1);
	}

	return 0;
}
