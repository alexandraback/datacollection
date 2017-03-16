 //You are weak? Why? Because You lack Hatred. - Itachi
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
#include <set>
using namespace std;

#define MAX 1000500
#define MOD 1000000007
#define INF 1e9

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("output_new2.txt", "w", stdout);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++){
        cout << "Case #" << t << ": ";
        int r, c, w;
        cin >> r >> c >> w;
        int miss = c/w;
        if (c == miss*w) miss = miss * r + (w-1);
        else miss = miss * r + w;
        cout << miss << endl;
    }
}
