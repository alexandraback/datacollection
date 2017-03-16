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

bool lesss(int a, int b)
{
    return b < a;
}

int main()
{
    FILE* inf = freopen("in.txt", "r", stdin); FILE* outf = fopen("out.txt", "w");
    RI(np); RNL();
    for (int pp = 1; pp <= np; pp++)
    {
        DPF("Case #%d: ", pp);
        RI(D);
        vector<int> P;
        REP(i, D)
        {
            RI(Pi);
            P.push_back(Pi);
        }
        sort(P.begin(), P.end(), lesss);

        int splitvalue = P[0] - 1;
        int mintime = P[0];
        while (splitvalue > 1)
        {
            int numsplits = 0;
            REP(i, D)
            {
                if (P[i] <= splitvalue)
                {
                    break;
                }
                numsplits += (P[i] + splitvalue - 1) / splitvalue - 1;
            }

            int timeWithSplits = numsplits + splitvalue;

            if (timeWithSplits < mintime)
            {
                mintime = timeWithSplits;
            }

            splitvalue--;
        }

        DPF("%d\n", mintime);
    }
    fclose(inf);
    fclose(outf);
    return 0;
}