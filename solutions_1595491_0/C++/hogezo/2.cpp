#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int hoge(int a){
  if(a < 0) return 0;
  return a;
}

int main(){
  int t,n,s,p,a,b,ans;
  vector<int> scores;
  cin >> t;
  for(int i = 0; i < t; i++){
    ans = 0; scores.clear();
    cin >> n >> s >> p;
    while(n--){
      cin >> a; scores.push_back(a);
    }
    sort(scores.begin(),scores.end(),greater<int>());
    
    for(int j = 0; j < scores.size(); j++){
      if(scores[j] >= p*3-2){
        ans++;
      } else if(s > 0 && scores[j] >= ( p + hoge(p-2)*2 ) ){
        ans++; s--;
      }
    }
    cout << "Case #" << i+1 << ": " << ans << endl;; 
  }
  return 0;
}
