#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <assert.h>
//#define mod 1000000009
#define INF 1e9
#define mod 11
using namespace std;
int main () {

    freopen ("d.in", "r", stdin);
    freopen ("output.txt","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.sync_with_stdio(false);
    int t,tc=1;
    cin >> t;
    while(t--)
    {
        int k , c, s;
        cin >> k >> c >>s;
        cout << "Case #"<<tc++<<":";
        for(int i = 1;i<=k;i++)
            cout << " " << i;
        cout <<endl;
    }
    return 0;
}

