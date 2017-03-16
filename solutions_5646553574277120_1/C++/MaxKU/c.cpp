#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
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
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

const int maxn=105;

int c,d,v;
int f[maxn];

int main(){
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    static int T,Cas;
    scanf("%d",&T);
    for(Cas=1;Cas<=T;Cas++){
        static long long now;
        static int i,ans;
        scanf("%d%d%d",&c,&d,&v);
        for(i=0;i<d;i++)
            scanf("%d",&f[i]);
        sort(f,f+d);
        now=ans=0;
        for(i=0;i<d;i++){
            while(now+1<f[i] && now<v){
                ans++;
                now+=(now+1)*c;
            }
            if(now<v)now+=f[i]*(long long)c;
        }
        while(now<v){
            ans++;
            now+=(now+1)*c;
        }
        printf("Case #%d: %d\n",Cas,ans);
    }
    return 0;
}
