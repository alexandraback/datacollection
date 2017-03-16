#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

long long T, x, l;


string s;
string gg;
long long fun(long long x, long long y){
    long long sign = 1;
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

long long a[100005];


int main(){
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);

    cin >> T;
    for (int i = 1; i<=T; i++){
        printf("Case #%d: ", i);
        cin >> l >> x;
        cin >> s;
        gg = s;

        //cout << l << " " << x << endl;
        //cout << s << endl;

        // end Bad Way

        for (long long i =0; i<l; i++){
            if (s[i] == '1') a[i] = 1;
            if (s[i] == 'i') a[i] = 2;
            if (s[i] == 'j') a[i] = 3;
            if (s[i] == 'k') a[i] = 4;
        }

        long long tot = 1;
        bool possible = true;
        long long run = 1;
        long long first_i = -1, last_k = -1;

        //cout << "BEGIN RUN" << endl;
        for (long long i=0; i<l; i++){
            tot = fun(tot, a[i]);
            //cout << tot << " ";
        }

        // Repeat X times
        if (tot==1) possible = false;
        else if (tot==-1 && x%2==0) possible = false;
        else if (tot!=-1 && tot!= 1 && x%4!=2) possible = false;

        //if (possible) cout << "still alive" << endl;
        if (x>=4){
            s = "";
            for (int i = 0; i<4; i++) s+=gg;
        }
        else{
            s = "";
            for (int i = 0; i<x; i++) s+=gg;
        }

        long long totlen = l*x;
        l = s.length();
        for (long long i =0; i<l; i++){
            if (s[i] == '1') a[i] = 1;
            if (s[i] == 'i') a[i] = 2;
            if (s[i] == 'j') a[i] = 3;
            if (s[i] == 'k') a[i] = 4;
        }
        //cout << s << " " << totlen << endl;
        //cout << endl;
        for (long long i=0; i<l; i++){
            run = fun(run, a[i]);
            if (run == 2){
                first_i = i;
                break;
            }
        }


        run = 1;
        long long cnt = 0;
        for (long long i = l-1; i>=0; i--){
            cnt++;
            run = fun(a[i], run);
            if (run == 4){
                last_k = i;
                break;
            }
        }
        last_k = totlen - cnt;

        if (possible && first_i>=0 && last_k>=0 && first_i<last_k-1) cout << "YES" << endl;
        else cout << "NO" << endl;

        // db
        //cout << "FINAL VALS = " << possible << " " << first_i << " " << last_k << endl;

    }

}
