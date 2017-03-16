#include <iostream>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdlib>

#define mp make_pair
#define pb push_back
#define ppb pop_back
#define X first
#define Y second

using namespace std;

int main(){
	freopen("inputA2.in","r",stdin);
	freopen("outputA2.out","w",stdout);
	int T;
	cin >> T;
	for (int TT = 1; TT <= T; TT++){
		printf("Case #%d: ", TT);
		long long a, b;
		scanf("%I64d/%I64d", &a, &b);
		 //cout << a << " " << b << endl;

		long long aa = a, bb = b;
		while (aa && bb){
			if (aa > bb) aa %= bb; else bb %= aa;
		}

		long long d = aa + bb;

		a /= d;
		b /= d;

		int ans = 41;

		for (int k = 1; k <= 40; k++){
			long long T = (1LL << (40 - k));
			long long ALL = 1LL << 40;
			if (ALL % b != 0){
				continue;
			}

			long long t = ALL / b;
			aa = a * t;
			bb = b * t;
			if (aa >= T){
				ans = k;
				break;
			}
		}

		if (ans == 41) cout << "impossible" << endl; else cout << ans << endl;
	}
    return 0;
}
