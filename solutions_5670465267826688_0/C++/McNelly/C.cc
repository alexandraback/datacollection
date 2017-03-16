#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define error(x) cerr << x << endl

const int SIZE = 12345;

enum {
    ONE = 1,
    II  = 2,
    JJ  = 3,
    KK  = 4
};

int trans[5][5] = {
    {0, 0,   0,    0,   0},
    {0, ONE, II,   JJ,  KK},
    {0, II,  -ONE, KK, -JJ},
    {0, JJ,  -KK, -ONE, II},
    {0, KK,  JJ,  -II, -ONE}
};

int conv(char c) {
    switch (c) {
        case '1': return ONE;
        case 'i': return II;
        case 'j': return JJ;
        case 'k': return KK;
    }
    return -1;
}

struct Number {
    int sign;
    int value;

    Number() {}
    Number(char c) {
        sign = 1;
        value = conv(c);
    }
    Number(int isign, int ivalue): sign(isign), value(ivalue){}

    Number operator * (const Number& num) {
        int a = num.sign * sign;
        int b = trans[value][num.value];
        if (b < 0) {
            a *= -1;
            b = abs(b);
        }
        return Number{a, b};
    }
};

string _word;
string word;

int L, X;

int main() {
    // freopen("input.txt", "r", stdin);
    int T, cas = 1;
    input(T);
    while (T--) {
        input(L >> X);
        input(_word);
        word = "";
        for (int i = 0; i < X; i++) {
            word += _word;
        }
        
        Number num('1');
        
        bool ii = false;
        bool jj = false;
        bool kk = false;
        
        int n = word.size();
        
        for (int i = 0; i < n; i++) {
            num = num * word[i];
            
            if (num.sign == 1 && num.value == II) {
                ii = true;
            }
            if (ii && num.sign == 1 && num.value == KK) {
                jj = true;
            }
        }
        if (ii && jj && num.sign == -1 && num.value == ONE) {
            kk = true;
        }
        printf("Case #%d: ", cas++);
        puts(kk? "YES": "NO");
    }
    return 0;
}
