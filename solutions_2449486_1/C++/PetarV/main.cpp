/*
 Petar 'PetarV' Velickovic
 Task: Lawnmower
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
using namespace std;
typedef long long lld;

int t;
int n, m;
int mat[150][150];
bool mark[150][150];

int total;
int prekRows = 0;

bool fail = false;

int main()
{
    freopen("/Users/PetarV/B-large.in.txt","r",stdin);
    freopen("/Users/PetarV/B-large-out.txt","w",stdout);
    cin >> t;
    for (int f=1;f<=t;f++)
    {
        fail = false;
        vector<pair<int, int> > pos[101];
        total = 0;
        cin >> n >> m;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                cin >> mat[i][j];
                pos[mat[i][j]].push_back(make_pair(i,j));
                mark[i][j] = false;
            }
        }
        for (int i=1;i<=100;i++)
        {
            for (int ii=0;ii<pos[i].size();ii++)
            {
                mark[pos[i][ii].first][pos[i][ii].second] = true;
            }
            total += pos[i].size();
            int covered = 0;
            prekRows = 0;
            for (int i=0;i<n;i++)
            {
                bool kk = true;
                for (int j=0;j<m;j++)
                {
                    if (!mark[i][j])
                    {
                        kk = false;
                        break;
                    }
                }
                if (kk)
                {
                    covered += m;
                    prekRows++;
                }
            }
            for (int j=0;j<m;j++)
            {
                bool kk = true;
                for (int i=0;i<n;i++)
                {
                     if (!mark[i][j])
                     {
                         kk = false;
                         break;
                     }
                }
                if (kk)
                {
                    covered += n - prekRows;
                }
            }
            if (covered != total)
            {
                fail = true;
                break;
            }
        }
        if (!fail) cout << "Case #" << f << ": YES" << endl;
        else cout << "Case #" << f << ": NO" << endl;
    }
    return 0;
}