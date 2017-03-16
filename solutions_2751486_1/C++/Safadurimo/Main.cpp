#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <ctime> 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <limits.h>
#include <vector>
#include <cassert>
#include <map>
#include <string>
#include <set>
#include <bitset>
#include <numeric>

using namespace std;

bool isVowel(char c){
  return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}



int main() 
{
  int T,n;
  string L;
  cin >> T;
  for(int i=1;i<=T;i++){    
    cin >> L >> n;
    int x=L.size();
    vector<long long> v(x);
    int numCons=!isVowel(L[0]) ? 1 : 0;

    v[0]= (n==1 && numCons==1) ? 1 :0;
    for(int j=1;j<x;j++){
      if(!isVowel(L[j])){
        numCons++;
      }
      else{
        numCons=0;
      }
      if(numCons<n){
        v[j]=v[j-1];
      }
      else{
        v[j] =  j - n+2;
      }
    }
    int result = accumulate(v.begin(),v.end(),0);
    cout << "Case #" << i << ": " << result <<  endl;
  }

}
