#define OSW2
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
using namespace std;


string str[105];
typedef long long ll;

ll gcd(ll a, ll b) {
    if (0==a) return b;
    return gcd(b%a, a);
}

int main() {
    #ifdef OSW
    freopen("C:\\Users\\Oswww\\Desktop\\in.txt", "r", stdin);
    #endif // OSW
    #ifdef OSW2
    freopen("E:\\ACM\\Google Code Jam 2014\\A.in", "r", stdin);
    freopen("E:\\ACM\\Google Code Jam 2014\\outA.txt", "w", stdout);
    #endif // OSW
    ios::sync_with_stdio(false);



    int T;
    cin >> T;
    int t=0;
    while (T-(t++)) {
        ll a,b;
        char ch;
        cin >> a >> ch >> b;
        //cout << a <<' '<<  b << endl;
        ll g = gcd(a,b);
        a /= g;
        b /= g;

       // b/=a;
        ll p = 1;
        int flag = 0;



        cout << "Case #" << t << ": ";
        int id1 = 0;
        for (int i=1; i<=40; ++i) {
            ll pp = (p<<i);
            if (b==pp) {
                flag = 1;
                id1 = i;
                break;
            }
        }
        if (!flag) cout << "impossible" << endl;
        for (int i=id1; i>=0; --i) {
            ll pp = (p<<i);
            if (a&pp) {
                cout << id1 - i << endl;
                break;
            }
        }

    }
}


