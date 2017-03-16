#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

long long int R (long long r0, long long n)
{
    return n * (2*n + 2*r0 - 1);
}

int main(int argc, char* args[])
{
    size_t T;
    cin >> T;

    for(size_t t = 0; t != T; ++t)
    {
        long long int r, s;
        cin >> r >> s;
        //cout << "Read r:" << r << "  and s:" << s<<endl;
        unsigned long long int count = 0;
        // while(s >= (2*r + 1))
        // {
        //     ++count;
        //     s  -= (2*r + 1);
        //     r += 2;
        // }
        long long int n = 0;
        long long int step = 1;
        while(R(r, n) <= s)
        {
            //cout << "current n:" << n << endl;
            while(R(r, n+step) <= s)
            {
                //cout << "   attempting step:" << step << endl;
                step *= 2;
            }
            if(step < 2)
            {
                break;
            }
            n += step/2;
            step = 1;
        }


        cout << "Case #" << t+1 << ": " << n << endl;

    }





    return 0;
}