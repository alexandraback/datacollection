#include<iostream>
#include<fstream>
#define ll long long
using namespace std;
bool u[10];

void add(int x) {
    while (x) {
        u[x % 10] = true;
        x /= 10;
    }
}

int main(void) {
    int n;
    cin >> n;
    ll x;
    ll c;
    for (int t = 1; t <= n; ++t) {
        cin >> x;
        c = 0;
        for (int i = 0; i < 10; ++i)
            u[i] = false;
        bool f = false;
        for (int i = 0; i < 100; ++i) {
            c += x;
            add(c);
            int tt = 0;
            for (int i = 0; i < 10; ++i)
                if (u[i]) tt++;
            if (tt == 10) {
                cout << "Case #" << t << ": " << c << endl;
                f = true;
                break;
            }
        }
        if (!f) {
                cout << "Case #" << t << ": INSOMNIA" << endl;
        }
    }
}
