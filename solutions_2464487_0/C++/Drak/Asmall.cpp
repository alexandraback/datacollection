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
int main() {
    long long int r, ti, p, q;
    double raiz;
    int t;
    scanf("%d", &t);    
    for( int casos=1 ; casos<=t ; casos++ ) {
        cin>>r>>ti;
        p = ( -2LL * r + 1LL );
        q = ( 2LL * r - 1LL ) * ( 2LL * r - 1LL ) + 8LL * ti; 
        //msg(p);msg(q);
        raiz = sqrt( (double)q );
        //msg(raiz);
        cout<<"Case #"<<casos<<": ";
        cout<< (long long int) (((double)p + raiz)/4.0)<<endl;
    }
    return 0;
}
