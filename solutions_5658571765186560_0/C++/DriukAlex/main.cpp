#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <list>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <valarray>
#include <ctime>
#include <set>
#include <sstream>
#include <stdarg.h>
#include <fstream>

using namespace std;
map<string, map<string, string> > a;

void solve(int t) {
    int x,r,c;
    cin>>x>>r>>c;
    if (x>=7) {
        printf("Case #%d: RICHARD\n", t);
        return;
    }
    if ((r*c)%x != 0) {
        printf("Case #%d: RICHARD\n", t);
        return;
    }
    if (max(r,c) < x) {
        printf("Case #%d: RICHARD\n", t);
        return;
    }
    if (min(r,c) < (x+1)/2) {
        printf("Case #%d: RICHARD\n", t);
        return;
    }
    if (min(r,c)==2 && x==4) {
        printf("Case #%d: RICHARD\n", t);
        return;
    }
    printf("Case #%d: GABRIEL\n", t);
    return;
}

int main(int argc, char** argv) {
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int T;
    cin>>T;
    for (int i=0;i<T;i++)
        solve(i+1);
    return 0;
}