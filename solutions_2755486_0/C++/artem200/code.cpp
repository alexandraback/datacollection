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
    vector <long long> A;
    long long t, s;
    node (long long T = 0, long long S = 0, vector <long long> Z = vector<long long>())
    {
        A = Z;
        t = T;
        s = S;
    }
};

bool cmp(node A, node B)
{
    return (A.t < B.t);
}

main()
{
    long long t;
    cin >> t;
    for (long long u = 0; u < t; u++)
    {
        cerr << u << endl;
        long long k;
        cin >> k;
        map <long long, long long> M;
        map < pair <long long, long long>, long long> M1;
        for (long long i = -100000; i <= 100000; i++)
        {
            M[i] = 0;
            M1[mp(i, i + 1)] = 0;
        }
        vector < node > V;
        for (long long i = 0; i < k; i++)
        {
            long long day, cou, l, r, S, dd, dt, ds;
            cin >> day >> cou >> l >> r >> S >> dd >> dt >> ds;
            for (long long j = 0; j < cou; j++)
            {
                vector <long long> Z;
                for (long long z = l; z <= r; z++)
                {
                    Z.push_back(z);
                }
                V.push_back(node(day, max(S, 100000000000LL), Z));
                S += ds;
                l += dt;
                r += dt;
                day += dd;
            }
        }
        sort(V.begin(), V.end(), cmp);
        long long ANS = 0;
        long long ld = -1;
        for (long long i = 0; i < V.size(); i++)
        {
            if (ld != -1 && ld != V[i].t)
            {
                for (long long j = -100000; j <= 100000; j++) {
                    if (M[j] < 0)
                        M[j] = -M[j];
                    if (M1[mp(j, j + 1)] < 0)
                        M1[mp(j, j + 1)] = -M1[mp(j, j + 1)];
                    }
                ld = V[i].t;
            }
            bool OK = false;
            ld = V[i].t;
            for (long long j = 0; j < V[i].A.size(); j++)
            {
                if (M[V[i].A[j]] < 0)
                {
                    OK = true;
                    if (-M[V[i].A[j]] < V[i].s)
                        M[V[i].A[j]] = -V[i].s;
                }
                else
                {
                    if (M[V[i].A[j]] < V[i].s)
                    {
                        M[V[i].A[j]] = -V[i].s;
                        OK = true;
                    }
                }
                if (j < V[i].A.size() - 1)
                    if (M1[mp(V[i].A[j], V[i].A[j + 1])] < 0)
                    {
                        OK = true;
                        if (-M1[mp(V[i].A[j], V[i].A[j + 1])] < V[i].s)
                            M1[mp(V[i].A[j], V[i].A[j + 1])] = -V[i].s;
                    }
                    else
                    {
                        if (M1[mp(V[i].A[j], V[i].A[j + 1])] < V[i].s)
                        {
                            M1[mp(V[i].A[j], V[i].A[j + 1])] = -V[i].s;
                            OK = true;
                        }
                    }
            }
            if (OK)
            {
                ANS++;
                //cout << V[i].t << " " << V[i].s << endl;
            }
        }
        cout << "Case #" << u + 1 << ": " << ANS << endl;
    }
    return 0;
}
