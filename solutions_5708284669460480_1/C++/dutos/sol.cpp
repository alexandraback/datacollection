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

bool canspell(string& word, string& letters)
{
    REP(i, word.size())
    {
        bool found = false;
        REP(j, letters.size())
        {
            if (letters[j] == word[i])
            {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
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

        RI(K); RI(L); RI(S); RNL();
        RS(letters);
        RS(word);

        double perc[26] = { 0.0 };
        REP(i, K)
        {
            perc[letters[i] - 'A'] += 1.0;
        }
        REP(i, 26)
        {
            perc[i] /= (double)K;
        }

        // determine max number of words he could type
        int overlapindex = L;
        REPS(j, 1, L)
        {
            bool overlap = true;
            REP(i, L - j)
            {
                if (word[i] != word[j + i])
                {
                    overlap = false;
                    break;
                }
            }
            if (overlap)
            {
                overlapindex = j;
                break;
            }
        }
   
        int maxbananas = 0;
        double bananas = 0.0;
        double eps = 1e-7;
        if (canspell(word, letters))
        {
            for (int i = 0; i < S; i += overlapindex)
            {
                if (i + L <= S)
                {
                    maxbananas += 1.0;
                }
                else
                {
                    break;
                }
            }

            // count cases where I could spell the word.
            // likelihood that I type between 1 and maxbananas
            
            double likelihood = 1.0;
            REP(i, L)
            {
                likelihood *= perc[word[i] - 'A'];
            }

            REPS(i, L - 1, S)
            {
                bananas += likelihood;
            }
                        
        }

        DPF("%0.7llf\n", (double)maxbananas - bananas);

    }
    fclose(inf);
    fclose(outf);
    return 0;
}