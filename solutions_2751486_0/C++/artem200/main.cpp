#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

bool good(char c)
{
    return (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'));
}

int main()
{
    vector <pair <long long, long long> > V;
    long long n;
    cin >> n;
    for (long long u = 0; u < n; u++)
    {
        long long z;
        string S;
        cin >> S >> z;
        long long sz = S.size();
        long long ANS = 0;
        for (long long i = 0; i < sz; i++)
        {
            for (long long j = i; j < sz; j++)
            {
                bool OK = false;
                long long ll = -1;
                for (long long k = i; k <= j; k++)
                {
                    if (good(S[k]))
                    {
                        if (ll == -1)
                        {
                            ll = k;
                        }
                    }
                    else
                    {
                        if (ll != -1)
                        {
                            if (k - 1 - ll + 1 >= z)
                                OK = true;
                        }
                        ll = -1;
                    }
                }
                if (ll != -1)
                    if (j - ll + 1 >= z)
                        OK = true;
                if (OK) ANS++;
            }
        }
        cout << "Case #" << u + 1 << ": " << ANS << endl;
    }
    return 0;
}
