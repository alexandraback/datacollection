#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;


int main(){

    int tt, n, t;

    cin>>tt;

    rep(ii,tt)
    {
        vector<int> r;
        map<int,int> cnt;

        cin >> n;
        rep(i, 2*n-1){
            rep(j,n){
                cin >> t;
                cnt[t]++;
            }
        }
        for(auto it = cnt.begin(); it!= cnt.end(); it++){
            if((*it).second%2==1){
                r.push_back((*it).first);
            }
        }
        sort(r.begin(), r.end());

        cout << "Case #"<<ii+1<<": ";
        rep(i,r.size()){
            cout << r[i] << " ";
        }
        cout<<endl;
    }
}
