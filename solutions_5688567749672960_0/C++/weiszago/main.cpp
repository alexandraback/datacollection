#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

int t;
int d[10000001];

int fordit(int x) {
    int c=0;
    while (x>0) {
        c*=10;
        c+=(x%10);
        x/=10;
    }
    return c;
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("ki.txt", "w", stdout);
    cin >> t;
    for (int ttt=1;ttt<=t;ttt++) {
        int n;
        cin >> n;
        for (int i=1;i<=2*n;i++) d[i]=-1;
        d[1]=1;
        for (int i=1;i<=2*n;i++) {
            if (d[i+1]==-1) d[i+1]=d[i]+1;
            d[i+1]=min(d[i]+1, d[i+1]);
            int zzz=fordit(i);
            if (zzz<=2*n) {
                if (d[zzz]==-1) d[zzz]=d[i]+1;
                d[zzz]=min(d[i]+1, d[zzz]);
            }
        }
        cout << "Case #" << ttt<< ": " <<d[n]<<endl;
    }
    return 0;
}
