#include <iostream>

using namespace std;

typedef long long ll;

ll t, c, d, v, curmax;
ll a;
ll res;

int main(){
    cin>>t;
    for(int i=0; i<t; ++i){
        res=0;
        cin>>c>>d>>v;
        curmax=0;
        for(int j=0; j<d; ++j){
            cin>>a;
            while(curmax+1<a){
                curmax+=c*(curmax+1);
                ++res;
            }
            curmax+=c*(a);
        }
        while(curmax<v){
            curmax+=c*(curmax+1);
            ++res;
        }
        cout<<"Case #"<<i+1<<": "<<res<<"\n";
    }
}
