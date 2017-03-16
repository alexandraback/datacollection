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

const int maxn=1000;
const double eps=1e-9;

int n,idx;
int p[maxn],v[maxn];

int check(){
    if(v[0]>v[1]){
        swap(v[0],v[1]);
        swap(p[0],p[1]);
    }
    double v0=(360.0*360.0/v[0])/(720.0-p[0]),v1=360.0/v[1],t;
    if(v0>v1)t=p[1]/(v0-v1);
    else return 0;
    if(t*v0<=360.0)return 1;
    return 0;
}

int main(){
    freopen("C-small-1-attempt1.in","r",stdin);
    freopen("C-small-1-attempt1.ans","w",stdout);
    static int T,Cas;
    scanf("%d",&T);
    for(Cas=1;Cas<=T;Cas++){
        scanf("%d",&n);
        static int i;
        idx=0;
        for(i=1;i<=n;i++){
            int a,b,c,j;
            scanf("%d%d%d",&a,&b,&c);
            for(j=0;j<b;j++){
                p[idx]=a;
                v[idx]=c+j;
                idx++;
            }
        }
        if(idx==1||v[0]==v[1])printf("Case #%d: 0\n",Cas);
        else{
            printf("Case #%d: %d\n",Cas,check());
        }
    }
    return 0;
}
