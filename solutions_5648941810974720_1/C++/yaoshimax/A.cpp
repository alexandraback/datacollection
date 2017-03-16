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

int main(){
  int n_case;
  cin >> n_case;
  int cnt[30];
  for( int loop = 0 ; loop < n_case ; loop++ ){
   string ansStr ="";
   memset(cnt,0,sizeof(cnt));
   string s;
   cin >> s;
   for( int i = 0 ; i < (int) s.size(); i++ ){
      cnt[s[i]-'A']++;
   }
   while( cnt['W'-'A']>0 ){
      cnt['T'-'A']--;
      cnt['W'-'A']--;
      cnt['O'-'A']--;
      ansStr+="2";
   }
   while( cnt['G'-'A']>0 ){
      cnt['E'-'A']--;
      cnt['I'-'A']--;
      cnt['G'-'A']--;
      cnt['H'-'A']--;
      cnt['T'-'A']--;
      ansStr+="8";
   }
   while( cnt['Z'-'A']>0 ){
      cnt['Z'-'A']--;
      cnt['E'-'A']--;
      cnt['R'-'A']--;
      cnt['O'-'A']--;
      ansStr+="0";
   }
   while( cnt['X'-'A']>0 ){
      cnt['S'-'A']--;
      cnt['I'-'A']--;
      cnt['X'-'A']--;
      ansStr+="6";
   }
   while( cnt['U'-'A']>0 ){
      cnt['F'-'A']--;
      cnt['O'-'A']--;
      cnt['U'-'A']--;
      cnt['R'-'A']--;
      ansStr+="4";
   }
   while( cnt['F'-'A']>0 ){
      cnt['F'-'A']--;
      cnt['I'-'A']--;
      cnt['V'-'A']--;
      cnt['E'-'A']--;
      ansStr+="5";
   }
   while( cnt['V'-'A']>0 ){
      cnt['S'-'A']--;
      cnt['E'-'A']--;
      cnt['V'-'A']--;
      cnt['E'-'A']--;
      cnt['N'-'A']--;
      ansStr+="7";
   }
   while( cnt['O'-'A']>0 ){
      cnt['O'-'A']--;
      cnt['N'-'A']--;
      cnt['E'-'A']--;
      ansStr+="1";
   }
   while( cnt['R'-'A']>0 ){
      cnt['T'-'A']--;
      cnt['H'-'A']--;
      cnt['R'-'A']--;
      cnt['E'-'A']--;
      cnt['E'-'A']--;
      ansStr+="3";
   }
   while( cnt['N'-'A']>0 ){
      cnt['N'-'A']--;
      cnt['I'-'A']--;
      cnt['N'-'A']--;
      cnt['E'-'A']--;
      ansStr+="9";
   }

   sort(ansStr.begin(),ansStr.end());
   cout << "Case #" << loop+1 << ": " <<ansStr<< endl;
  }
  return 0;
}
