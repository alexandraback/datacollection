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
#define N 
#define INF (1<<30)
#define msg(a) cout<<#a<<"="<<a<<endl;
long long int r, ti;
/*bool eval(long long int n ) {
    if( 2LL * n * n + (2LL*r - 1LL) * n <= ti ) return true;
    return false;
}*/
bool eval(long long int n ) {
    if( n == 0 ) return true;
    if( 2LL * n + 2LL*r - 1LL <= ti/n ) return true;
    return false;
}
long long int f() {
    long long int ini = 0LL, medio, fin = 1000000000LL;
    while( ini <= fin ) {
        medio = ini + ( fin - ini) / 2LL;
        if( eval(medio) )
            ini = medio + 1LL;
        else 
            fin =  medio - 1LL;
    }
    return ini - 1LL;
}
int main() {
    int t;
    scanf("%d", &t);    
    for( int casos=1 ; casos<=t ; casos++ ) {
        cin>>r>>ti;
        cout<<"Case #"<<casos<<": ";
        cout<<f()<<endl;
    }
    return 0;
}
