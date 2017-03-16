#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define frl(a, b, c) for( (a) = (b);( a) < (c); (a++))
#define fru(a, b, c) for( (a) = (b); (a) <= (c); (a++))
#define frd(a, b, c) for( (a) = (b); (a) >= (c); (a--))
#define mst(a, b) memset(a, b, sizeof(a))
#define si(a) scanf("%d", &a)
#define ss(a) scanf("%s", a)
#define sc(a) scanf("%c", &a)

#define nwl puts("");

#define vi vector <int>
#define vs vector <string>
#define ll long long int
#define dec int i = 0, j= 0, k = 0;

#define pau system("pause");

ll arr[1000];
int main()
{
    int t;

    ll p, q;
    string str;
    int a;
    dec;
    arr[0] = 1LL;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> t;
    for(a = 1; a <= t; a++){
        char ch;
        cin >> p >> ch >> q;
        ll gcd = __gcd(p, q);
        p /= gcd;
        q /= gcd;
//        cout << p << " " <<  q << endl;
        if((q & (q-1)) == 0) {
            if(p/q > 1LL){
//                cout << " here1\n";
                cout << "Case #" << a << ": " << 1 << endl;
            } else {
//                cout << " here2\n";
//                cout << log2(p) << endl;
                if(p > 1){
                    ll ans11 = log2(p);
                    q /= ans11;
                }
//                cout << q << endl;
                cout << "Case #" << a << ": " << ((ll)(log2(q))) << endl;
            }
        } else {
            cout << "Case #" << a << ": " << "impossible\n";
        }
    }
}











