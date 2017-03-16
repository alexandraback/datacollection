#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

ifstream fin("A-large.in");
ofstream fout("my.out");

int main(){
  int m,n;

  fin >> m;

  for(int index=1; index<=m; index++){
    fin >> n;
    char c;
    int stand = 0;
    int res = 0;
    for(int i=0; i<=n; i++){
      fin >> c;
      int k = c - '0';
      if(stand>=i){
        stand += k;
      }
      else{
        res += (i - stand);
        stand = i+k;
      }
    }
    fout << "Case #" << index << ": " << res << endl; 
  }
  return 0;
}