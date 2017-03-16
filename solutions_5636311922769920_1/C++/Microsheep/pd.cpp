#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T=0,k=1;
    cin >> T;
    while(T--){
        long long K=0,C=0,S=0;
        cin >> K >> C >> S;
        //2 3 2
        if(C*S<K){
            cout << "CASE #" << k << ": IMPOSSIBLE" << endl;
        }
        else{
            cout << "CASE #" << k << ":";
            long long now=0;
            while(now<K){
                long long x=now;
                for(int b=1;b<C;b++){
                    x=x*K+min(K-1,now+b);
                }
                now=now+C;
                cout << " " << x+1;
            }
            cout << endl;
        }
        k++;
    }
    return 0;
}
