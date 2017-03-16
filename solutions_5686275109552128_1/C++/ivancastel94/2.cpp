#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int i,j,d,p,cases,c1,max,res,mov;
    cin>>cases;
    for(c1=1;c1<=cases;c1++){
        cin>>d;
        int p[d];
        max=0;
        for(i=0;i<d;i++){
            cin>>p[i];
            if(max<p[i])max=p[i];
        }
        res=1001;
        for(i=1;i<=max;i++){
            mov=0;
            for(j=0;j<d;j++){
                if(p[j]>i){
                    mov+=(p[j]-1)/i;
                }
            }
            if(res>mov+i){
                res=mov+i;
            }
        }
        cout<<"Case #"<<c1<<": "<<res<<endl;
    }
}
