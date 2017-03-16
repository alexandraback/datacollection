#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    freopen("1D1.in","r",stdin);
    freopen("out","w",stdout);
    int t;
    cin>>t;
    int t2 = 0;
    while(t--){
               
               int x,r,c;
               cin>>x>>r>>c;
               cout<<"Case #"<<++t2<<": ";
               if(x >= 7) cout<<"RICHARD"<<endl;
               else if(r*c%x!=0){
                            cout<<"RICHARD"<<endl;
                            }
               else{
                    if(r<c){
                            r^=c^=r^=c;
                            }
                    if((x+1)/2 > c){
                             cout<<"RICHARD"<<endl;
                             }
                    else if(x>=4&&(x+1)/2==c&&(x+1)/2+(x+1)%2+1>=r){
                                         cout<<"RICHARD"<<endl;
                                         }
                    else{
                         cout<<"GABRIEL"<<endl;
                         }
                    }
               }
    }