#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <list>
#include <stack>
using namespace std;
#define PB			push_back
#define ALL(v)			(v).begin() , (v).end()
#define SZ(v)			( (int) v.size() )
#define Set(v,x)		memset(  v , x , sizeof(v))
#define two(n)			( 1 << (n) )
#define contain(S,i)		( (S) & two(i) ) 
#define SQR(v)			( (v) * (v) )
#define ABS(x)			( ( (x) >= 0 ) ? (x) : -(x) )
#define foreach(v,it)		for( typeof((v).begin()) it = (v).begin() ; it != (v).end() ; it++ )
int N, K, M , R, v[100], pool[100], np;
char res[100], ok[20];
const int ITER = 3000;

void solve() {
    cin >> R >> N >> M >> K;
    int a, p, i, j;
    for (i = 0; i < 12; i++) {
        for (j = 2; j <= M; j++)
            pool[np++] = j;
    }
    while (R--) {
        cerr << R << endl;
        for (i = 0; i < K; i++)
            cin >> v[i];
        for (int x = 0 ; x < ITER ; x++) {
            random_shuffle(pool, pool + np);
            Set(ok, 0);
            bool valido = true;
            for (a = 0 ; a < K ; a++) {
                p = v[a];
                for (i = 0 ; i < N; i++) {
                    if ( p % pool[i] == 0)
                        p /= pool[i];
                }
                if (p != 1) {
                    valido = false;
                    break;
                }
            }
            if (valido)
                break;
        }    
        for (j = 0 ; j < N ; j++) {
            res[j] = '0' + pool[j];
        }
        puts(res);
    }
}

int main() {
    int C , nc;

    scanf("%d\n", &C);
    for ( nc = 1 ; nc <= C ; nc++) {
        cout << "Case #" << nc << ":\n";
        solve();
    }	
    return 0;
}
