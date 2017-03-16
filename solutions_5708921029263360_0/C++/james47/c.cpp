/*************************************************************************
    > File Name: c.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sun May  8 18:58:46 2016
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
int T, cas;
int J,P,S,K;

int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d %d", &J, &P, &S, &K);
		ll ans = 0;
		if (K >= 3){
			ans = J * P * S;
		}
		else if (K == 2){
			if (J == 1)
				ans = min(2, P) * min(2, S);
			if (J == 2){
				// ans = min(2, S) * P * J;
				if (P == 2){
					ans = 2 * 2 * 2;
				}
				else{
					ans = 8 + 2;
				}
			}
			if (J == 3){
				// ans = min(2, S) * min(2, P) * min(2, J);
				ans = 8 + 2 * 3;
			}
		}
		else{// K == 1
			ans = J * P;
		}
		printf("Case #%d: %lld\n", ++cas, ans);
	}
	return 0;
}
