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


int main() 
{
  int T,X,Y;
  cin >> T;
  for(int i=1;i<=T;i++){
    cin >> X >> Y;
    string res="";
    while(X>0){
      res+="WE";
      X--;
    }
     while(X<0){
      res+="EW";
      X++;
    }
     while(Y>0){
      res+="SN";
      Y--;
    }
     while(Y<0){
      res+="NS";
      Y++;
    }
    assert(res.size()<=500);
    cout << "Case #" << i << ": " << res <<  endl;
  }

}
