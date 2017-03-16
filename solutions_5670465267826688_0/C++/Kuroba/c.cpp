#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int T, x, l;


string s;
string gg;
int fun(int x, int y){
    int sign = 1;
    if (x<0){
        sign *= -1;
        x *= -1;
    }
    if (y<0){
        sign *= -1;
        y *= -1;
    }
    if (x == 1 || y == 1) return x * y * sign;
    if (x == y) return -1 * sign;
    if (x == 2 && y == 3) return 4 * sign;
    if (x == 3 && y == 2) return -4 * sign;
    if (x == 3 && y == 4) return 2 * sign;
    if (x == 4 && y == 3) return -2 * sign;
    if (x == 4 && y == 2) return 3 * sign;
    if (x == 2 && y == 4) return -3 * sign;

    return 0;
}

int a[100005];


int main(){
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);

    cin >> T;
    for (int i = 1; i<=T; i++){
        printf("Case #%d: ", i);
        cin >> l >> x;
        cin >> gg;
        s = "";
        // Bad Way
        for (int i = 0; i<x; i++) s+=gg;

        //cout << l << " " << x << endl;
        //cout << s << endl;

        // end Bad Way


        l = s.length();

        for (int i =0; i<l; i++){
            if (s[i] == '1') a[i] = 1;
            if (s[i] == 'i') a[i] = 2;
            if (s[i] == 'j') a[i] = 3;
            if (s[i] == 'k') a[i] = 4;
        }

        int tot = 1;
        int run = 1;
        int first_i = -1, last_k = -1;

        //cout << "BEGIN RUN" << endl;
        for (int i=0; i<l; i++){
            tot = fun(tot, a[i]);
            //cout << tot << " ";
        }
        //cout << endl;
        for (int i=0; i<l; i++){
            run = fun(run, a[i]);
            if (run == 2){
                first_i = i;
                break;
            }
        }
        run = 1;
        for (int i = l-1; i>=0; i--){
            run = fun(a[i], run);
            if (run == 4){
                last_k = i;
                break;
            }
        }

        if (tot == -1 && first_i>=0 && last_k>=0 && first_i<last_k-1) cout << "YES" << endl;
        else cout << "NO" << endl;

        // db
        //cout << "FINAL VALS = " << tot << " " << first_i << " " << last_k << endl;

    }

}
