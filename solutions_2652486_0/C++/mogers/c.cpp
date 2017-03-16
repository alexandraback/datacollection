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
int N, K, M , R, v[100];
char res[100], ok[10000];

void solve() {
    cin >> R >> N >> M >> K;
    int a, b, c, i, j;
    while (R--) {
        for (i = 0; i < K; i++)
            cin >> v[i];
        strcpy(res, "222");
        for (a = 2; a <= M; a++)
            for (b = 2; b <= M; b++)
                for (c = 2; c <= M; c++) {
                    Set(ok, 0);
                    int x[] = {a,b,c};
                    for (i = 0; i < two(N); i++) {
                        int p = 1;
                        for (j = 0; j < N; j++)
                            if (contain(i,j))
                                p *= x[j];
                        ok[p] = 1;
                    }
                    bool valido = true;
                    for (i = 0 ; i < K; i++)
                        if (!ok[v[i]])
                            valido = false;
                    if (valido) {
                        res[0] = '0' + a;
                        res[1] = '0' + b;
                        res[2] = '0' + c;
                    }
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
