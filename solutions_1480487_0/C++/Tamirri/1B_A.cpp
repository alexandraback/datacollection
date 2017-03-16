#include <iostream>
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

int N;
int sum;
vector<int> J;


void runCase2(int Case)
{
    int sum = 0;
    for (int i=0; i<N; i++)
        sum += J[i];

    printf("Case #%d: ", Case+1);

    for (int curr=0; curr<N; curr++)
    {
        double minP = 1;
        for (int i=0; i<N; i++)
        {
            if (i==curr)
                continue;

            double p = (double)(J[i] - J[curr] + sum) / (2.0 * sum);
            minP = min(minP, p);
        }

        printf("%f ", minP);
    }
    printf("\n");
    return;
}

bool isOk(int curr, double p)
{
    double rem = 1.0 - p;
    double myVal = J[curr] + sum*p;

    for (int i=0; i<N; i++)
    {
        if (i==curr)
            continue;

        double req = (myVal-J[i])/sum;
        if (req <= 0)
            continue;

        rem -= req;
        if (rem < 0)
            return true;
    }
    return (rem <=0);
}

void runCase(int Case)
{
    sum = 0;
    for (int i=0; i<N; i++)
        sum += J[i];

    printf("Case #%d: ", Case+1);

    for (int i=0; i<N; i++)
    {
        double l = 0;
        double h = 1;
        double mid;
        while (h-l > 0.00000001)
        {
            mid = (l+h)/2;
            if (isOk(i, mid))
                h = mid;
            else
                l = mid;
        }
        printf("%f ", h*100);
    }

    printf("\n");
    return;
}

void Run()
{
    int T;
    cin >> T;

    for (int i=0; i < T; i++)
    {
        cin >> N;
        readLineOfNums(N, J);

        runCase(i);
    }
}


void main()
{
    _chdir(".\\Src");
    setStdinFromFile("A-small-attempt0.in");
    setStdoutToFile ("A.out");

    Run();

    system("pause");
}

