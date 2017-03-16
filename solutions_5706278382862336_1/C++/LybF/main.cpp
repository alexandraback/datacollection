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
#include <bitset>
using namespace std;



long long gcd(long long a,long long b){
    if (b==0) return a;
    return gcd(b,a%b);
}
bool check(long long a){
    while (a%2==0) a/=2;
    return a==1LL;
}
int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,cas=1;
    scanf("%d",&T);
    while (T--){
        long long a,b;
        scanf("%I64d/%I64d",&a,&b);
        long long t=gcd(a,b);
        a/=t;
        b/=t;
        if (!check(b)){
            printf("Case #%d: impossible\n",cas++);
            continue;
        }
        int ret=0;
        while (b%2==0&&a<b){
            b/=2;ret++;
        }
        if (ret>40) {
            printf("Case #%d: impossible\n",cas++);
        } else {
            printf("Case #%d: %d\n",cas++,ret);
        }
    }
    return 0;
}



