// 
// 
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int A, B, C, k;

struct T { 
    int a, b, c;
    T(int aa, int bb, int cc) : a(aa), b(bb), c(cc) {}

    void print(int type) {
        switch (type) {
            case 0: cout << a << " " << b << " " << c << endl; break;
            case 1: cout << a << " " << c << " " << b << endl; break;
            case 2: cout << b << " " << a << " " << c << endl; break;
            case 3: cout << b << " " << c << " " << a << endl; break;
            case 4: cout << c << " " << a << " " << b << endl; break;
            default: cout << c << " " << b << " " << a << endl; break;

        }
    }
};

int _type(int &a, int &b, int &c) {
    int A = a; int B = b; int C = c;
    if (A <= B && B <= C) {
        return 0;
    }
    if (A <= C && C <= B) {
        a = A; b = C; c = B;
        return 1;
    }
    if (B <= A && A <= C) {
        a = b; b = A; c = c;
        return 2;
    }
    if (B <= C && C <= A) {
        a = B; b = C; c = A;
        return 3;
    }
    if (C <= A && A <= B) {
        a = c; b = A; c = B;
        return 4;
    }
    a = C; b = B; c = A;
    return 5;
}

void solve() {
    cin >> A >> B >> C >> k;
    int type = _type(A, B, C);

    map<int, int> ab, ac, bc, abc;
    vector<T> out;

    for (int c = C; 0 < c; c--) {
        for (int b = B; 0 < b; b--) {
            if (k <= bc[b*100+c]) break;

            for (int a = A; 0 < a; a--) {
                if (k <= ab[a*100+b] || k <= ac[a*100+c]) break;
                if (0 < abc[a*1000+b*100+c]) break;

                ab[a*100+b]++;
                ac[a*100+c]++;
                bc[b*100+c]++;
                abc[a*10000+b*100+c]++;
                out.push_back(T(a, b, c));
            }
        }
    }
    cout << out.size() << endl;
    for (T& t : out) {
        t.print(type);
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}

