#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#define pb push_back
#define rep(i,n) for(i=0;i<n;i++)
typedef long long ll;
typedef long double ld;
using namespace std;

long int gcd(long int a,long int b){
    if(a<b)
        swap(a,b);
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main() {
    double t,p,q,i,ans;
   long int a,b;
   char ch;



     i=0;
    cin>>t;

    while(t--){
        cin>>p>>ch>>q;
        ans = 0;
        a = p;
        b = q;

        p /= gcd(a,b);
        q /= gcd(a,b);

            if(p/q >= 1){
                    cout<<"Case #"<<++i<<": "<<"impossible"<<endl;
                    continue;
                }
            ans = ceil(  log(q/p)/log(2)  );


            a = q;
            if(  (a & (a-1) ) != 0   )
                cout<<"Case #"<<++i<<": "<<"impossible"<<endl;
            else
                cout<<"Case #"<<++i<<": "<<ans<<endl;


    }



    return 0;
}
