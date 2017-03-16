#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
using namespace std;


#define forn(i, n) for(int i = 0; i < n; i++)


vector <bool> fi, se;
int a[1000][2];
int t, n, res, ans;


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int test = 1; test <= t; test++)
    {
        cin >> n;
        fi.resize(n);
        se.resize(n);
        forn(i, n)
        {
            fi[i] = 1;
            se[i] = 1;
            cin >> a[i][0] >> a[i][1];
        }
        res = 0;
        ans = 0;
        int prev = 0;
        while(1)
        {
            if(res == 2 * n) break;
            prev = res;
            forn(i, n)
            {
                if(se[i]  &&  res >= a[i][1])
                {
                    ans++;
                    se[i] = false;
                    fi[i] = false;
                    res += 2;
                }
            }
            if(res != prev) continue;
            int best = -1;
            forn(i, n)
            {
                if(res >= a[i][0]  &&  fi[i]  &&  (best == -1  ||  se[i] == false  ||   (se[best] == true  &&  se[i] == true  &&  a[best][1] < a[i][1])))
                    best = i;
            }
            if(best == -1)  goto armag;
            fi[best] = se[best];
            a[best][0] = a[best][1];
            se[best] = false;
            res++;
            ans++;
        }
        printf("Case #%d: %d\n", test, ans);
        continue;
        armag:
        printf("Case #%d: Too Bad\n", test);
    }
}
