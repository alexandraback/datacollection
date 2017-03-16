#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <list>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <valarray>
#include <ctime>
#include <set>
#include <sstream>
#include <stdarg.h>
#include <fstream>

using namespace std;

void solve(int t) {
    int n;
    cin>>n;
    vector<int> mas(n);
    int maxi=0;
    for (int i=0;i<n;i++) {        
        cin>>mas[i];
        maxi=max(maxi,mas[i]);
    }
    int bestres=1E9;
    for (int i=1;i<=maxi;i++) {
        int curres=i;
        for (int j=0;j<n;j++) {
            curres+=((mas[j]-1)/i);
        }
        bestres=min(bestres, curres);
    }
    printf("Case #%d: %d\n",t,bestres);
}

int main(int argc, char** argv) {
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int T;
    cin>>T;
    for (int i=0;i<T;i++)
        solve(i+1);
    return 0;
}