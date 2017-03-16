#include <iostream>
#include <stdio.h>

using namespace std;

int x, y;

void read() {
    cin >> x >> y;
}

void solve() {
    if(x > 0) {
        for(int i = 1; i <= x; i ++)
            cout << "WE";
    }
    if(x < 0) {
        x = -x;
        for(int i = 1; i <= x; i ++)
            cout << "EW";
    }

    if(y > 0) {
        for(int i = 1; i <= y; i ++)
            cout << "SN";
    }
    if(y < 0) {
        y = -y;
        for(int i = 1; i <= y; i ++)
            cout << "NS";
    }
    cout << endl;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i ++) {
        printf("Case #%d: ", i);
        read();
        solve();
    }

    return 0;
}
