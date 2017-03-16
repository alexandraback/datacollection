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

const string a[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"} ;

int b[26];
bool used[10];

int q[26];

int ans[10];

int main() {
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);

    int number = 0;
    int test = next_int<int>();
    while(test--) {
        string w;
        cin >> w;

        for(int i = 0; i < 26; i++) b[i] = 0;

        for(int i = 0; i < 10; i++) used[i] = 0;

        for(int i = 0; i < w.size(); i++) b[w[i] - 'A']++;

        for(int it = 0; it < 10; it++) {
            for(int j = 0; j < 26; j++) q[j] = 0;

            for(int j = 0; j < 10; j++) {
                if(used[j]) continue;
                for(int k = 0; k < a[j].size(); k++) {
                    int e = 0;
                    for( ; e < k; e++) {
                        if(a[j][e] == a[j][k]) break;
                    }

                    if(e == k) q[a[j][k] - 'A']++;
                }
            }

            for(int j = 0; j < 10; j++) {
                if(used[j]) continue;
                bool ok = 0;

                for(int k = 0; !ok && k < a[j].size(); k++) {
                    if(q[a[j][k] - 'A'] == 1) {
                        used[j] = 1;

                        int e = 0;
                        for(int f = 0; f < a[j].size(); f++) e += (a[j][k] == a[j][f]);

                        ans[j] = b[a[j][k] - 'A'] / e;
                        ok = 1;
                    }
                }

                if(!ok) continue;

                for(int k = 0; k < a[j].size(); k++) {
                    b[a[j][k] - 'A'] -= ans[j];
                }

            }
        }

        number++;
        cout << "Case #" << number << ": ";
        for(int i = 0; i < 10; i++) {
            while(ans[i]--) cout << i;
        }
        puts("");
    }
}