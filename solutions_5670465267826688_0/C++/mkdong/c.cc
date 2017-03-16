#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int reduceBack(int sum, int l)
{
    if (sum == l) return 1;
    if (sum == -l) return -1;
    if (l == 2) { // left = 'i'
        if (sum == -1) return 2;
        if (sum == 4) return 3;
        if (sum == -3) return 4;

        if (sum == 1) return -2;
        if (sum == -4) return -3;
        if (sum == 3) return -4;
    }
    if (l == 3) {
        if (sum == -4) return 2;
        if (sum == -1) return 3;
        if (sum == 2) return 4;

        if (sum == 4) return -2;
        if (sum == 1) return -3;
        if (sum == -2) return -4;
    }
    if (l == 4) {
        if (sum == 3) return 2;
        if (sum == -2) return 3;
        if (sum == -1) return 4;

        if (sum == -3) return -2;
        if (sum == 2) return -3;
        if (sum == 1) return -4;
    }
    cout << "Error back" << endl;
    cout << l << ' ' << sum << endl;
    exit(-1);
}
int reduceOne(int a, int b)
{
    if (a < 0 && b < 0) {
        a = -a;
        b = -b;
    }
    int neg = 1;
    if (a < 0 || b < 0) neg = -1;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a == 1) return neg * b;
    if (b == 1) return neg * a;
    if (a == b) return -1 * neg;
    if (a == 2) {
        if (b == 3) return 4 * neg;
        if (b == 4) return -3 * neg;
    }
    if (a == 3) {
        if (b == 2) return -4 * neg;
        if (b == 4) return 2 * neg;
    }
    if (a == 4)  {
        if (b == 2) return 3 * neg;
        if (b == 3) return -2 * neg;
    }
    cout << "error one " << endl;
    exit(-1);
}

int toInt(char a)
{
    if (a == 'i') return 2;
    if (a == 'j') return 3;
    if (a == 'k') return 4;
    cout << "error " << endl;
    exit(-1);
}

string ss;
int reduce(int b, int e)
{
    int ret = toInt(ss[b]);
    for (int i=b+1; i<e; ++i) {
        ret = reduceOne(ret, toInt(ss[i]));
    }
    return ret;
    if (ret == 2) return 'i';
    if (ret == 3) return 'j';
    if (ret == 4) return 'k';
    return '0';
}

int main()
{
    int T;
    cin >> T;
    for (int t=0; t<T; ++t) {
        string ans = "NO";
        int l, x;
        string s;
        cin >> l >> x;
        cin >> s;
        ss = "";
        for (int i=0; i<x; ++i) {
            ss += s;
        }
        int n = l * x;
        // [0,i), [i,j), [j,n)
        int tot = reduce(0, n);
        int init = 1;
        int tail = tot;
        for (int i=1; i<n; ++i) {
            init = reduceOne(init, toInt(ss[i-1]));
            tail = reduceBack(tail, toInt(ss[i-1]));
            if (init != toInt('i')) continue;
            int sec = 1;
            int last = tail;
            for (int j=i+1; j<n; ++j) {
                sec = reduceOne(sec, toInt(ss[j-1]));
                last = reduceBack(last, toInt(ss[j-1]));
                if (sec == toInt('j') && last == toInt('k')) {
                    ans = "YES";
                    goto done;
                }
            }
        }
done:
        cout << "Case #" << t+1 << ": " << ans << endl;
    }
    return 0;
}
