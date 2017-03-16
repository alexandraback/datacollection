#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

#define F1 "code.inp"
#define F2 "code.out"

const int inf=1000000000;
const int md=1000000007;
const double esp=0.000000000001;
typedef pair<int,int>ii;

double c,f,x;
int init(){
    return 0;
}

int read(){
    scanf("%lf%lf%lf",&c,&f,&x);
    return 0;
}

int process(){
    double last=x/2;
    double now,rate;
    double time=0;
    rate=2.0;
    for (int i=1;i<=100000000;i++){
        time+=c/rate;
        rate+=f;
        now=time+x/rate;
        if (now>last) break;
        last=now;
    }
    printf("%.7lf",last);
    return 0;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen(F1,"r",stdin);
    freopen(F2,"w",stdout);
    #endif // ONLINE_JUDGE
    int sotest;
    scanf("%d",&sotest);
    //sotest=1;
    for (int test=1;test<=sotest;test++){
        init();
        printf("Case #%d: ",test);
        read();
        process();
        printf("\n");
    }

    return 0;
}
