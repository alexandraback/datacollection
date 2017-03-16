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

void processnormally(string& C, string& J, int l)
{
    bool less = false;
    bool cless = false;

    REP(i, l)
    {
        bool cu = C[i] == '?';
        bool ju = J[i] == '?';

        if (cu && ju)
        {
            if (less)
            {
                if (cless)
                {
                    C[i] = '9';
                    J[i] = '0';
                }
                else
                {
                    J[i] = '9';
                    C[i] = '0';
                }
            }
            else
            {
                C[i] = J[i] = '0';
            }
        }
        else if (cu)
        {
            if (less)
            {
                if (cless)
                {
                    C[i] = '9';
                }
                else
                {
                    C[i] = '0';
                }
            }
            else
            {
                C[i] = J[i];
            }
        }
        else if (ju)
        {
            if (less)
            {
                if (cless)
                {
                    J[i] = '0';
                }
                else
                {
                    J[i] = '9';
                }
            }
            else
            {
                J[i] = C[i];
            }
        }
        else if (!less)
        {
            int cval = C[i] - '0';
            int jval = J[i] - '0';
            if (cval < jval)
            {
                less = true;
                cless = true;
            }
            else if (jval < cval)
            {
                less = true;
            }
        }
    }
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

        RS(C); RS(J);

        int lessindex = -1;

        int l = C.size();

        string oC = C;
        string oJ = J;

        for (int i = 0; i < l; i++)
        {
            bool cu = C[i] == '?';
            bool ju = J[i] == '?';

            if (cu || ju)
            {
                // do nothing
            }
            else if (lessindex == -1)
            {
                int cval = C[i] - '0';
                int jval = J[i] - '0';
                if (cval != jval)
                {
                    lessindex = i;
                }
            }
        }

        if (lessindex == -1)
        {
            REP(i, l)
            {
                bool cu = C[i] == '?';
                bool ju = J[i] == '?';

                if (cu && ju)
                {
                    C[i] = J[i] = '0';
                }
                else if (cu)
                {
                    C[i] = J[i];
                }
                else if (ju)
                {
                    J[i] = C[i];
                }
            }
        }
        else
        {
            int cval = C[lessindex] - '0';
            int jval = J[lessindex] - '0';

            if (cval < jval)
            {
                //DPF("*");
                if (jval - cval < 5)
                {
                    //DPF("*** (<5)");
                    processnormally(C, J, l);
                }
                else
                {
                    int diff = jval - cval;

                    //if (diff == 5) DPF("***");
                    //DPF("*** (>=5)");
                    string oC = C;
                    string oJ = J;
                    // walk back from lessindex matching until we find one where they both are ?
                    int i = lessindex - 1;
                    bool swapped = false;
                    bool flipped9 = false;
                    bool flipped0 = false;
                    while (i >= 0)
                    {
                        if (C[i] == '?' && J[i] == '?')
                        {
                            if (diff == 5)
                            {
                                J[i] = '0';
                                C[i] = '0';
                            }
                            else
                            {
                                C[i] = '1';
                                J[i] = '0';
                                swapped = true;
                                break;
                            }
                            
                        }
                        else if (C[i] == '?')
                        {
                            if (diff == 5)
                            {
                                C[i] = J[i];
                            }
                            else
                            {
                                if (J[i] == '9')
                                {
                                    C[i] = '0';
                                    flipped9 = true;
                                }
                                else
                                {
                                    C[i] = J[i] + 1;
                                    swapped = true;
                                    break;
                                }
                            }
                        }
                        else if (J[i] == '?')
                        {
                            /*if (diff == 5)
                            {
                                J[i] = C[i];
                            }
                            else*/
                            {
                                if (C[i] == '0')
                                {
                                    J[i] = '9';
                                    flipped0 = true;
                                }
                                else
                                {
                                    J[i] = C[i] - 1;
                                    swapped = true;
                                    break;
                                }
                            }
                        }
                        i--;
                    }

                    if (!swapped && flipped9)
                    {
                        C = oC;
                        J = oJ;
                        processnormally(C, J, l);
                    }
                    else
                    {
                        processnormally(C, J, l);
                    }
                }
            }
            else if (jval < cval)
            {
                //DPF("*");
                if (cval - jval < 5)
                {
                    //DPF("*** (<5)");
                    processnormally(C, J, l);
                }
                else
                {
                    int diff = cval - jval;
                    //if (diff == 5) DPF("***");
                    //DPF("*** (>=5)");
                    // walk back from lessindex matching until we find one where they both are ?
                    string oC = C;
                    string oJ = J;
                    // walk back from lessindex matching until we find one where they both are ?
                    int i = lessindex - 1;
                    bool swapped = false;
                    bool flipped9 = false;
                    bool flipped0 = false;
                    while (i >= 0)
                    {
                        if (C[i] == '?' && J[i] == '?')
                        {
                            if (diff == 5)
                            {
                                J[i] = '0';
                                C[i] = '0';
                            }
                            else
                            {
                                C[i] = '0';
                                J[i] = '1';
                                swapped = true;
                                break;
                            }
                        }
                        else if (C[i] == '?')
                        {
                            /*if (diff == 5)
                            {
                                C[i] = J[i];
                            }
                            else*/
                            {
                                if (J[i] == '0')
                                {
                                    C[i] = '9';
                                    flipped9 = true;
                                }
                                else
                                {
                                    C[i] = J[i] - 1;
                                    swapped = true;
                                    break;
                                }
                            }
                        }
                        else if (J[i] == '?')
                        {
                            if (diff == 5)
                            {
                                J[i] = C[i];
                            }
                            else
                            {
                                if (C[i] == '9')
                                {
                                    J[i] = '0';
                                    flipped0 = true;
                                }
                                else
                                {
                                    J[i] = C[i] + 1;
                                    swapped = true;
                                    break;
                                }
                            }
                        }
                        i--;
                    }

                    if (!swapped && (flipped9 || flipped0))
                    {
                        C = oC;
                        J = oJ;
                        processnormally(C, J, l);
                    }
                    else
                    {
                        processnormally(C, J, l);
                    }
                }
            }
        }
        int cval = atoi(C.c_str());
        int jval = atoi(J.c_str());
        DPF("%s %s\n", C.c_str(), J.c_str());
        //DPF("%s %s - %d\n", C.c_str(), J.c_str(), abs(cval - jval));
    }
    fclose(inf);
    fclose(outf);
    return 0;
}