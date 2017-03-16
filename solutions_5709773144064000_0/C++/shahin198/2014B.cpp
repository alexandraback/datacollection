#include<bits/stdc++.h>
using namespace std;
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
const double eps = 1e-9;
int main(){
    //FILEIO("B-small-practice");
    freopen("B-small-attempt5.in","r",stdin);
    freopen("B-small-attempt5.out","w",stdout);

    int t,i;
    double c,f,x,v,tt=0.0,s=0.0,d,ct,tm,tn;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        s=0.0;
        tt=0.0;
        d=2.0;
        ct=0;
        cin>>c>>f>>x;
       while(1)
        {
            tm=tt+c/d+x/(d+f);
            tn=tt+x/d;
            ct=ct+c;
            if(tn<tm||ct>=x)
            {
                break;
            }
            tt=tt+c/d;
            d=d+f;
        }
        s=tn;
        printf("Case #%d: %.7lf\n",i,s);
    }
    return 0;
}


