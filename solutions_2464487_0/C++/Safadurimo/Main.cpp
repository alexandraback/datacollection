#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <ctime> 

using namespace std;

typedef string Date;

int main() 
{
  int T;
  int r,t;
  cin >> T;
  int count=0;
  for(int i=1;i<=T;i++){
    cin >> r >> t;
    count=0;
    while(t>0){
      int next=(r+1)*(r+1)-r*r;
      if(next<=t){
        count++;
        t-=next;
        r+=2;
      }
      else
        break;
    }
    cout << "Case #" << i << ": " << count << endl;
  }
}
