// A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

long long pole[1111111];

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("vstup.txt", "r", stdin);
	freopen("vystup.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		long long n;
		scanf("%lld", &n);
		vector<bool> zapis;
		/*long long tmp = n;
		while (tmp > 0){
			if (tmp % 2 == 0){ zapis.push_back(false); }
			else{ zapis.push_back(true); }
			tmp /= 2;
		}
		long long best = n;
		tmp = 0;
		for (int i = 0; i < (int)zapis.size(); i++){
			for (int j = i; j >= 0; j--){
				tmp *= 2;
				if (zapis[j]){ tmp++; }
			}
			long long tmp2 = 0;
			for (int j = i + 1; j < zapis.size(); j++){
				tmp *= 2;
				if (zapis[j]){ tmp++; }
			}
			tmp += tmp2;
			best = min(best, tmp);
		}*/
		for (int i = 1; i < n+1; i++){ pole[i] = 2 * n; }
		pole[1] = 1;
		for (int i = 1; i < n; i++){
			pole[i + 1] = min(pole[i] + 1, pole[i+1]);
			long long reverz = 0;
			long long tmp = i;
			while (tmp > 0){
				reverz *= 10;
				reverz += tmp % 10;
				tmp /= 10;
			}
			pole[reverz] = min(pole[reverz], pole[i] + 1);
		}
		printf("Case #%d: %lld\n", t, pole[n]);
	}
	return 0;
}

