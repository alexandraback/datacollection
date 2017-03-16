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

using namespace std;

bool isVowel(char c){
  return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

bool hasNcons(string s, int n){
  int best=0;
  int count=0;
  for(int i=0;i<s.size();i++){
    if(!isVowel(s[i])){
      count++;
      best=max(best,count);
    }
    else
      count=0;
  }
  return best>=n;
}

int main() 
{
  int T,N;
  string L;
  cin >> T;
  cout << hasNcons("quartz", 3);
  for(int i=1;i<=T;i++){
    cin >> L >> N;
    int x=L.size();
    int count=0;
    for(int j=0;j<x;j++){
      for(int l=1;l+j<=x;l++){
        string s = L.substr (j, l);
        if(hasNcons(s,N)) 
          count++;
      }
    }
    cout << "Case #" << i << ": " << count <<  endl;
  }

}
