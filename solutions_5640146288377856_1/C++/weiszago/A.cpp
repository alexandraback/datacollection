#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;


int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("ki.txt", "w", stdout);
    int t, r, c, w;
    cin >> t;
    for (int tt=1;tt<=t;tt++) {
        cin >>r>>c>>w;;
        int mo=c/w;
        mo*=r;
        if (c%w==0) mo+=w-1;
        else mo+=w;
        cout << "Case #" << tt<< ": "<<mo<<endl;
    }
    return 0;
}
