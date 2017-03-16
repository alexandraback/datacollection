#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <fstream>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

ll ex[50];

int main(){
  ifstream myfile;
  myfile.open ("awesome.in");
  ofstream a_file ( "example.out" );

  
  ex[0] = 1;
  for(int i = 1; i <= 49; i++) {
    ex[i] = 2 * ex[i - 1];
  }
  
  int t; myfile >> t;
  for(int i = 1; i <= t; i++) {
    a_file<<"Case #"<<i<<": ";
    ll b, m;
    myfile >> b >> m;
    if(m > ex[b - 2]) {
      a_file << "IMPOSSIBLE" << endl;
      continue;
    }
    else {
      a_file << "POSSIBLE" << endl;
    }
    
    ll chain[b - 1];
    chain[0] = 1;
    for(int j = 1; j < b - 1; j++) {
      chain[j] = ex[j - 1];
    }
    ll sum = 0;
    
    while(sum < m) {
      int j = b - 2;
      for(j = b - 2; chain[j] == 0 || sum + chain[j] > m; j--){
        //fout<<chain[j]<<endl;
      }
      //fout<<j<<' '<<chain[j]<<endl;
      sum += chain[j];
      chain[j] = 0;
    }
    
    for(int j = 0; j < b; j++) {
      for(int k = 0; k <= j; k++) {
        a_file << 0;
      }
      for(int k = j + 1; k < b - 1; k++) {
        a_file << 1;
      }
      if(j == b - 1) {
        
      }
      else if(chain[j] == 0) {
        a_file << 1;
      }
      else {
        a_file << 0;
      }
      a_file << endl;
    }
  }
  return 0;
}