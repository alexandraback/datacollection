#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <map>
#include <stack>
#include <set>
#include <queue>

using namespace std;

ifstream in;
ofstream out;

int step(unsigned long long a)
{
    int i = 0;
    while (a != 0)
    {
        a /= 10;
        ++i;
    }
    return i;
}

unsigned long long binsearch(unsigned long long r, unsigned long long t)
{
    unsigned long long n = 2000000000;
    unsigned long long first = 0; /* Номер первого элемента в массиве */
    unsigned long long last = n;  /* Номер элемента в массиве, СЛЕДУЮЩЕГО ЗА последним */
                      /* Если просматриваемый участок непустой, first<last */
    unsigned long long mid;
    while (first < last)
    {
        mid = first + (last - first) / 2;
        unsigned long long K;
        K = (2 * r * (mid + 1) + 2 * mid * mid + 3 * mid + 1);
        if (step(r) + step(mid) > 19 || t <= K)
        {
            last = mid;
        }
        else
        {
            first = mid + 1;
        }
    }
    unsigned long long K;
    K = (2 * r * (first + 1) + 2 * first * first + 3 * first + 1);
    if (t >= K)
    {
        ++first;
    }
    return first;
}

int main()
{
    in.open("input.in");
    out.open("output.txt");
    unsigned long long N, r, t;
    in >> N;
    for (int i = 0 ; i < N; ++i)
    {
        in >> r >> t;
        out << "Case #" << i + 1 << ": " << binsearch(r, t) << endl;
    }
    return 0;
}
