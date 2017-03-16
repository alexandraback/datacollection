#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <numeric>
#include <array>
#include <map>
#include <unordered_map>
#include <functional>
#include <iostream>
#include <thread>
#include <sstream>
#include <atomic>

using namespace std;


long long nwd(long long a, long long b){
    while (a) swap(b%=a, a);
    return b;
}




int main () {
	int T;
	scanf("%d", &T);
    char S[100];
    gets(S);
	for (int t=1; t<=T; t++) {
        long long P, Q;
        char S[100];
        gets(S);
        for (char* s=S; *s; s++) if (*s=='/') *s=' ';
        sscanf(S, "%lld%lld", &P, &Q);
        long long d=nwd(P, Q);
        P/=d; Q/=d;
        while (Q<(1LL << 40)) {
            Q*=2;
            P*=2;
        }
        if ((Q!=(1LL << 40)) || Q<P) {
            printf("Case #%d: impossible\n", t);
        }
        else {
            int res=41;
            while (P) {
                res--;
                P/=2;
            }



            printf("Case #%d: %d\n", t, res);
        }
	}
	return 0;
}

