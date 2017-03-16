#include <iostream>
#include <cstring>
using namespace std;
int coins[31];
bool change[31];

int get_moneyz(int n,int bits){
    int ans = 0;
    for(int i=0;i<bits;++i){
        if(n&(1<<i)) ans+= coins[i];
    }
    return ans;
}

int main(){
    int T;
    int C,D,V, ans, counter = 1;
    cin>>T;
    while(T--){
        cin>>C>>D>>V;
        for(int i=0;i<D;++i)
            cin>>coins[i];
        memset(change, 0, sizeof change);      
        ans= 0;

        for(int i=0;i<(1<<D);++i){
            int t = get_moneyz(i,D);
            if(t<=V){
                change[t] = true;
            }    
        } 

        int k = 1;
        while(k<=V){
        if(change[k]){
            k++;
            continue;
        }

        coins[D] = k;
        ++D;
        ++ans;

        for(int i=0;i<(1<<D);++i){
            int t = get_moneyz(i,D);
            if(t<=V){
                change[t] = true;
            }
        }
        k++;
        }

        cout<<"Case #"<<counter++<<": "<<ans<<endl;
    }
    return 0;
}
