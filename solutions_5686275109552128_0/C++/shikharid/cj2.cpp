#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,d;
    //ifstream cin("B-small-attempt5.in");
    //ofstream cout("out.txt");
    cin>>t;
    int tot,spe;
    for(int tt=1;tt<=t;tt++){
        cin>>d;
        int a[d],mx=0;
        for(int i=0;i<d;i++){
                cin>>a[i];
                if(a[i]>mx)mx=a[i];
        }
        int ans=mx;
        for(int i=1;i<=mx;i++){
            spe=0;

            for(int j=0;j<d;j++){

                if(a[j]>i){
                    spe+=(a[j]/i)-1;
                    if(a[j]%i){
                        spe++;
                    }
                }
            }
            spe+=i;
            if(spe<ans)ans=spe;
        }
        cout<<"Case #"<<tt<<": "<<ans<<endl;

    }
    return 0;
}
