#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>


using namespace std;

bool valid(vector<int> products, int i , int j , int k ){
  vector<int> allproducts;
  int array[3];
  array[0]=i;array[1]=j;array[2]=k;

  for( int mask = 0 ; mask < (1<<3) ; mask++ ){
    int p = 1;
    for( int n = 0 ; n < 3 ; n++ ){
      if( (mask&(1<<n)) ) p*=array[n];
    }
    allproducts.push_back(p);
  }
  sort( allproducts.begin(), allproducts.end() );
  allproducts.erase( unique(allproducts.begin(),allproducts.end()) , allproducts.end());
  bool ok = true;
  for( int n = 0 ; n < (int)products.size(); n++ ){
    int curp = products[n];
    if( find( allproducts.begin(), allproducts.end(),curp ) == allproducts.end()){
    return false;
    }
  }
  return ok;
}

int main(){
  int n_case;
  cin >> n_case;
  for( int loop = 0 ; loop < n_case ; loop++ ){
    int R,N,M,K;
    cin >>R>>N>>M>>K;
    cout << "Case #" << loop+1 << ":"<<endl;
    for( int l = 0 ; l < R ; l++ ){
      vector<int> products;
      for( int ll = 0 ; ll < K ; ll ++ ){
        int tmp;
        cin >> tmp;
        products.push_back(tmp);
      }
      sort( products.begin(), products.end() );
      products.erase( unique( products.begin(),products.end()) , products.end());
      if( N != 3 ) cout <<"caution!" << endl;
      bool ok = false; 
      for( int i = 2 ; !ok&&i <= M ; i++ ){
       for( int j = 2 ; !ok&&j <= M ; j++){
        for( int k = 2 ; !ok&&k <= M ; k++ ){
          if( valid( products, i, j , k ) ){
            cout <<i<<j<<k<< endl;
            ok = true;
            break;
          }
        }
       }
      }
    }

  }
  return 0;
}
