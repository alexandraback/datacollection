#include <iostream>

#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long

using namespace std;

ll tt,c,k,s,r,b;

int main(){
    cin >> tt;
    rep(ii,tt){
        cin >> k >> c >> s;
        cout << "Case #"<<ii+1<<": ";
        if(c*s<k){
            cout << "IMPOSSIBLE" <<endl;
            continue;
        }
        if(k%c==0)b = k/c;
        else b = (k/c)+1;

        rep(i,b){
            r = 0;
            for(int j=i*c;j<(i+1)*c;j++){
                r = r*k+j%k;
            }
            cout << r+1<<" ";
        }
        cout << endl;
    }
}

