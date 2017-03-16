#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int main(){
    freopen ("out.out","w",stdout);
    int tcs;
    cin>>tcs;
    for (int tc=1;tc<=tcs;tc++){
        cout <<"Case #"<<tc<<": ";
        int a,b,k;
        cin>>a>>b>>k;
        ll t1=0;
        for (int i=0;i<a;i++){
            for (int ii=0;ii<b;ii++){
                //cout <<i<<" "<<ii<<" "<<(i&ii)<<endl;
                if ((i&ii)<k) t1++;
            }
        }
        cout <<t1<<endl;
    }
}
