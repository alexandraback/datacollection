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
const int MAX_STR = 20000;
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

#define ONE 0
#define I 1
#define J 2
#define K 3
#define NEG_ONE 4
#define NEG_I 5
#define NEG_J 6
#define NEG_K 7

enum STATE
{
    STATE_ONE,
    STATE_I,
    STATE_J,
    STATE_K,
    STATE_NEG_ONE,
    STATE_NEG_I,
    STATE_NEG_J,
    STATE_NEG_K,
};

int mat[4][4] =
{
    {
        ONE,
        I,
        J,
        K,
    },
    {
        I,
        NEG_ONE,
        K,
        NEG_J,
    },
    {
        J,
        NEG_K,
        NEG_ONE,
        I,
    },
    {
        K,
        J,
        NEG_I,
        NEG_ONE,
    },
};

int mult(int q1, int q2)
{
    // assume q2 is always unsigned since it comes from the string
    int sign = q1 / 4 + q2 / 4;
    q1 %= 4;
    q2 %= 4;

    int prod = mat[q1][q2];
    sign += prod / 4;
    prod %= 4;

    if (sign % 2 == 0)
    {
        return prod;
    }
    else
    {
        return prod + 4;
    }
}

bool checkcycle(LL X, LL cycle_repeat, LL possible)
{
    if (possible > X)
    {
        return false;
    }
    else if (possible == X)
    {
        return true;
    }
    else
    {
        // Subtract the cycles it took to get here, then see if the remainder is divisible by the cycle repeat length.
        X -= possible;

        // Each cycle when repeated at the repeat length will always reduce to 1
        // so return true if we have the proper number of cycles.
        if (X % cycle_repeat == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    FILE* inf = freopen("in.txt", "r", stdin); FILE* outf = fopen("out.txt", "w");
    RI(np); RNL();
    time_t timestart, timeend;
    time(&timestart);   
    for (int pp = 1; pp <= np; pp++)
    {
        DPF("Case #%d: ", pp);
        RI(L);
        RLL(X);
        RS(chs);
        vector<int> chars;
        REP(i, L)
        {
            chars.push_back(chs[i] - 'i' + 1);
        }

        int pattern[8][10000];
        bool hasJPastIndex[8][10000] = { false };
        bool endsWithK[8] = { false };
        REP(start, 8)
        {
            STATE curr = (STATE)start;
            REP(i, L)
            {
                curr = (STATE)mult(curr, chars[i]);
                pattern[start][i] = curr;
            }
            if (pattern[start][L - 1] == STATE_K)
            {
                endsWithK[start] = true;
            }
        }

        REP(start, 8)
        {
            REP(i, L)
            {
                if (pattern[start][L - i - 1] == STATE_J)
                {
                    REPS(j, i, L)
                    {
                        hasJPastIndex[start][L - j - 1] = true;
                    }
                    break;
                }
            }
        }

        int seen_at_index_0[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };
        STATE curr = STATE_ONE;
        int currcycle = 0;
        int repeat = 0;
        while (true)
        {
            // Multiply by the first q.
            curr = (STATE)mult(curr, chars[0]);
            if (seen_at_index_0[curr] == -1)
            {
                seen_at_index_0[curr] = currcycle;
            }
            else
            {
                // Break when we first see the element we care about.
                repeat = currcycle - seen_at_index_0[curr];
                break;
            }
            REPS(i, 1, L)
            {
                STATE next = (STATE)mult(curr, chars[i]);
                curr = next;
            }

            currcycle++;
        }

        // Find an I.
        bool possible = false;

        STATE currI = STATE_ONE;
        int cyclesI = 0;
        bool seenI[8] = { false };
        while (seenI[currI] == false)
        {
            seenI[currI] = true;
            REP(i, L)
            {
                if (pattern[currI][i] == STATE_I)
                {
                    // See if we have a J past this index in this cycle.
                    // If not, continue on to see if we have it in the progression of cycles.
                    // If so, then search for a K.
                    int iIndex = (i + 1) % L;
                    STATE currJ = STATE_ONE;
                    int cyclesJ = cyclesI;
                    if (iIndex == 0)
                    {
                        cyclesJ++;
                    }
                    REP(cj, 8)
                    {
                        if (chars[iIndex] == pattern[cj][iIndex])
                        {
                            currJ = (STATE)cj;
                            break;
                        }
                    }
                    bool seenJ[8] = { false };
                    while (seenJ[currJ] == false)
                    {
                        seenJ[currJ] = true;
                        if (hasJPastIndex[currJ][iIndex])
                        {
                            REPS(jIndex, iIndex, L)
                            {
                                if (pattern[currJ][jIndex] == STATE_J)
                                {
                                    STATE currK = STATE_ONE;
                                    int cyclesK = cyclesJ;
                                    int jFoundIndex = (jIndex + 1) % L;
                                    if (jFoundIndex == 0)
                                    {
                                        cyclesK++;
                                    }
                                    REP(cj, 8)
                                    {
                                        if (chars[jFoundIndex] == pattern[cj][jFoundIndex])
                                        {
                                            currK = (STATE)cj;
                                            break;
                                        }
                                    }
                                    bool seenK[8] = { false };
                                    while (seenK[currK] == false)
                                    {
                                        seenK[currK] = true;
                                        if (endsWithK[currK])
                                        {
                                            if (checkcycle(X, repeat, cyclesK + 1))
                                            {
                                                possible = true;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            currK = (STATE)pattern[currK][L - 1];
                                            cyclesK++;
                                        }
                                    }
                                    if (possible)break;
                                }
                            }
                        }
                        else
                        {
                            currJ = (STATE)pattern[currJ][L - 1];
                            iIndex = 0;
                            cyclesJ++;
                        }
                        if (possible)break;
                    }
                }

                if (possible)break;
            }
            currI = (STATE)pattern[currI][L - 1];
            cyclesI++;
            if (possible)break;
        }

        if (possible)
        {
            DPF("YES\n");
        }
        else
        {
            DPF("NO\n");
        }
    }
    time(&timeend);
    double minutes = difftime(timeend, timestart) / 60.0;
    printf("Minutes elapsed %.2lf\n", minutes);
    
    fclose(inf);
    fclose(outf);
    
    return 0;
}