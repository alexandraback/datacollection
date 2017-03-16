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
int dif(string a, string b){
   return abs(atoi(a.c_str())-atoi(b.c_str()));
}

int main(){
  int n_case;
  cin >> n_case;
  for( int loop = 0 ; loop < n_case ; loop++ ){
    string c,j;
    cin >> c >> j;
    vector<string> cvec;
    vector<string> jvec;
    cvec.push_back(c);
    jvec.push_back(j);
    int size = c.size();
    for( int i = 0 ; i < size; i++ ){
      if( c[i]=='?'){
         vector<string> vec2;
         for( int k=0; k < (int)cvec.size(); k++ ){
            string cv=cvec[k];
            for( int d = 0 ; d <=9 ; d++ ){
               cv[i]=('0'+d); 
               vec2.push_back(cv);
            }
         }
         cvec=vec2;
      }
      if( j[i]=='?'){
         vector<string> vec2;
         for( int k=0; k < (int)jvec.size(); k++ ){
            string cv=jvec[k];
            for( int d = 0 ; d <=9 ; d++ ){
               cv[i]=('0'+d); 
               vec2.push_back(cv);
            }
         }
         jvec=vec2;
      }
    }
    int dif_min=INT_MAX;
    string cans="999";
    string jans="999";
    for( int i = 0 ; i < (int) cvec.size(); i++){
      for(int k=0; k < (int) jvec.size(); k++ ){
         int curdif=dif(cvec[i],jvec[k]);       
         if( curdif<dif_min || (curdif==dif_min && cvec[i]<cans) ){
            cans=cvec[i];
            jans=jvec[k];
            dif_min=curdif;
         }
      }
    }
    cout << "Case #" << loop+1 << ": " <<cans <<" " << jans << endl;
  }
  return 0;
}
