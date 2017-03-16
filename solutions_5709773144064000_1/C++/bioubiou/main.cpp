#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    //freopen("C://Users//Jo//Downloads//B-large.in","r",stdin);
    //freopen("d://out.txt","w",stdout);
    int t;
    double ans=1000000;
    double c,f,x;
    double tt;
    double vv;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        ans=1000000;
        scanf("%lf%lf%lf",&c,&f,&x);
        tt=0;
        vv=2;
        while(ans>=tt+x/vv){
            ans=tt+x/vv;
            tt+=c/vv;
            vv+=f;
        }
        printf("Case #%d: %.7lf\n",cas,ans);
    }
    return 0;
}
