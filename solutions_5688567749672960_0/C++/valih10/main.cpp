#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

long long rez[20], d[5001000];

long long n;
int nrc;

long long rev(long long a) {
    long long no = 0;

    while(a) {
        no = no * 10 + a % 10;
        a /= 10;
    }

    return no;
}

void brut() {
    long long i;

    for(i = 1; i <= n; ++i) {
        d[i] = d[i - 1] + 1;
        if(i % 10 == 0)
            continue;

        long long z = rev(i);

        if(z < i)
            d[i] = min(d[i], d[z] + 1);
    }

    cout << d[n];
}

void sol() {
    int i;

    nrc = 0;
    long long t;

    cin >> n;
    t = n;

    while(t) {
        ++nrc;
        t /= 10;
    }

    if(n < 10) {
        cout << n;
        return;
    }

    rez[1] = 10;
    for(i = 2; i <= 14; ++i) {
        int r1 = 0;

        for(int j = 1; j <= i / 2; ++j)
            r1 = r1 * 10 + 9;

        rez[i] = r1;
        if(i & 1)
            rez[i] += r1 * 10 + 9;
        else
            rez[i] += r1;
    }

    t = 0;

    for(i = 1; i < nrc; ++i)
        t += rez[i];

    int x[20], nr = 0;
    long long tt = n;
    while(tt) {
        x[++nr] = tt % 10;
        tt /= 10;
    }

    long long r1 = 0;

    for(i = nr / 2; i; --i) {
        r1 = r1 * 10 + x[i];
    }
    t += r1;

    r1 = 0;

    for(i = nr; i > nr / 2; --i)
        r1 = r1 * 10 + x[i];
    t += r1;

    int vv = 1;
    for(i = nr - 1; i > nr / 2; --i)
        if(x[i])
            vv = 0;

    if(x[nr] == 1 && vv)
        --t;

    cout << t << " ";
}

int main() {
    freopen("ttt", "r", stdin);
    freopen("tttt", "w", stdout);

    int t, a = 0;
    cin >> t;

    while(t--) {
        ++a;
        cout << "Case #" << a << ": ";

        //sol();
        cin >> n;
        brut();
        cout << "\n";
    }

    return 0;
}
