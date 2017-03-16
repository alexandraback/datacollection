#include<bits/stdc++.h>
using namespace std;
int a,s,d[2502],f,g,h,j,k,l,i,n,m;
main(){
    freopen("out.txt","w",stdout);
    cin>>n;
    for(i=0;i<n;i++){
        cin>>m;
        cout<<"Case #"<<i+1<<": ";
        for(a=0;a<2*m-1;a++){
            for(j=0;j<m;j++){
            cin>>k;
            d[k]++;
            }
        }
        for(a=1;a<=2500;a++){
            if(d[a]%2==1) cout<<a<<" ";
            d[a]=0;
        }
        cout<<endl;
    }
}
