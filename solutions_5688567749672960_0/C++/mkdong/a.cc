#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef long long i64;


const int NN = 1000000;
bool ok[NN];
int aa[NN];
int min(int a, int b) { return a < b ? a : b; }
int reverse(int d)
{
    if (d % 10 == 0) return 99999999;
    int aaa[1000];
    int nnn = 0;
    while (d != 0) {
        aaa[nnn++] = d % 10;
        d /= 10;
    }
    int r = 0;
    for (int i=0; i<nnn; ++i) {
        r *= 10;
        r += aaa[i];
    }
    return r;
}
int dfs_chk(int d)
{
    if (ok[d]) return aa[d];
    aa[d] = dfs_chk(d-1) + 1;
    if (reverse(d) < d) {
        aa[d] = min(aa[d],
            dfs_chk(reverse(d)) + 1
            );
    }
    ok[d] = true;
    return aa[d];
}
i64 solve(i64 n);
void check()
{
    for (int i=1; i<NN; ++i) {
        ok[i] = false;
    }
    aa[1] = 1;
    ok[1] = true;
    for (int i=1; i<NN; ++i) {
        dfs_chk(i);
        if (aa[i] != solve(i)) {
            cout << "ERRR" << i <<  endl;
            cout << aa[i] << ';' << solve(i) << endl;
            exit(-1);
        } else {
            cout << i << ":" << aa[i] << endl;
        }
    }
}

//10^e
i64 solve10e(int e)
{
    if (e == 0) return 0;
    if (e == 1) return 10; // 10 counts from 0 to 10
    i64 ret = solve10e(e - 1);
    int n9 = e/2;
    i64 nines = 0;
    for (int i=0; i<n9; ++i) {
        nines *= 10;
        nines += 9;
    }
    ret += nines;
    ret ++;

    n9 = e - e/2;
    nines = 0;
    for (int i=0; i<n9; ++i) {
        nines *= 10;
        nines += 9;
    }
    ret += nines;
    return ret;
}

int is10e(i64 n)
{
    while (n != 0 && n != 1) {
        if (n % 10) return 0;
        n /= 10;
    }
    if (n == 1) return 1;
    cout << "ERERERE" << endl;
    return -1;
}

i64 get10e(int a)
{
    i64 r = 1;
    for (int i=0; i<a; ++i) {
        r *= 10;
    }
    return r;
}

i64 solve(i64 n)
{
    if (n <= 10) return n;
    i64 ret = 0;
    // wei shu
    i64 m = n;
    int weishu = 0;
    int a[100];
    while (m != 0) {
        a[weishu] = m % 10;
        weishu++;
        m /= 10;
    }
    ret = solve10e(weishu-1);
    i64 left = 0;
    i64 right = 0;
    for (int i=0; i<weishu/2; ++i) {
        right *= 10;
        right += a[weishu/2-1-i];
    }
    for (int i=0; i<weishu/2; ++i) {
        left *= 10;
        left += a[weishu - weishu/2 + i];
    }
    //cout << left << ' ' << right << endl;

    if (is10e(n)) {
        return ret;
    }
    if (n % 10 == 0) {
        return 1+solve(n-1);
    } else {
        ret++;
        // 1000000001 -> n
        if (weishu % 2 == 1) {
            // mid
            ret += get10e(weishu / 2) * a[weishu/2];
        }
        if (is10e(left)) {
            return ret + right - 1;
        }
        if (right == 1) {
            return ret + left - 1 + 1;
        }
        ret += left - 1;
        ret++;
        ret += right - 1;
        return ret;
    }
}

int main()
{
    //check();
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        i64 n;
        cin >> n;
        cout << "Case #" << t << ": " << solve(n) << endl;
    }
    return 0;
}
