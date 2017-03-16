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
#define MAX 110

char sa[MAX], sb[MAX];
int n;
long long nums[1000000];

long long solve() {
    long long a = atoll(sa), b = atoll(sb);
    int sol = 0 , i;
    for (i = 0 ; i < n ; i++)
        if (nums[i] >= a && nums[i] <= b)
            sol++;
    return sol;
}
int aux[100];
inline bool ispal(long long x) {
    int d = 0, i , j;
    do {
        aux[d++] = x % 10;
        x /= 10;
    } while (x);
    for (i = 0 ,j = d-1 ; i < j ; i++, j--)
        if (aux[i] != aux[j])
            return false;
    return true;
}
void preprocess() {
    int lim = 10000000, i;
    long long sq;
    for (i = 1 ; i <= lim ; i++) {
        sq = (long long)i * i;
        if (ispal(i) && ispal(sq)) {
//            printf("%d) %d^2 = %lld\n", n+1, i, sq);
            nums[n++] = sq;
        }
    }
}
int main() {
    int nt, t;
    preprocess();
    scanf("%d", &nt);
    for (t = 1; t <= nt; t++) {
        scanf("%s %s", sa,sb);
        printf("Case #%d: %lld\n", t, solve());
    }
    return 0;
}
