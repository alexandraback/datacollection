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
const int MAX_STR = 100000;
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

        int letter[1000] = {0};
        int count[10] = {0};

        RS(s);
        for (int i = 0; i < (int)s.size(); i++)
        {
            letter[s[i]]++;
        }

        // process Z
        if (letter['Z'] > 0)
        {
            int ct = letter['Z'];
            letter['Z'] -= ct;
            letter['E'] -= ct;
            letter['R'] -= ct;
            letter['O'] -= ct;
            count[0] += ct;
        }
        if (letter['W'] > 0)
        {
            int ct = letter['W'];
            letter['T'] -= ct;
            letter['W'] -= ct;
            letter['O'] -= ct;
            count[2] += ct;
        }
        if (letter['X'] > 0)
        {
            int ct = letter['X'];
            letter['S'] -= ct;
            letter['I'] -= ct;
            letter['X'] -= ct;
            count[6] += ct;
        }
        if (letter['G'] > 0)
        {
            int ct = letter['G'];
            letter['E'] -= ct;
            letter['I'] -= ct;
            letter['G'] -= ct;
            letter['H'] -= ct;
            letter['T'] -= ct;
            count[8] += ct;
        }
        if (letter['S'] > 0)
        {
            int ct = letter['S'];
            letter['S'] -= ct;
            letter['E'] -= ct;
            letter['V'] -= ct;
            letter['E'] -= ct;
            letter['N'] -= ct;
            count[7] += ct;
        }
        if (letter['V'] > 0)
        {
            int ct = letter['V'];
            letter['F'] -= ct;
            letter['I'] -= ct;
            letter['V'] -= ct;
            letter['E'] -= ct;
            count[5] += ct;
        }
        if (letter['T'] > 0)
        {
            int ct = letter['T'];
            letter['T'] -= ct;
            letter['H'] -= ct;
            letter['R'] -= ct;
            letter['E'] -= ct;
            letter['E'] -= ct;
            count[3] += ct;
        }
        if (letter['R'] > 0)
        {
            int ct = letter['R'];
            letter['F'] -= ct;
            letter['O'] -= ct;
            letter['U'] -= ct;
            letter['R'] -= ct;
            count[4] += ct;
        }
        if (letter['O'] > 0)
        {
            int ct = letter['O'];
            letter['O'] -= ct;
            letter['N'] -= ct;
            letter['E'] -= ct;
            count[1] += ct;
        }
        if (letter['I'] > 0)
        {
            int ct = letter['I'];
            letter['N'] -= ct;
            letter['I'] -= ct;
            letter['N'] -= ct;
            letter['E'] -= ct;
            count[9] += ct;
        }
        for (int i = 0; i < 1000; i++)
        {
            _ASSERT(letter[i] == 0);
        }
        for(int i = 0; i < 10; i++)
        {
            for (int j = 0; j < count[i]; j++)
            {
                DPF("%d", i);
            }
        }
        DPF("\n");
    }
    fclose(inf);
    fclose(outf);
    return 0;
}