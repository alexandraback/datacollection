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

struct node
{
    long long n, sz, ans;
    node(long long N = 0, ll SZ = 0, ll ANS = 0)
    {
        n = N;
        sz = SZ;
        ans = ANS;
    }
};

pair <long long, long long> get(long long a, long long b)
{
    long long ans = 0;
    while(a <= b)
    {
        ans++;
        a += a - 1;
    }
    return mp(a + b, ans);
}

const long long inf = 100000000000;

int main()
{
    ifstream cin("in"); ofstream cout("out");
    long long t;
    cin >> t;
    for (long long u = 0; u < t; u++)
    {
        cerr << u << endl;
        long long a, n;
        cin >> a >> n;
        long long A[n];
        for (long long j = 0; j < n; j++)
            cin >> A[j];
        sort(A, A + n);
        vector < node > V;
        V.push_back(node(0, a, 0));
        long long k = 0;
        long long ANS = inf;
        while (k < V.size())
        {
            //cout << V[k].n << " " << V[k].sz << " " << V[k].ans << endl;
            if (V[k].n == n)
            {
                ANS = min(ANS, V[k].ans);
                k++;
                continue;
            }
            node AA = node(V[k].n + 1, V[k].sz, V[k].ans + 1);
            node B = node(-1, -1, -1);
            if (V[k].sz > 1)
                B = node(V[k].n + 1, get(V[k].sz, A[V[k].n]).first, V[k].ans + get(V[k].sz, A[V[k].n]).second);
            if (B.sz == -1)
                V.push_back(AA);
            else
            {
                if (B.ans <= AA.ans)
                {
                    V.push_back(B);
                }
                else
                {
                    V.push_back(AA);
                    V.push_back(B);
                }
            }
            k++;
        }
        cout << "Case #" << u + 1 << ": " << ANS << endl;
    }
    return 0;
}
