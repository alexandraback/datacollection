#include <bits/stdc++.h>
#define MA(a,b) ((a)>(b)?(a):(b))
#define MI(a,b) ((a)<(b)?(a):(b))
#define AB(a) (-(a)<(a)?(a):-(a))
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define ep 0.00000001
#define pi 3.1415926535897932384626433832795
#define na(x) ((x)<P?(x):(x)-P)
using namespace std;
double difmin=10000000.0;

bool ch(int d1,int v1,int d2,int v2){
    if (v1>v2) return 0;
    if (v1==v2) return 0;
    //difmin=min(difmin,AB(1.0*(360-d2)*v2*(v2-v1)-1.0*(360-d1+d2)*v1*v2));
return  (1ll*(360-d2)*(v2-v1)>1ll*(360-d1+d2)*v1);
}
int main() {
    freopen("C8.in","r",stdin);
    freopen("textC8.txt","w",stdout);

    int t;
    cin>>t;
    for (int tt=1;tt<=t;tt++){
        int A=10,D,H,M;
        vector <int> v,d;
        int n;
        cin>>n;
        d.clear();
        v.clear();
        while (n--){
            cin>>D>>H>>M;
            for (int i=0;i<H;i++)
            v.pb(i+M),d.pb(D);
        }
        n=v.size();
        int k=0;
        for (int B=0;B<(1<<n);B++){
            int f=1;
            for (int i=0;i<n && f;i++)
            if (B&(1<<i))
            for (int j=0;j<n && f;j++)
            if (B&(1<<j))
            f=(f && ch(d[i],v[i],d[j],v[j])==0);
            if (f){
                k=0;
                for (int i=0;i<n;i++)
                k+=((B&(1<<i))>0);
                A=min(A,n-k);
            }
        }

        printf("Case #%d: %d\n",tt,A);
    }
   // cout<<difmin<<endl;
    return 0;
}
