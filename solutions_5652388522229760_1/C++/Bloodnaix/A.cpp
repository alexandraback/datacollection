#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <cmath>
#include <memory.h>
#include <string>
#include <vector>
using namespace std;

bool used[10];
int count_used;

void update_digits(long long int n)
{
    int d = 0;
    while(n)
    {
        d = n % 10;
        if(!used[d])
        {
            used[d] = 1;
            ++count_used;
        }
        n /= 10;
    }
}

int main()
{
    ifstream f1("A-large.in");
    ofstream f2("A-large.out");
    int T;
    long long int N, M;

    f1 >> T;
    for(int t = 0; t < T; ++t)
    {
        f2 << "Case #" << t+1 << ": ";
        f1 >> N;
        if(N == 0)
        {
            f2 << "INSOMNIA" << endl;
            continue;
        }
        for(int i = 0; i < 10; ++i)
            used[i] = 0;
        count_used = 0;

        M = N;
        update_digits(M);
        while(count_used < 10)
        {
            M += N;
            update_digits(M);
        }
        f2 << M << endl;
    }
    return 0;
}

