#include <iostream>
using namespace std;
    int v[1000];
    int d[1000];
    int e,r,n;
    long ans;
void recur(int k){
     if (k<n){
        for (int i=0; i<=e; ++i)
        {
         d[k]=i;
         recur(k+1);
        }
     }
     else{
          bool ok =true;
          int ex=e;
          long a=0;
          for (int i=0; i<n; ++i){
              if (d[i]>ex){
                 ok=false;
                 break;
              }
              else{
                   a+=d[i]*v[i];
                   ex=ex+r-d[i];
                   if (ex>e)
                   ex=e;
              }
          }
          if (ok){
             if (a>ans)
                ans=a;
          }
     }
}
int main(){
    int tt,z;
    long i,j,k,t,x,f,a,b,c,nowe;
    cin>>tt;
    for (z=1; z<=tt; ++z){
                cin>>e>>r>>n;
        ans=-1;
        for (i=0; i<n; ++i){
            cin>>v[i];
            d[i]=r;
        }
        recur(0);
         cout<<"Case #"<<z<<": "<<ans<<endl; 
    }
}
