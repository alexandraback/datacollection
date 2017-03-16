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
#define mod 1000000009
#define INF 1e9
using namespace std;
int main () {

    freopen ("b.in", "r", stdin);
    freopen ("output.txt","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.sync_with_stdio(false);
    int t,tc=1;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int counter=0;
        for(int i =s.size()-1  ;i >= 0;i-- )
        {
            if((s[i]=='+'&&counter&1) || (s[i]=='-'&&!(counter&1)))
                counter++;
        }
        cout << "Case #"<<tc++<<": ";
        cout << counter <<endl;

    }
    return 0;
}

