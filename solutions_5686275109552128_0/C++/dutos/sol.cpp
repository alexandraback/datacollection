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

        // The idea is that we use all our special minutes up front, then let things play out.
        /*
        int seconds = 0;
        int size = D;
        while (size)
        {

            
            // How many elements of size P[0] do we have;
            int splits = 0;
            REP(i, size)
            {
                if (P[i] == P[0])
                {
                    splits++;
                }
                else
                {
                    break;
                }
            }

            // Only split if its cheaper.  Be greedy!
            int timeWithNoSplits = P[0];
            int timeWithMajorSplits = (P[0] + 1) / 2 + splits;
            if (timeWithNoSplits > timeWithMajorSplits)
            {
                // Tis is a base condition for splitting, but not the best possible way to split.
                int splitvalue = 0;
                if (size > splits && P[splits] * 2 <= P[0])
                {
                    int numminorsplits = (P[0] + P[splits] - 1) / P[splits] - 1;
                    int timeWithMinorSplits = P[splits] + numminorsplits * splits;
                    if (timeWithMajorSplits >= timeWithMinorSplits)
                    {
                        splitvalue = P[splits];
                    }
                    else
                    {
                        splitvalue = P[0] / 2;
                    }
                }
                else
                {
                    splitvalue = 2;
                    int minTime = timeWithMajorSplits;
                    int minSplitValue = P[0] / 2;
                    while (splitvalue < P[0] / 2)
                    {
                        int numminorsplits = 0;
                        REP(i, size)
                        {
                            numminorsplits += (P[i] + splitvalue - 1) / splitvalue - 1;
                            if (P[i] <= splitvalue)
                            {
                                break;
                            }
                        }
                        int timeWithMinorSplits = splitvalue + numminorsplits * splits;
                        if (minTime >= timeWithMinorSplits)
                        {
                            minTime = timeWithMinorSplits;
                            minSplitValue = splitvalue;
                        }
                        splitvalue++;
                    }
                    splitvalue = minSplitValue;
                }
                REP(i, splits)
                {
                    P[i] -= splitvalue;
                    P.push_back(splitvalue);
                    size++;
                    seconds++;
                }
                sort(P.begin(), P.end(), lesss);
            }
            else
            {
                // Eat!  We probably don't need to simulate this, but why not, input sizes are small.
                REP(i, size)
                {
                    P[i]--;
                    if (P[i] == 0)
                    {
                        REP(j, size - i)
                        {
                            P.erase(P.end() - 1);
                        }
                        size = i;
                        break;
                    }
                }
                seconds++;
            }
            
            
        }

        DPF("%d\n", seconds);*/
    }
    fclose(inf);
    fclose(outf);
    return 0;
}