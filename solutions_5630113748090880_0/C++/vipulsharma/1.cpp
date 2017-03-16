#include<bits/stdc++.h>
using namespace std;
int main(){
   int t,tt = 1;
   ifstream cin("a.txt");
   ofstream cout("b.txt");
   cin >> t;
   while( t-- ){
     int n , x ;
     cin >> n;
     int  hsh[2501] = {0};
       for( int i = 1 ; i <= (2*n-1)*n ; ++i ){
          cin >> x;
          hsh[x]++;
       }
     cout << "Case #"<<tt++<<": ";
     for(int i = 1 ; i <= 2500 ; ++i ){
       if(hsh[i] & 1 )
       cout << i <<" ";
     }
     cout << endl;
    }
}
