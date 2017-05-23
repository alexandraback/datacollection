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

int T, A, B;
ld p[100000];

int main()
{
    ios::sync_with_stdio(0);
    ifstream in("A.in");
    ofstream out("A.out");
    out << fixed << setprecision(12);
    in >> T;
    for (int z = 1; z <= T; ++z)
    {
       in >> A >> B;
       for (int i = 0; i < A; ++i)
           in >> p[i];
       ld best = B + 2, cor = 1;
       for (int i = 0; i <= A; ++i)
       {
           best = min(best, 1+A+B-2*i+(1-cor)*(1+B));
           cor *= p[i];
       }
       out << "Case #" << z << ": " << best << endl;
    }
}
