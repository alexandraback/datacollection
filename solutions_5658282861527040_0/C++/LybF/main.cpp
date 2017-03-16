#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
using namespace std;

const int N=1e6+10;
int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++){
        int a,b,k;
        scanf("%d %d %d",&a,&b,&k);
        int ans=0;
        for (int i=0;i<a;i++)
            for (int j=0;j<b;j++)
                if ((i&j)<k)
                    ans++;
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
