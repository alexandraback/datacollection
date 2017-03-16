#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int A[1005][1005];
int main(){
    int t;
    cin >> t;
    int index=1;
    while(t--){
           int n;
           cin >> n;
        map<int,int> M;
        for(int i=1;i<2*n;++i){
            for(int j=1;j<=n;++j){
                int a;
                cin >> a;
                ++M[a];
            }
        }
        map<int,int> ::iterator it=M.begin();
        vector<int> ans;
        while(it!=M.end()){
            if((*it).second%2){
                ans.push_back((*it).first);

            }
            ++it;
        }




        cout << "Case #" << index++ << ": ";
        for(int i=0;i<ans.size();++i)
            cout << ans[i] << " ";
        cout << endl;

    }
    return 0;
}
