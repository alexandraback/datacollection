/*
 * Author: fatboy_cw
 * Created Time:  2015/4/11 14:33:27
 * File Name: c.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

const int maxn = 10000 + 5;
int t, x, l, n;
char ch[maxn], str[maxn];

struct Qua {
    char ch;
    int sign;
    Qua(char _ch, int _sign) : ch(_ch), sign(_sign) {}
    Qua operator * (const Qua &A) const {
        char rc;
        int rs;
        if(ch == '1') {
            if(A.ch == '1') rc = '1', rs = 1;
            if(A.ch == 'i') rc = 'i', rs = 1;
            if(A.ch == 'j') rc = 'j', rs = 1;
            if(A.ch == 'k') rc = 'k', rs = 1;
        }
        if(ch == 'i') {
            if(A.ch == '1') rc = 'i', rs = 1;
            if(A.ch == 'i') rc = '1', rs = -1;
            if(A.ch == 'j') rc = 'k', rs = 1;
            if(A.ch == 'k') rc = 'j', rs = -1;
        }
        if(ch == 'j') {
            if(A.ch == '1') rc = 'j', rs = 1;
            if(A.ch == 'i') rc = 'k', rs = -1;
            if(A.ch == 'j') rc = '1', rs = -1;
            if(A.ch == 'k') rc = 'i', rs = 1;
        }
        if(ch == 'k') {
            if(A.ch == '1') rc = 'k', rs = 1;
            if(A.ch == 'i') rc = 'j', rs = 1;
            if(A.ch == 'j') rc = 'i', rs = -1;
            if(A.ch == 'k') rc = '1', rs = -1;
        }
        return Qua(rc, sign * rs * A.sign);
    }
    void out() {
        cout << ch << " " << sign << endl;
    }
};

vector<Qua> pre, back;

void get_pre() {
    Qua c = Qua(str[0], 1);
    pre.push_back(c);
    for(int i = 1; i < n; i++) {
        c = c * Qua(str[i], 1);
        pre.push_back(c);
    }
}

void get_back() {
    Qua c = Qua(str[n - 1], 1);
    back.push_back(c);
    for(int i = n - 2; i >= 0; i--) {
        c = Qua(str[i], 1) * c;
        back.push_back(c);
    }
    reverse(back.begin(), back.end());
}

bool possible() {
    get_pre();
    get_back();
    for(int i = 0; i < n - 1; i++) {
        if(pre[i].ch == 'i' && pre[i].sign == 1) {
            Qua q = Qua(str[i + 1], 1);
            for(int j = i + 1; j < n - 1; j++) {
                if(q.ch == 'j' && q.sign == 1 && back[j + 1].ch == 'k' && back[j + 1].sign == 1) {
                    return true;
                }
                q = q * Qua(str[j + 1], 1);
            }
        }
    }
    return false;

}

int ca;

int main() {
    freopen("C.out", "w", stdout);
    scanf("%d", &t);
    while(t--) {
        pre.clear();
        back.clear();
        scanf("%d%d", &x, &l);
        n = x * l;
        scanf("%s", ch);
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < x; j++) {
                str[i * x + j] = ch[j];
            }
        }
        if(possible()) {
            printf("Case #%d: YES\n", ++ca);
        }
        else{
            printf("Case #%d: NO\n", ++ca);
        }
    }
    return 0;
}

