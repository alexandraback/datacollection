#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <complex>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ll> pt;

int T, N;
pii levels[1000];
int done[1000];

int main()
{
    ios::sync_with_stdio(0);
    ifstream in("B.in");
    ofstream out("B.out");
    in >> T;
    for (int z = 1; z <= T; ++z)
    {
       in >> N;
       for (int i = 0; i < N; ++i)
           in >> levels[i].second >> levels[i].first;
       sort(levels, levels + N);
       memset(done, 0, sizeof done);
       
       int plays = 0, stars = 0;
       bool success = true;
       while (success)
       {
           success = false;
           for (int i = 0; i < N; ++i)
           if (done[i] < 2 && levels[i].first <= stars)
           {
               stars += 2 - done[i];
               plays++;
               done[i] = 2;
               success = true;
           }
           if (!success)
           {
               for (int i = N-1; i >= 0; --i)
               if (!done[i] && levels[i].second <= stars)
               {
                   stars++;
                   plays++;
                   done[i] = 1;
                   success = true;
                   break;
               }
           }
       }
       if (stars < 2*N)
           out << "Case #" << z << ": Too Bad" << endl;
       else
           out << "Case #" << z << ": " << plays << endl;
    }
}
