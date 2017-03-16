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
        // z = 2;
        long long sz = S.size();
        long long ANS = 0;
        long long d[sz];
        long long c = 0;
        if (z == 1 && good(S[0])) {
            d[0] = 1;
            c++;
        }
        else
            d[0] = 0;
        if (good(S[0])) c++;
        for (int i = 1; i < sz; i++)
        {
            d[i] = d[i - 1];
            if ((good(S[i])))
            {
                if (c >= z - 1)
                {
                    d[i] = i - z + 2;
                    c++;
                }
                else
                    c++;
            }
            else
                c = 0;
        }
        long long SUM = 0;
        for (int i = 0; i < sz; i++) {
            //cout << d[i] << " ";
            SUM = SUM + d[i];
        }
        cout << "Case #" << u + 1 << ": " << SUM << endl;
        continue;
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
