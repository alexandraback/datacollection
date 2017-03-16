#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t ; cin >> t;
    for(int cse = 1; cse <=t ; cse ++){
      cout<<"Case #"<<cse<<": ";
      int n ;
      cin >> n ;
      map<int,int> m;
      for(int i =0 ; i < 2*n*n-n ; i ++){
        int x;
        cin >> x;
        m[x]++;
      }
      vector<int> ans;
      for(map<int,int>::iterator it = m.begin(); it != m.end(); ++it)
      {
        if( it->second %2 != 0) {
          ans.push_back(it->first);
        }
      }
      sort(ans.begin(), ans.end());
      for(int i =0 ; i <ans.size(); i ++){
        cout<<ans[i];
        if( i != ans.size()-1) cout<<" ";
        else cout<<endl;
      }
    }
}
