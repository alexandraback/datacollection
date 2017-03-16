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

int n;
double a[1111],b[1111];
int mark[1111];
int init(){
    for (int i=1;i<=n;i++) mark[i]=0;
    return 0;
}

int read(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lf",&a[i]);
    for (int i=1;i<=n;i++) scanf("%lf",&b[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
//    printf("\n");
//    for (int i=1;i<=n;i++) printf("%lf %lf\n",a[i],b[i]);
    return 0;
}

int process(){
    int dem=0;
    int x,y;
    y=n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (!mark[j] && b[j]>a[i]) {
                mark[j]=1;
                y--;
                break;
            }
        }
    }

    dem=0;
    x=0;
    init();
    int l,r;
    l=1;r=n;
    for (int i=1;i<=n;i++){
        if (l>r) break;
        if (a[i]<b[l]) r--;
        else {
            x++;
            l++;
        }
    }
    printf("%d %d",x,y);
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
