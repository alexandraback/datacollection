#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void apply(long long x, vector<int> & checker)
{
    while (x > 0)
    {
        checker[x % 10] = 1;
        x /= 10;
    }
}

bool done(const vector<int> & checker)
{
    for (int i = 0; i < 10; ++i)
    {
        if (checker[i] == 0)
        {
            return false;
        }
    }
    return true;
}

long long solve(long long N)
{
    long long curr = N;
    vector<int> checker(10);
    while (1)
    {
        apply(curr, checker);
        if (done(checker))
        {
            return curr;
        }
        curr += N;
    }
    return 0;
}

int main()
{
    int caseCount;
    cin >> caseCount;
    
    for (int csIx = 1; csIx <= caseCount; ++csIx)
    {
        long long N;
        cin >> N;
        if (N == 0)
        {
            cout << "Case #" << csIx << ": INSOMNIA" << endl;
        }
        else
        {
            cout << "Case #" << csIx << ": " << solve(N) << endl;
        }
    }
    
    return 0;
}
