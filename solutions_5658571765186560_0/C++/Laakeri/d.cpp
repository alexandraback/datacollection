#include <bits/stdc++.h>
using namespace std;
int main(){
    int tcs;
    cin>>tcs;
    for (int tc=1;tc<=tcs;tc++){
        cout<<"Case #"<<tc<<": ";
        int x,r,c;
        cin>>x>>r>>c;
        if (c>r) swap(r, c);
        int w=0;
        if (x<7){
            if ((r*c)%x==0){
                if (x>3){
                    if ((x+1)/2<c){
                        if (x<=r){
                            w=1;
                        }
                    }
                }
                else{
                    if ((x+1)/2<=c){
                        if (x<=r){
                            w=1;
                        }
                    }
                }
            }
        }
        if (w){
            cout<<"GABRIEL"<<endl;
        }
        else{
            cout<<"RICHARD"<<endl;
        }
    }
}
