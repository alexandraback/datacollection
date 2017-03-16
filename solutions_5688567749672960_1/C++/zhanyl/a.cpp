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

long long f[20];

long long fan(long long x){
    long long ans=0;
    while(x){
        ans=ans*10+x%10;
        x=x/10;
    }
    return ans;
}

bool panduan(long long x){
    if(x==1)return false;
    if(x==0)return true;
    while(x%10==0)x=x/10;
    return x==1;
}

long long check(long long x){
    //prlong longf("%d\n",x);
    if(x<=20)return x;
    if(fan(x)==x)return check(x-1)+1;
    long long len=0,tmp=x;
    while(tmp){
        len++;
        tmp=tmp/10;
    }
    tmp=x/f[(len+1)/2]*f[(len+1)/2]+1;
    if(tmp>x){
        if(panduan(x/f[(len+1)/2])||panduan(x/f[(len+1)/2]-1))return check(f[len-1]-1)+x-f[len-1]+1;
        else tmp=(x/f[(len+1)/2]-1)*f[(len+1)/2]+1;
    }
    return check(fan(tmp))+(long long)(fan(tmp)!=tmp)+x-tmp;
}

int main(){
    f[0]=1;
    for(int i=1;i<20;i++)
        f[i]=f[i-1]*10;
    freopen("A-large.in","r",stdin);
    freopen("A-large.ans","w",stdout);
    int T,Cas;
    scanf("%d",&T);
    for(Cas=1;Cas<=T;Cas++){
        long long n;
        scanf("%I64d",&n);
        printf("Case #%d: %I64d\n",Cas,check(n));
    }
    return 0;
}
