#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long myLong;
//  myLong max = 18446744073709551615ULL;
//  myLong can be used upto 10 ^ 19.


#define For(i,n) for (int i=1;i<(int)(n+1);i++) 
#define FOR(i,n) for (int i=0;i<(int)(n);i++) 

int ops;

void solve(vector<long> & motes, vector<long>::iterator start, long currentA, int i)
{
    int new_ops = 1; --i;
    currentA += (currentA -1);
    vector<long>::iterator to_absorb = motes.end();
    for (vector<long>::iterator it = start; it != motes.end(); it++)
    {
        if (*it < currentA)
            currentA += *it;
        else
        {
            while (i > 0 && *it >= currentA)
            {
                new_ops++; --i;
                currentA += (currentA -1);
            }
            if (*it < currentA)
                currentA += *it;
            else
            {
                to_absorb = it;
                break;
            }
        }
    }
    new_ops += distance(to_absorb,motes.end());
    if(ops > new_ops)
        ops = new_ops;
}

void solve_case()
{
    long A;
    int N;
    cin >> A >> N;
    vector<long> motes;
    FOR(i,N)
    {
        long m;
        cin >> m;
        motes.push_back(m);
    }
    sort(motes.begin(),motes.end());

    long currentA = A;
    vector<long>::iterator to_absorb = motes.end();
    for (vector<long>::iterator it = motes.begin(); it != motes.end(); it++)
    {
        if (*it < currentA)
            currentA += *it;
        else
        {
            to_absorb = it;
            break;
        }
    }
    if (to_absorb == motes.end())
        cout << "0";
    else
    {
        if ((currentA -1) > 0)
        {
            ops = distance(to_absorb, motes.end());
            int max_op = ops;
            for(int i =1; i < max_op; i++)
                solve(motes, to_absorb, currentA, i);
            cout << ops;

        }
        else
            cout << distance(to_absorb, motes.end());
    }

}

main()
{
    unsigned int tests;
    cin >> tests;
    for (unsigned int tests_index = 1; tests_index < tests +1; tests_index++)
    {
        cout << "Case #" << tests_index << ": ";
        solve_case();
        cout << endl;
    }

}
