#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    int n,i,j,t,cases,aux;
    bool el[3000];
    cin>>cases;
    for(t=1;t<=cases;t++){
        cin>>n;
        memset(el,0,sizeof el);
        for(i=0;i<2*n-1;i++){
            for(j=0;j<n;j++){
                cin>>aux;
                el[aux]=!el[aux];
            }
        }
        cout<<"Case #"<<t<<":";
        for(i=1;i<=2500;i++){
            if(el[i]){
                cout<<" "<<i;
            }
        }
        cout<<endl;
    }
}
