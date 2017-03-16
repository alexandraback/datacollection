#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <algorithm>
#include <ctime>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
#define DPF(fmt,...) { printf(fmt,##__VA_ARGS__); fprintf(outf, fmt,##__VA_ARGS__); }
const int MAX_STR = 2000;
#define RI(val) int val = 0; scanf("%d", &val);
#define RLL(val) LL val = 0; scanf("%lld", &val);
#define RD(val) double val = 0.0f; scanf("%lf", &val);
#define RS(val) string val; {char str[MAX_STR]; scanf("%s", str); val = str;}
#define RC(val) char val = 0; scanf("%c", &val);
#define RL(val) string val; {char str[MAX_STR]; fgets(str, MAX_STR - 1, stdin); int len = strlen(str); if (str[len - 1] == '\n'){str[len - 1] = '\0';}else{str[len] = '\0';} val = str;}
#define RNL() {char str[MAX_STR]; fgets(str, MAX_STR, stdin);}
#define REP(ii, nn) for (int ii = 0; ii < nn; ii++)
#define REPS(ii, mm, nn) for (int ii = mm; ii < nn; ii++)
#define swap(a, b) {auto t = a; a = b; b = t;}

int main()
{
    FILE* inf = freopen("in.txt", "r", stdin); FILE* outf = fopen("out.txt", "w");
    RI(np); RNL();
    for (int pp = 1; pp <= np; pp++)
    {
        DPF("Case #%d: ", pp);
        RI(X);
        RI(R);
        RI(C);

        int mn = min(R, C);
        int mx = max(R, C);

        if (R * C % X != 0)
        {
            // Can't possibly fix X-ominoes w/o spill.
            DPF("RICHARD\n");
        }
        else if (mx < X)
        {
            // Can't handle the tall piece.
            DPF("RICHARD\n");
        }
        else if (mn < X - 1)
        {
            // Zig-zag pieces are the hardest to deal with, for a 4x2 grid, the 2x2 zig-zag has to have an extra row to be handled.
            // For a 5x3 grid, we need an extra row for the M shaped piece.
            // Same is true for the extension of the for X == 6.  FOr X >= 7, we don't care due to the holes.
            DPF("RICHARD\n");
        }    
        else if (X >= 7)
        {
            // Richard can pick a piece with a hole in it, not possible to win.
            DPF("RICHARD\n");
        }
        else
        {
            DPF("GABRIEL\n");
        }

    }
    fclose(inf);
    fclose(outf);
    return 0;
}