#include <iostream>

#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long

using namespace std;

ll tt,c,k,s,r;

int main(){
    cin >> tt;
    rep(ii,tt){
        cin >> k >> c >> s;
        cout << "Case #"<<ii+1<<": ";
        rep(i,s){
            r = 0;
            rep(j,c){
                r = r*k+i;
            }
            cout << r+1 <<" ";
        }
        cout << endl;
    }

}

