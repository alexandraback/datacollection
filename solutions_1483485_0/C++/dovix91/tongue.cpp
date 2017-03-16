#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
using namespace std;

const char tran[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int T;
string s;

int main() {

   int i, j;
   
   cin>>T;
   getline(cin, s);

   for(i=0; i<T; i++) {
      getline(cin, s);
      cout<<"Case #"<<i+1<<": ";
      for(j=0; j<s.size(); j++) {
         if('a'>s.at(j) || 'z'<s.at(j)) cout<<s.at(j);
         else {
            cout<<tran[s.at(j)-'a'];
         }
      }
      cout<<endl;  
   }
   
   return 0;

}
