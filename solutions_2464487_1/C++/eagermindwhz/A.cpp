#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    freopen("A.in","r",stdin);
    freopen("output2.txt","w",stdout);
    int T;
    cin>>T;
    for (int cas = 1; cas <= T; cas++){
        long long r,t;
        cin>>r>>t;
        double dr = 1.0*r, dt=1.0*t; //dn = ((1-2*dr)+sqrt((2*dr-1)*(2*dr-1)+8*t))/4;
        double l = 0.0, tr = 100000000000000.0;
        while (fabs(l-tr)>1e-3){
            double mid = (l+tr)/2;
            if ((2*mid*mid+(2*dr-1)*mid-t)<=0) l = mid;
            else tr = mid;
        }
        long long ans;
        if (fabs((long long)(l+1) - l) <1e-5) ans = (long long)(l+1);
        else ans = (long long)l;
        if (ans == 0) ans = 1;
        cout<<"Case #"<<cas<<": "<<ans<<endl;
        /*long long tn = (int)dn, ans;
        for (i = -delta;i < delta; i++){
            ans =
        }*/
    }
    return 0;
}

