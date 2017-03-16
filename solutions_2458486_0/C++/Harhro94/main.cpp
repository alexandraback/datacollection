/*
 * File:     main.cpp
 * Author:   Hrayr [HarHro94]
 * Problem:  
 * IDE:      Visual C++ 2008
 */
//#pragma comment(linker, "/STACK:66777216")
#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <Vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define LL long long
#define LD long double

int n, k, key[100], need[100], cnt[100], a[100][100], pred[(1<<21)];
bool used[(1<<21)];

int main()
{
#ifdef harhro94
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, test, T;
    cin >> T;
    for(test=1;test<=T;++test)
    {
        cin >> k >> n;
        for(i=0;i<k;++i)
        {
            cin >> key[i];
        }
        for(i=0;i<n;++i)
        {
            cin >> need[i] >> cnt[i];
            for(j=0;j<cnt[i];++j)
            {
                cin >> a[i][j];
            }
        }
        queue<int> Q;
        memset(used, false, sizeof used);
        Q.push(0);
        used[0]=true;
        while(!Q.empty())
        {
            int u=Q.front();Q.pop();
            map<int, int> curKeys;
            for(i=0;i<k;++i)
            {
                curKeys[key[i]]++;
            }
            for(i=0;i<n;++i)
            {
                if (((u>>i)&1)==1)
                {
                    curKeys[need[i]]--;
                    for(j=0;j<cnt[i];++j)
                    {
                        curKeys[a[i][j]]++;
                    }
                }
            }
            for(i=0;i<n;++i)
            {
                if (((u>>i)&1)==0)
                {
                    if (curKeys[need[i]]>0 && !used[u+(1<<i)])
                    {
                        used[u+(1<<i)]=true;
                        Q.push(u+(1<<i));
                        pred[u+(1<<i)]=u;
                    }
                }
            }
        }
        cout << "Case #" << test << ":";
        if (!used[(1<<n)-1])
        {
            cout << " IMPOSSIBLE" << endl;
            continue;
        }
        vector<int> way;
        int u=(1<<n)-1;
        while(u!=0)
        {
            int p=pred[u];
            int q=u-p;
            int power=0;
            while((1<<power)!=q)
            {
                ++power;
            }
            way.pb(power+1);
            u=p;
        }
        reverse(all(way));
        for(i=0;i<n;++i)
        {
            cout << " " << way[i];
        }
        cout << endl;
    }

#ifdef harhro94
	cerr << fixed << setprecision(3) << "\nExecution time = " << clock()/1000.0 << "s\n";
#endif
	return 0;
}
