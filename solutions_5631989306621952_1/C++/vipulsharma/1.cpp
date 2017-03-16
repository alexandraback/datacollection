#include<bits/stdc++.h>
using namespace std;
int main(){
   int t,tt = 1;
   ifstream cin("a.txt");
   ofstream cout("b.txt");
   cin >> t;
   while( t-- ){
       string x;
       cin >> x;
       string ans;
       ans += x[0];
       for(int i = 1 ; i < x.size() ; ++i ){
                  if(x[i] >= ans[0]){
                  string y;
                  y += x[i];
                  y += ans;
                  ans = y;
                  }
                  else
                  ans += x[i];
       }
     cout << "Case #"<<tt++<<": "<<ans << endl;
    }
}
