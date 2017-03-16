#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;
typedef int var;

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    var t, r, c, w, rez;
    cin>>t;
    for(var tt=1; tt<=t; tt++) {
        cin>>r>>c>>w;

        rez = c/w + w;

        if(c % w == 0)
            rez --;

        printf("Case #%d: %d\n", tt, rez);
    }

    return 0;
}
