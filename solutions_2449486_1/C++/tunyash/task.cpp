#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const int INF = 1000000000;
const int prime = 9241;
const ld pi = acos(-1.);

int area[105][105];
bool row[105];
bool col[105];

void solve(int test)
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
         cin >> area[i][j];
    bool ok = 1;
    for (int h = 0; h <= 100 && ok; h++)
    {
        for (int i = 0; i < n; i++)
           row[i] = 1;
        for (int j = 0; j < m; j++)
           col[j] = 1;
        for (int i = 0; i < n; i++)
           for (int j = 0; j < m; j++)
              if (area[i][j] > h) 
                 row[i] = col[j] = 0;
        for (int i = 0; i < n && ok; i++)
           for (int j = 0; j < m && ok; j++)
              if (area[i][j] <= h && !row[i] && !col[j]) 
              {
               //  cout << "i=" << i << " j=" << j << endl;
               //  cout << row[i] << ' ' << col[j] << endl;
                 ok = 0;
              }
    }
    cout << "Case #" << test << ": " << (ok?"YES":"NO") << endl;
 /*   for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
           cout << area[i][j] << ' ';
        cout << endl;
    }
    cout << endl;   */
}

int main()
{
   int t;
   cin >> t;
   for (int i = 0; i < t; i++)
      solve(i+1);
}