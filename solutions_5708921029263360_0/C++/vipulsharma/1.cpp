#include<bits/stdc++.h>
using namespace std;
int main(){
  ifstream cin("a.txt");
  ofstream cout("b.txt");

   int t , tt = 1;
   cin >> t;
   while( t--){

       int a  , b , c , d;
       cin >> a >> b >> c >> d;
       vector< pair< int , pair< int,int > > > v;
       int A[11][11]  = {0} , B[11][11] = {0} , C[11][11] = {0};
       for(int i = 1 ; i <= a ; ++i ){
        for( int j = 1 ; j <= b ; ++j ){
          for(int k = 1 ; k <= c ; ++k ){
            A[i][j]++;
            B[j][k]++;
            C[i][k]++;
             if(A[i][j] <= d && B[j][k] <= d && C[i][k] <= d )
             v.push_back({i,{j,k}});
             else {
            A[i][j]--;
            B[j][k]--;
            C[i][k]--;
             }
          }
        }
       }
       cout << "Case #"<<tt++<<": "<< v.size() << endl;
        for(int i = 0 ; i < v.size() ; ++i )
         cout << v[i].first <<" "<< v[i].second.first <<" "<<v[i].second.second << endl;
   }
  return 0;
}
