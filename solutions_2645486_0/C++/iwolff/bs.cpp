#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <ctime>
#include <cassert>
#include <sstream>

using namespace std;

#define INF 0x3f3f3f3f
#define ll long long

int n,E,R,v[20];

int go(int x, int rem) {
    if (x == n) return 0;
    
    int p = 0;
    for (int i=0; i<=rem; i++)
        p = max(p, v[x]*i + go(x+1,min(E,rem-i+R)));
    return p;
}

int main() {
    int nt,nteste=1;
    
    cin>>nt;
    while (nt--) {
        cin>>E>>R>>n;
        
        for (int i=0; i<n; i++)
            cin>>v[i];
            
        printf("Case #%d: %d\n",nteste++,go(0,E));
    }
    
	return 0;
}
