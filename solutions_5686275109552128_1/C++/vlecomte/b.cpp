#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

int p[1000];

int main()
{
    int T;
    cin >> T;
    for (int t=1; t<=T; t++)
    {
        int d;
        cin >> d;
        int maxp = 0;
        for (int i=0; i<d; i++)
        {
            cin >> p[i];
            maxp = max(maxp, p[i]);
        }
        int minTime = 1000;
        for (int nat=1; nat<=maxp; nat++)
        {
            int time = nat;
            for (int i=0; i<d; i++)
            {
                time += (p[i]-1)/nat;
            }
            minTime = min(minTime, time);
            //cout << nat << ": " << time << endl;
        }
        printf("Case #%d: %d\n", t, minTime);
    }
}
