#include <direct.h>
#include <cmath>
#include <assert.h>

#define STL
#ifdef STL
    #include <algorithm>
    #include <vector>
    #include <list>
    #include <map>
    using namespace std;
#endif

enum {MAX_LINE_LEN = 512};
#include "InputUtils.h"

typedef double TN;
int A;
int B;  // length
vector<double> P;


TN runCase()
{
    vector<TN> TP;

    TN p_ok = 1;
    for (int i=0; i<A; i++)
    {
        TN prob(P[i]);
        p_ok *= prob;
        TP.push_back(p_ok);
    }

    TN keep_type = TP[A-1] * (B-A+1) + (1-TP[A-1])*(B-A+1+B+1);

    TN back_min = A+B+1;    // backspace till the begin
    for (int i=1; i<A; i++)     // how many backs
    {
        int new_pos = A-i;
        int first_try = i+B-new_pos+1;
        TN back = TP[A-i-1]*first_try + (1-TP[A-i-1])*(first_try + B+1); 

        back_min = min(back_min, back);
    }

    TN press_ent = 1 + B+1;

    TN ret = min(min(keep_type, back_min), press_ent);
    return ret;
}


void Run()
{
    int T = readNumLine();  // number of cases

    LineType line;
    for (int i=0; i < T; i++)
    {
        readLine(line);
        A = readFirstNum(line);
        B = readNextNum();

        readLine(line);
        P.clear();
        readLineOfD(line, A, P);

        TN ans = runCase();

        printf("Case #%d: %6lf \n", i+1, ans);
    }
}


void main()
{
    _chdir(".\\Src");
    setStdinFromFile("A-small-attempt2.in");
    setStdoutToFile ("A.out");

    Run();

    system("pause");
}

