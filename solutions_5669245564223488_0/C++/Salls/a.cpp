#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <cstdlib>
#include <cstring>

using namespace std;

string removeDup(string s){
string result;
char last = '0';
for(int i = 0; i<s.size();i++){
   if(s[i]!=last)
      result.push_back(s[i]);
   last = s[i];
}

return result;
}

int counts[26];

void solve() {
   int N;
   cin >> N;

   vector<string> cars1;
   for(int i = 0; i < N; i++){
      string s;
      cin >> s;
      cars1.push_back(s);
   }

   vector<string> cars;
   for(int i = 0; i < N; i++)
      cars.push_back(removeDup(cars1[i]));

   vector<int> order;
   for(int i = 0; i < N; i++)
      order.push_back(i);

   int count = 0;
   do{
      memset(counts,0,sizeof(counts));

      bool good = true;
      char last = '0';
      for(int i = 0; i < N; i++){
         string s = cars[order[i]];
         for(int j = 0; j < s.size(); j++){
            if(counts[s[j]-'a'] > 0 && s[j] != last)
               good = false;
            last = s[j];
            counts[s[j]-'a']++;
         }
      }
      if(good)
         count++;

   } while(next_permutation(order.begin(),order.end()));
   cout << count;
}

int main() {

int t;
cin >> t;
for (int i = 0; i < t; i++) {
   cout << "Case #" << i+1 << ": "; 
   solve();
   cout << endl;
}


return 0;
}
