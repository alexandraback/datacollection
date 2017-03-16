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
#ifdef _DEBUG
#define DPF(fmt,...) { printf(fmt,##__VA_ARGS__); fprintf(outf, fmt,##__VA_ARGS__); }
#else
#define DPF(fmt,...) { fprintf(outf, fmt,##__VA_ARGS__); }
#endif
const int MAX_STR = 2000;
#define RI(val) int val = 0; scanf("%d", &val);
#define RIS(val, nn) vector<int> val; { for (int ii = 0; ii < (nn); ii++) { int vval; scanf("%d", &vval); val.push_back(vval); } }
#define RLL(val) LL val = 0; scanf("%lld", &val);
#define RLLS(val, nn) vector<LL> val; { for (int ii = 0; ii < (nn); ii++) { LL vval; scanf("%lld", &vval); val.push_back(vval); } }
#define RD(val) double val = 0.0f; scanf("%lf", &val);
#define RDS(val, nn) vector<double> val; { for (int ii = 0; ii < (nn); ii++) { double vval; scanf("%lf", &vval); val.push_back(vval); } }
#define RC(val) char val = 0; scanf("%c", &val);
#define RS(val) string val; {char str[MAX_STR]; scanf("%s", str); val = str;}
#define RL(val) string val; {char str[MAX_STR]; fgets(str, MAX_STR - 1, stdin); int len = strlen(str); if (str[len - 1] == '\n'){str[len - 1] = '\0';}else{str[len] = '\0';} val = str;}
#define RNL() {char str[MAX_STR]; fgets(str, MAX_STR, stdin);}
#define REP(ii, nn) for (int ii = 0; ii < (nn); ii++)
#define REPS(ii, mm, nn) for (int ii = (mm); ii < (nn); ii++)
#define swap(a, b) {auto t = a; a = b; b = t;}

int val(vector<int>& coins, int coinUseMask)
{
    int coinIndex = 0;;
    int val = 0;
    while (coinUseMask)
    {
        if (coinUseMask & 0x1)
        {
            val += coins[coinIndex];
        }
        coinUseMask >>= 1;
        coinIndex++;
    }
    return val;
}

int main()
{
    FILE* inf = freopen("in.txt", "r", stdin); FILE* outf = fopen("out.txt", "w");
    RI(np); RNL();
    for (int pp = 1; pp <= np; pp++)
    {
#ifndef _DEBUG
        printf("Case #%d\n", pp);
#endif
        DPF("Case #%d: ", pp);
        RI(C); RI(D); RI(V);
        RIS(cs, D);

        int coins[31] = { 0 };
        int need[14] =
        {
            0,
            1, // 1
            1, // 2
            1, // 3
            0,
            1, //5
            0,
            1, //7
            0,
            0,
            0,
            1, // 11
            0,
            1, //13
        };
        int needmax[31] =
        {
            0,
            1,
            2,
            2, //3
            3, //4
            3, //5
            5, //6
            5, //7
            5, //8
            5, //9
            5, //10
            5, //11
            7, //12
            7, //13
            7, //14
            7, //15
            7, //16
            7, //17
            7, //18
            11, //19
            11, //20
            11, //21
            11, //22
            11, //23
            11, //24
            11, //25
            11, //26
            11, //27
            11, //28
            11, //29
            13, //30
        };

        REP(i, D)
        {
            coins[cs[i]] = 1;
        }
        int added = 0;
        REP(i, needmax[V])
        {
            if (need[i] && !coins[i])
            {
                added++;
            }
        }
        DPF("%d\n", added);

    }
    fclose(inf);
    fclose(outf);
    return 0;
}