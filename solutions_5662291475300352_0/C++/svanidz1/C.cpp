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

int main() {
    freopen("C4.in","r",stdin);
    freopen("textC4.txt","w",stdout);

    int t;
    cin>>t;
    for (int tt=1;tt<=t;tt++){
        int A=2,D,H,M;
        vector <int> v,d;
        int n;
        cin>>n;
        d.clear();
        v.clear();
        d.pb(0);
        v.pb(0);
        while (n--){
            cin>>D>>H>>M;
            for (int i=0;i<H;i++)
            v.pb(i+M),d.pb(D);
        }
      //  if (v.size()>3) cout<<"TEST "<<tt<<endl;
       // assert
        if (v.size()<=2) A=0; else {
            if (v[1]>v[2]) swap(v[1],v[2]),swap(d[1],d[2]);
            if (v[1]==v[2]) A=0; else
            if (1.0*(360-d[2])*v[2]*(v[2]-v[1])>=1.0*(360-d[1]+d[2])*v[1]*v[2]) A=1; else A=0;
  //          cout<<1ll*(360-d[2])*v[2]*(v[2]-v[1])<<" "<<1ll*360*(360-d[1]+d[2])*v[1]*v[2]<<endl;
        }
        printf("Case #%d: %d\n",tt,A);
    }
    return 0;
}
