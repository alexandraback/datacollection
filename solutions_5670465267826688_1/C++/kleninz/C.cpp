#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define INF 2e9
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

const int MAXATT = 6;
int a[4][4] = {{'1', 'i', 'j', 'k'}, {'i', '1', 'k', 'j'}, {'j', 'k', '1', 'i'}, {'k', 'j', 'i', '1'}};
int sgn[4][4] = {{1, 1, 1, 1}, {1, -1, 1, -1}, {1, -1, -1, 1}, {1, 1, -1, -1}};
map <char, int> m;
char targ[2] = {'i', 'j'};

char res(char p, char q, int& sign) {
    int A = m[p];
    int B = m[q];
    sign *= sgn[A][B];
    return a[A][B];
}

bool fpow(char x, ll pwr, int sign) {
    char v = x;
    int sv = sign;

    char r = '1';
    int sr = 1;
    /* cout << "VVV " << v << " " << sv  << endl; */
    while (pwr) {
        /* cout << "pwr&1 " << (pwr & 1) << " " << pwr <<  endl; */
        if (pwr & 1) {
            /* cout << "before " << r << " " << sr  << endl; */
            /* cout << "to " << v << " " << sv << endl; */
            r = res(r, v, sr);
            sr *= sv;
            /* cout << "after " << r << " " << sr  << endl; */
        }
        int t = sv;
        v = res(v, v, sv);
        sv *= t;
        pwr /= 2;
        /* cout << "fpow " << r << " " << sr  << endl; */
    }
    /* cout << " > " << sr << " " << r << endl; */
    if (sr == -1 && r == '1') {
        return true;
    } else {
        return false;
    }
}

int main()
{
    int tests;
    cin >> tests;
    m['1'] = 0;
    m['i'] = 1;
    m['j'] = 2;
    m['k'] = 3;
    forn (it, tests) {
        ll l, x;
        cin >> l >> x;
        string s;
        cin >> s;

        char t = '1';
        int sign = 1;
        int ind = 0;
        bool ans = false;
        int att = MAXATT;

        char oneway = '1';
        int onewaysign = 1;
        for (int i = 0; i < l; i++) {
            oneway = res(oneway, s[i], onewaysign);
        }
        /* cout << "one " << oneway << " " << onewaysign << endl; */
        int cnt = 0; 
        while (att && cnt < x) {
            for (int i = 0; i < l; i++) {
                t = res(t, s[i], sign);
                /* cout << ". " << t << " " << sign << endl; */
                if (t == targ[ind] && sign == 1) {
                    if (ind == 1) {
                        ans = true;
                        /* cout << "oK\n"; */
                    } else {
                        ind++;
                        /* cout << "ok\n"; */
                        t = '1';
                        sign = 1;
                        att = MAXATT;
                    }
                }
            }
            cnt++;
            att--;
        }
        if (!fpow(oneway, x, onewaysign)) {
            ans = false;
        }

        cout << "Case #" << it + 1 << ": " << (ans ? "YES" : "NO") << endl;
    }
       
    return 0;
} 
