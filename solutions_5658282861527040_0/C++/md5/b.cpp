#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define fst first
#define snd second
#define pb push_back
#define sz(a) ((int)size(a))

int main() {
    int nbTests;
    scanf("%d", &nbTests);
    
    for (int iTest = 0; iTest < nbTests; iTest++) {
        int limA, limB, limK;
        scanf("%d%d%d", &limA, &limB, &limK);
        int nbGagne = 0;
        
        for (int valA = 0; valA < limA; valA++)
            for (int valB = 0; valB < limB; valB++)
                if ((valA & valB) < limK)
                    nbGagne++;               
        
        printf("Case #%d: %d\n", iTest + 1, nbGagne);
    }
    
    return 0;
}
