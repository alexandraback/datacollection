//
//  main.cpp
//  Brattleship
//

#include <iostream>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    freopen("A-large.in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    // insert code here...
    int T, pid=1;
    for (cin>>T;T--;) {
        cout << "Case #" << pid++ << ": ";
        int R, C, W;
        cin >> R >> C >> W;
        int res = C / W * R + W - 1;
        if (C % W != 0) res++;
        cout << res << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
