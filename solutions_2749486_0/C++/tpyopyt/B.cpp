#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std;

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int ts, ks, i, x, y;
    cin >> ts;
    for (ks = 0; ks < ts; ks++){
        cin >> x >> y;
        cout << "Case #" << ks + 1 << ": ";
        for (i = 0; i < abs(x); i++){
            if (x > 0)
               cout << "WE";
            else cout << "EW";
        }
        for (i = 0; i < abs(y); i++){
            if (y > 0)
               cout << "SN";
            else cout << "NS";
        }
        cout << endl;
    }
    return 0;
}
