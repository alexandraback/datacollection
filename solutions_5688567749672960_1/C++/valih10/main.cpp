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

    long long t;
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

    cout << d[n] << " ";
    if(n > 100 && d[n] != t) {
        cout << "NNNNNNNNN";
    }
}

void sol() {
    int i;

    nrc = 0;

    t = n;
    int vvv = 0;

    while(t) {
        ++nrc;
        if(t % 10 > 1)
            vvv = 2;
        if(t % 10 == 1)
            ++vvv;
        t /= 10;
    }

    if(n < 10) {
        cout << n << " ";
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

        rez[i]++;
    }

    t = 0;

    for(i = 1; i < nrc; ++i)
        t += rez[i];

    if(vvv < 2) {
        cout << t << " ";
        return;
    }

    int x[20], nr = 0;
    long long tt = n;
    while(tt) {
        x[++nr] = tt % 10;
        tt /= 10;
    }

    long long r1 = 0;
    int r = 0;

    for(i = 1; i <= nr / 2; ++i)
        if(x[i] != 0)
            r = 1;

    if(!r) {

        long long last = t;
        long long pc = 1;
        for(i = 1; i < nrc; ++i)
            pc = pc * 10;

        x[nr / 2 + 1]--;

        for(i = nr / 2 + 1; i <= nr; ++i)
        if(x[i] < 0) {
            x[i]+= 10;
            x[i + 1]--;
        }

        for(i = nr / 2 + 1; i <= nr; ++i)
            r1 = r1 * 10 + x[i];

        t += r1;

        r1 = 0;
        for(i = nr; i; --i)
            r1 = r1 * 10 + x[i];

        t += n - r1;

        long long add = t - last;
        t = last;
        t = min(t + add, t + n - pc);

        cout << t << " ";
        return;
    }

     int vv = 1;
    for(i = nr - 1; i > (nr + 1) / 2; --i)
        if(x[i])
            vv = 0;

    if(x[nr] == 1 && vv)
        --t;

    for(i = nr / 2; i; --i) {
        r1 = r1 * 10 + x[i];
    }
    t += r1;

    r1 = 0;

    for(i = nr / 2 + 1; i <= nr; ++i)
        r1 = r1 * 10 + x[i];
    t += r1;

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

        cin >> n;

            sol();
        //brut();
        cout << "\n";
    }

    return 0;
}
