#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iomanip>
#include <ctime>
using namespace std;

template <typename T>
T next_int() {  
    T x = 0, p = 1;
    char ch;
    do { ch = getchar(); } while(ch <= ' ');
    if (ch == '-') {
        p = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * p;
}

const int max_n = (int)1e6 + 227 + 1;
const int max_int = (int)1e9 + 227 + 1;

string a;
string b;

string a_kek;
string b_kek;

string a_ans;
string b_ans;

int to_int(string a) {
    int ans = 0;
    for(int i = 0; i < a.size(); i++) {
        ans = ans * 10 + (a[i] - '0');
    }
    return ans;
}

void go(int p) {
    if(p == a.size()) {
        int pr = abs(to_int(a_ans) - to_int(b_ans));
        int next = abs(to_int(a_kek) - to_int(b_kek));
        if(pr > next || (pr == next && a_ans > a_kek) || (pr == next && a_ans == a_kek && b_ans > b_kek)) {
            a_ans = a_kek;
            b_ans = b_kek;
        }
        return;
    }

    if(a[p] == '?' && b[p] == '?') {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                a_kek += (i + '0');
                b_kek += (j + '0');

                go(p + 1);

                a_kek.resize(a_kek.size() - 1);
                b_kek.resize(b_kek.size() - 1);
            }
        }
    } else 
    if(a[p] == '?') {
        for(int i = 0; i < 10; i++) {
            a_kek += (i + '0');
            b_kek += b[p];

            go(p + 1);

            a_kek.resize(a_kek.size() - 1);
            b_kek.resize(b_kek.size() - 1);
        }        
    } else
    if(b[p] == '?') {
        for(int j = 0; j < 10; j++) {
            a_kek += a[p];
            b_kek += (j + '0');

            go(p + 1);

            a_kek.resize(a_kek.size() - 1);
            b_kek.resize(b_kek.size() - 1);
        }        
    } else {
        a_kek += a[p];
        b_kek += b[p];

        go(p + 1);

        a_kek.resize(a_kek.size() - 1);
        b_kek.resize(b_kek.size() - 1);
    }
}

int main() {
    freopen("t.in", "r", stdin);
    freopen("super_t.out", "w", stdout);

    int test = next_int<int>();
    int number = 0;
    while(test--) {
        number++;
        cout << "Case #" << number << ": ";

        cin >> a;
        cin >> b;

        a_ans = a;
        for(int i = 0; i < a_ans.size(); i++) {
            if(a_ans[i] == '?') a_ans[i] = '0';
        }
        b_ans = b;
        for(int i = 0; i < b_ans.size(); i++) {
            if(b_ans[i] == '?') b_ans[i] = '0';
        }

        go(0);

        cout << a_ans << " " << b_ans << "\n";
    }
}