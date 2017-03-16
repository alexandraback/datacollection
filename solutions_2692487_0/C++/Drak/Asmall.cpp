#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <list>
#include <bitset>
using namespace std;
#define N 200
#define INF (1<<30)
#define msg(a) cout<<#a<<"="<<a<<endl;
int cal( long long &s, long long x ) {
    int cnt = 0;
    while( s <= x ) {
        s += (s - 1LL);
        cnt++;
    }
    return cnt;
}
int main() {
    long long int v[N], s;
    int t, cnt, pos, minimo, n;
    scanf("%d", &t);
    for( int casos=1 ; casos<=t ; casos++ ) {
        minimo = INF;
        cnt = 0;
        printf("Case #%d: ", casos);
        scanf("%lld %d", &s, &n);
        for( int i=0 ; i<n ; i++ )
            scanf("%lld", &v[i]);
        if( s == 1LL ) printf("%d\n", n);
        else {
            sort(v,v+n);
            pos = 0;
            while( pos < n ) {
                while( pos < n && s > v[pos] ) {
                    s += v[pos];
                    pos++;
                }
                if( cnt + n - pos < minimo ) {
                    minimo = cnt + n - pos;
                }
                if( pos < n ) {
                    cnt += cal(s, v[pos]);
                    s += v[pos];
                    pos++;
                }    
                /*msg(s);
                msg(cnt);
                msg(minimo);*/
            }
            if( cnt < minimo ) minimo = cnt;
            printf("%d\n", minimo);
        }
    }
    return 0;
}
