#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long r;
    cin >> r;
    for(long long test = 1; test <= r; test++)
    {
        int N, M;
        cin >> N >> M;
        vector<pair<long long, long long> > A, B;
        int del = 0;
        for(int i = 0; i < N; i++)
        {
            long long a, b;
            cin >> a >> b;
            if(A.size() >= 1 && A[i-1].second == b)
            {
                A[i-1].first += a;
                del++;
            }
            else
                A.pb(mp(a, b));
        }
        N -= del;
        for(int i = N; i < 3; i++)
            A.pb(mp(0, -1));
        for(int i = 0; i < M; i++)
        {
            long long a, b;
            cin >> a >> b;
            B.pb(mp(a, b));
        }

        long long good = 0;
        for(int i = 0; i <= M; i++)
        {
            for(int j = i; j <= M; j++)
            {
                    long long good2 = 0;
                    vector<long long> Vz(3);
                    for(int t = 0; t < M; t++)
                    {
                        if(t >= 0 && t < i && B[t].second == A[0].second)
                        {
                            Vz[0] += B[t].first;
                        }
                        if(t >= i && t < j && B[t].second == A[1].second)
                        {
                            Vz[1] += B[t].first;
                        }
                        if(t >= j && t < M && B[t].second == A[2].second)
                        {
                            Vz[2] += B[t].first;
                        }
                    }
                    for(int t = 0; t < 3; t++)
                        good2 += min(Vz[t], A[t].first);
                    if(good2 > good)
                        good = good2;
            }
        }
        if(N == 3 && A[0].second == A[2].second)
        {
            long long good2 = 0;
            long long Vz = 0;
            for(int t = 0; t < M; t++)
            {
                if(B[t].second == A[0].second)
                {
                    Vz += B[t].first;
                }
            }
            good2 = min (Vz, A[0].first + A[2].first);
            if(good2 > good)
                good = good2;
        }
        cout << "Case #"<< test<<": ";

        cout << good << endl;
    }

    return 0;
}
