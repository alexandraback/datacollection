#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

typedef long long LL;
const double pi=acos(-1);

int main(){
    int cas,tt=0;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    LL l,r,mid;
    //double tmp,s,rr;
    LL s,rr;
    //printf("%lf\n",pi);
    scanf("%d",&cas);
    while(cas--){
        //scanf("%lf%lf",&rr,&s);
        cin>>rr>>s;
        l=0;  r=s/(2*rr+1);
        while(l<r){
            mid=(l+r+1)/2;
            if(2*rr+2*mid-1==s/mid){l=mid;break;}
            else if(2*rr+2*mid-1<=s/mid)l=mid;
            else r=mid-1;
        }
        printf("Case #%d: ",++tt);
        cout<<l<<endl;
    }
    return 0;
}
