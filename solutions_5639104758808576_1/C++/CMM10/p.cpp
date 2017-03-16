#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cmath>
#include <stack>
#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
  freopen("in", "r", stdin);
  freopen("out", "w", stdout); 
  int tt;
  cin >> tt;
  for(int i=0; i<tt; ++i){
   int smax; cin >> smax;
   string a; cin >> a;
   int p=0, res=0;
   for(int j=0; j<smax+1; ++j){
     int aux = (int) a[j]-'0';
     if(aux > 0)
       while(p<j){ ++p; ++res; }

     p += aux;
   }
   cout << "Case #" << i+1 << ": " << res << endl;
  }
}