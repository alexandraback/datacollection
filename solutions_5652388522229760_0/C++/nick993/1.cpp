#include <iostream>
#include <stdio.h>
#include <algorithm>

#define ll unsigned long long

using namespace std;

ll returnMask(ll num) {
    ll mask=0;
    while(num>=0) {
        mask|=(1<<(num%10));
        num/=10;
        if(num==0)  break;
    }
    return mask;
}


int main() {
    ios::sync_with_stdio(false);
    freopen("f1.txt","r",stdin);
    freopen("o2.txt","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        int n;
        cin>>n;
        cout<<"Case #"<<t<<": ";
        bool nosol=false;
        ll mask2=0;
        mask2=returnMask(n);
        if(mask2==1) {
            cout<<"INSOMNIA"<<endl;
        }
        else {
            ll mask=0;
            int i=0;
            while(mask!=0x3ff) {
                    i++;
                mask|=returnMask(n*i);

                if(i>100){
                    break;
                    nosol=true;
                }
            }
            if(nosol) {
                cout<<"INSOMNIA"<<endl;
            }
            else{
                cout<<n*i<<endl;
            }


        }

    }

}
