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
#define EPS 1e-9

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ll> pt;

char c;
int T, N;
ld S[50], P[50];
bool dp[100][1<<6];

inline ld pos(int ind, ld t)
{
    return P[ind] + S[ind]*t;
}

int main()
{
    ios::sync_with_stdio(0);
    ifstream in("C.in");
    ofstream out("C.out");
    out << fixed << setprecision(12);
    in >> T;
    for (int z = 1; z <= T; ++z)
    {
       in >> N;
       int state = 0, full = (1<<N) - 1;
       for (int i = 0; i < N; ++i)
       {
           in >> c >> S[i] >> P[i];
           if (c == 'R') state |= 1<<i;
       }
       memset(dp, false, sizeof dp);
       //dp[0][state] = true;
       for (int tm = full; tm >= 0; --tm)
       {
           bool valid = true;
           for (int i = 0; i < N && valid; ++i)
           for (int j = 0; j < i; ++j)
           {
               bool bi = (tm & (1<<i)), bj = (tm & (1<<j));
               if (bi == bj && abs(P[i] - P[j]) < 5)
                   valid = false;
           }
           for (int i = 0; i < N && valid; ++i)
           {
               bool b1 = (state & (1<<i)), b2 = (tm & (1<<i));
               if (b1 != b2)
               {
                   for (int j = 0; j < N; ++j)
                   if (i != j && abs(P[i] - P[j]) < 5)
                       valid = false;
               }
           }
           if (valid)
               dp[0][tm] = true;
       }
       
       set<ld> se;
       se.insert(0);
       se.insert(EPS);
       se.insert(1e20);
       for (int i = 0; i < N; ++i)
       for (int j = 0; j < i; ++j)
       if (S[i] != S[j])
       {
           ld t = (P[j]-P[i]+5)/(S[i]-S[j]);
           if (t > EPS) se.insert(t);
           t = (P[j]-P[i]-5)/(S[i]-S[j]);
           if (t > EPS) se.insert(t);
       }
       vector<ld> events(se.begin(), se.end());
       /*for (int i = 0; i < events.size(); ++i)
           out << events[i] << ' ';
       out << endl;*/
       
       ld best = 0;
       for (int i = 1; i < events.size()-1; ++i)
       for (int bm = full; bm >= 0; --bm)
       if (dp[i-1][bm])
       for (int tm = full; tm >= 0; --tm)
       {
           ld t = events[i];
           bool valid = true;
           
           for (int i = 0; i < N && valid; ++i)
           for (int j = 0; j < i; ++j)
           {
               bool bi = (bm & (1<<i)), bj = (bm & (1<<j));
               if (bi == bj)
               {
                   if (S[i] == S[j])
                   {
                       if (abs(P[i] - P[j]) < 5)
                           valid = false;
                   }
                   else
                   {
                       if (abs(pos(i,t-EPS) - pos(j,t-EPS)) < 5)
                           valid = false;
                   }
               }
           }
           for (int i = 0; i < N && valid; ++i)
           for (int j = 0; j < i; ++j)
           {
               bool bi = (tm & (1<<i)), bj = (tm & (1<<j));
               if (bi == bj)
               {
                   if (S[i] == S[j])
                   {
                       if (abs(P[i] - P[j]) < 5)
                           valid = false;
                   }
                   else
                   {
                       if (abs(pos(i,t+EPS) - pos(j,t+EPS)) < 5)
                           valid = false;
                   }
               }
           }
           for (int i = 0; i < N && valid; ++i)
           {
               bool b1 = (bm & (1<<i)), b2 = (tm & (1<<i));
               if (b1 != b2)
               {
                   for (int j = 0; j < N; ++j)
                   if (i != j)
                   {
                       if (abs(pos(i,t) - pos(j,t)) < 5 - EPS)
                           valid = false;
                   }
               }
           }
           if (valid)
           {
               best = events[i+1];
               dp[i][tm] = true;
           }
       }
       
       if (best > 1e18)
           out << "Case #" << z << ": Possible" << endl;
       else
           out << "Case #" << z << ": " << best << endl;
    }
}
