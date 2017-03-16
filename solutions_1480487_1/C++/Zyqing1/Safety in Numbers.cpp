#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=210;
const double eps=1e-6;
int n,s[maxn],sum;

double calc(int p)
{
    double l=0,r=100,mid,rest;
    while(r-l>eps){
        mid=(l+r)/2;
        double tmp=s[p]+sum*mid;
        rest=100-mid;
        //cout<<tmp<<" "<<rest<<endl;
        for(int i=0;i<n;i++){
            if(i!=p && s[i] < tmp){
                rest -= (tmp-s[i])/sum;
                if(rest<0) break;
            }
            //printf("i=%d,rest=%f,mid=%f\n",rest,mid);
        }
        if(rest < 0) r=mid;
        else l=mid;
    }
    return mid;
}
void solve()
{
    for(int i=0;i<n;i++){
        //printf("s[%d]=%d: ",i,s[i]);
        printf(" %.5f",calc(i));
    }
    puts("");
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T;
    cin >> T;
    for(int cas=1; cas <= T; cas ++){
        cin >> n;
        sum=0;
        for(int i = 0; i < n ; i ++){
            cin>>s[i];
            sum+=s[i];
            s[i]*=100;
        }
        printf("Case #%d:",cas);
        solve();
    }
    return 0;
}
/*
1
2 20 10
*/
