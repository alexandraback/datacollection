#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int n,s,p,T;
int a;
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&T);
    for(int cs=1;cs<=T; ++cs){
        scanf("%d%d%d",&n,&s,&p);
        int ans=0;
        for(int i=0;i<n;++i){
            scanf("%d",&a);
            if(a/3>=p || a%3!=0 && a/3+1>=p) ++ans;
                else if(s>0 && (a%3==0 && a/3+1>=p && a>0 || a%3==2 && a/3+2>=p)){
                    --s;
                    ++ans;
                }
        }
        printf("Case #%d: %d\n",cs,ans);
    }
    return 0;
}
