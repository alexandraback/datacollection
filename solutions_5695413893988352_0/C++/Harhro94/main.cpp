#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <cassert>
#include <map>
#include <string>
#include <iomanip>
#include <set>
#include <queue>
#include <ctime>
#include <vector>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define sz(v) (int)(v).size()
#define mp make_pair
#define all(v) (v).begin(), (v).end()
//typedef long double LD;
typedef long long LL;

const LL INF = 1LL << 61;
const int N = 20;
int n;
char A[N], B[N];
LL pw[30];
string ans;
LL ansd, ansa, ansb;

LL br, ba, bb;

void brute_force(int i, LL a = 0, LL b = 0) {
    if (i == n) {
        LL d = (a >= b ? a-b : b-a);
        if (mp(d, mp(a, b)) < mp(br, mp(ba, bb))) {
            br = d;
            ba = a;
            bb = b;
        }
    }
    else {
        FOR(ca, 10) FOR(cb, 10) {
            if ((A[i] == '0' + ca || A[i] == '?') && (B[i] == '0' + cb || B[i] == '?')) {   
                brute_force(i+1, a*10+ca, b*10+cb);
            }
        }
    }
}

LL get_brute() {
    br = INF;
    brute_force(0);
    return br;
}

char AA[N], BB[N];

void go(int pos, int ty) {
    FOR(i, n) {
        AA[i] = A[i];
        BB[i] = B[i];
    }
    FOR(i, pos) {
        if (AA[i] == '?') AA[i] = BB[i];
        if (BB[i] == '?') BB[i] = AA[i];
        if (AA[i] == '?') AA[i] = BB[i] = '0';
    }
    if (ty == 1) {
        if (AA[pos] == '?' && BB[pos] == '?') {
            AA[pos] = '0';
            BB[pos] = '1';
        }
        else if (AA[pos] == '?') {
            if (BB[pos] == '0') return;
            AA[pos] = BB[pos] - 1;
        }
        else if (BB[pos] == '?') {
            if (AA[pos] == '9') return;
            BB[pos] = AA[pos] + 1;
        }
        for(int i = pos+1; i < n; ++i) {
            if (AA[i] == '?') AA[i] = '9';
            if (BB[i] == '?') BB[i] = '0';
        }
    }
    else {
        if (AA[pos] == '?' && BB[pos] == '?') {
            AA[pos] = '1';
            BB[pos] = '0';
        }
        else if (AA[pos] == '?') {
            if (BB[pos] == '9') return;
            AA[pos] = BB[pos] + 1;
        }
        else if (BB[pos] == '?') {
            if (AA[pos] == '0') return;
            BB[pos] = AA[pos] - 1;
        }
        for(int i = pos+1; i < n; ++i) {
            if (AA[i] == '?') AA[i] = '0';
            if (BB[i] == '?') BB[i] = '9';
        }
    }
    LL a = 0, b = 0;
    FOR(i, n) {
        a = a * 10 + AA[i] - '0';
        b = b * 10 + BB[i] - '0';
    }
    LL d = (a >= b ? a-b : b-a);
    if (mp(d, mp(a, b)) < mp(ansd, mp(ansa, ansb))) {
        ansd = d;
        ansa = a;
        ansb = b;
        ans = string(AA, AA + n) + " " + string(BB, BB + n);
    }
}

void solve() {
    pw[0] = 1;
    for (int i = 1; i < 30; ++i) pw[i] = 10 * pw[i-1];

    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++test) {
        printf("Case #%d: ", test);
        scanf("%s%s", A, B);
        n = strlen(A);

        bool ok = true;
        FOR(i, n) {
            if (A[i] != '?' && B[i] != '?' && A[i] != B[i]) ok = false;
        }
        ans = "9";
        ans[0] += 1;
        ansd = INF;
        if (ok) {
            FOR(i, n) {
                if (A[i] == '?') A[i] = B[i];
                if (B[i] == '?') B[i] = A[i];
                if (A[i] == '?') A[i] = B[i] = '0';
            }
            ans = string(A, A + n) + " " + string(B, B + n);
        }
        else {
            FOR(i, n) {
                if (A[i] == '?' || B[i] == '?') {
                    go(i, 1);
                    go(i, 2);
                }
                else {
                    if (A[i] < B[i]) {
                        go(i, 1);
                        break;
                    }
                    else if (A[i] > B[i]) {
                        go(i, 2);
                        break;
                    }
                }
            }
        }
        /*
        LL br = get_brute();
        string A = "";
        string B = "";
        FOR(i, n) {
            A += '0'+ba % 10;
            ba /= 10;
        }
        FOR(i, n) {
            B += '0'+bb%10;
            bb/=10;
        }
        reverse(all(A));
        reverse(all(B));
        if (A + " " + B != ans) {
            cerr << ::A << " " << ::B << endl;
            cerr << ans << " " << A << endl;
            assert(false);
        }*/
        printf("%s\n", ans.c_str());
    }
}

void testgen() {
    FILE *f = fopen("input.txt", "w");
    srand(time(0));
    fclose(f);
}

int  main(int argc, char* argv[]) {
#ifdef harhro94
    //testgen();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    #define task "estimate"
    //freopen(task".in", "r", stdin);
    //freopen(task".out", "w", stdout);
#endif

    solve();

#ifdef harhro94
    cerr << "\ntime = " << clock() / 1000.0 << endl;
#endif
    return 0;
}