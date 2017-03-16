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
    string s;
    cin>>s;
    int cnt=0, res=0;
    for (int i=0;i<n+1;i++) {        
        if (cnt<i) {
            res+=(i-cnt);
            cnt=i;
        }
        cnt+=(s[i]-'0');
    }
    printf("Case #%d: %d\n",t,res);
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