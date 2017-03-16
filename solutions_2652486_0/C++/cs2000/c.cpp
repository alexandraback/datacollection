#include <iostream>
using namespace std;
int num[7];
int c[64];
int d[64][3];
int main(){
    int i,j,k,t,r,n,m;
    for (i=0; i<=3; ++i)
        for (j=0; j<=3; ++j)
        for (k=0; k<=3; ++k){
            c[i*16+j*4+k]=(i+2)*(j+2)*(k+2);
            d[i*16+j*4+k][0]=i+2;
            d[i*16+j*4+k][1]=j+2;
            d[i*16+j*4+k][2]=k+2;
        }
    int temp;
    for (i=0; i<64; ++i)
    for (j=0; j<63; ++j){
        if (c[j]<c[j+1]){
           temp=c[j+1];
           c[j+1]=c[j];
           c[j]=temp;
           temp=d[j+1][0];
           d[j+1][0]=d[j][0];
           d[j][0]=temp;
           temp=d[j+1][1];
           d[j+1][1]=d[j][1];
           d[j][1]=temp;
           temp=d[j+1][2];
           d[j+1][2]=d[j][2];
           d[j][2]=temp;
        }
    }
    cout<<"Case #1:"<<endl;
    cin>>t;
    cin>>r>>n>>m>>k;
    for (int zz=0; zz<r; ++zz){
        int ma=0;
        for (i=0; i<k; ++i){
            cin>>num[i];
            if (num[i]>ma)
               ma=num[i];
        }
       // cout<<"AA"<<ma<<endl;
        bool ok= false;
        for (i=0; i<64; ++i){
            if (c[i]==ma){
               cout<<d[i][0]<<d[i][1]<<d[i][2]<<endl;
               ok=true;
               break;
            }
        }
        if (!ok){
           if (ma==6)
           cout<<"123"<<endl;
           else if (ma==5)
           cout<<"115"<<endl;
           else if (ma==4)
           cout<<"122"<<endl;
           else if (ma==3)
           cout<<"113"<<endl;
           else if (ma==2)
           cout<<"112"<<endl;
           else
           cout<<"111"<<endl;
        }
    }
}
