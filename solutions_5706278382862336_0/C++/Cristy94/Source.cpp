#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <conio.h>
#include <cmath>
#define Nmax 256

using namespace std;

long count_bits(long n) {
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

        int nrbits = count_bits(Q);
        
        int sol = 0;

        if (nrbits != 1){
            sol = -1;
        }

        if (sol != -1){
            
            // Find largest 2power in P
            int p = 1;
            while (p * 2 <= P){
                p *= 2;
            }

            Q /= p;
            
            int n = log2(Q);
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