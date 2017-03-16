#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <conio.h>
#include <cmath>
#define Nmax 256

using namespace std;

long long count_bits(long long n) {
    unsigned int c; // c accumulates the total bits set in v
    for (c = 0; n; c++)
        n &= n - 1; // clear the least significant bit set
    return c;
}

int T, N;
long long P, Q;

int main(){

    freopen("fis.in", "r", stdin);
	ofstream g("fis.out");

    scanf("%d", &T);

    for(int t = 1; t <= T; ++t){

        scanf("%lld/%lld",&P, &Q);

        // Reducem fractia P,Q

        long long mid = sqrt(P);
        for (int i = 2; i <= mid; ++i){
            while (Q%i == 0 && P%i == 0){
                P /= i;
                Q /= i;
            }
        
        }

        if (Q%P == 0){
            Q /= P;
            P = 1;

        }
        long long nrbits = count_bits(Q);
        
        long long sol = 0;

        if (nrbits != 1){
            sol = -1;
        }

        if (sol != -1){
            
            // Find largest 2power in P
            long long p = 1;
            while (p * 2 <= P){
                p *= 2;
            }

            Q /= p;
            
            long long n = log2(Q);
            sol = n;
        }
        

        g << "Case #" << t << ": ";
        if (sol == -1)
            g << "impossible";
        else g << sol;
		g << '\n';
	}

	return 0;
}