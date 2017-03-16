#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;
typedef pair<int,int> pii;

void solve(int num) {
    double c,f,x,rate=2.0,time=0.0;
    double res=1000000000.0;
    scanf(" %lf %lf %lf",&c,&f,&x);
    For(i,((int)x)+5) {
        if(time>res) break;
        double cas=time+x/rate;
        if(res>cas) res=cas;
        time+=c/rate;
        rate+=f;
    }
    printf("Case #%d: ",num);
    printf("%0.9lf\n",res);
}

int main() {
    int t;
    scanf("%d",&t);
    For(i,t) solve(i+1);
return 0;
}
