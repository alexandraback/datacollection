#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <math.h>
#define ll long long int
using namespace std;


int main () {
  int T;
  int i, j, k;
  
  cin>>T;
  map<char,bool> vog;
  
  vog['a'] = true;
  vog['e'] = true;
  vog['i'] = true;
  vog['o'] = true;
  vog['u'] = true;
  for (k = 0; k < T; k++) {
    ll sum = 0;
    int n;
    int begin = 0;
    string s;
    
    cin>>s>>n;
    int con = 0;
    bool has = false;
    for (i = 0; i < s.size(); i++) {
      con = 0;
      has = false;
      for (j = i; j < s.size(); j++) {
        if (!vog[s[j]]) {
          con++;
        }
        else 
          con = 0;
        
        if(con >= n)
          has = true;
        
        if(has)
          sum++;
        //printf("\t%d,%d, %d, %d : %lld\n",i, j,con, has, sum);
      }
    }
  
    
    cout<<"Case #"<<(k+1)<<": "<<sum<<endl;
    
  }

}
