#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 256
struct rec {
    double pos,ans;
    int num;
};
int cmp(rec a,rec b) {
    return a.pos<b.pos;
}
int cmp2(rec a, rec b) {
    return a.num<b.num;
}
double sum,sum1;
int n,n2;
rec b[N];

int main() {
    freopen("A-large.in","r",stdin);
    freopen("large.txt","w",stdout);

    int T;
    cin>>T;
    for (int tt=1; tt<=T; tt++) {
        cin>>n;
        n2=n;
        sum=sum1=0;
        for (int i=1; i<=n; i++) {
            scanf("%lf",&b[i].pos);
            sum+=b[i].pos;
            b[i].num=i;
            b[i].ans=0;
        }
        sum1=sum;
        sort(b+1,b+1+n,cmp);
        for (int i=n; i>=1; i--)
            if (sum+sum1-n*b[i].pos<0.000000001) {
                sum1-=b[i].pos;
                n--;
            }
        if (sum1>0.000000001)
            for (int i=1; i<=n; i++)
                b[i].ans=(sum+sum1-n*b[i].pos)/(n*sum),b[i].ans=b[i].ans*100;
        else {
            for (int i=1; i<=n; i++)
                b[i].ans=100.0/n;
        }
        printf("Case #%d:",tt);
        sort(b+1,b+1+n2,cmp2);
        for (int i=1; i<=n2; i++)
            printf(" %.7lf",b[i].ans);
        printf("\n");
    }
}
