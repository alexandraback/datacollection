#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
using namespace std;
typedef long long LL;

//*******************
int K, L, S;
string keyboard, target;
vector<string> all;
unordered_map<char, int> l_count;
//*******************

void read() {
   cin >> K >> L >> S;
   cin >> keyboard >> target;
}

void gen(string &t) {
   if(t.size() == S) {
      all.push_back(t);
      return;
   }
   for(char c : keyboard) {
      t.push_back(c);
      gen(t);
      t.pop_back();
   }
}

int count_string(const string &s, const string &target) {
   int counter = 0;
   for(int i = 0; i <= s.size() - target.size(); ++i) {
      int j = 0, k = i;
      while(j < target.size() && s[k] == target[j]) ++k, ++j;
      if(j == target.size()) ++counter;
   }
   return counter;
}

double solve() {
   string t;
   gen(t);
   int result = 0;
   int max_count = 0;
   for(string &s : all) {
      int c = count_string(s, target);
      max_count = max(c, max_count);
      result += c;
   }
   return (double) max_count - (double) result / all.size();
}

void clean() {
   l_count.clear();
   all.clear();
}

int main() {
   ios::sync_with_stdio(false);
   int z;
   cin >> z;
   for(int i = 1; i <= z; ++i) {
      read();
      cout << "Case #" << i << ": " << fixed << setprecision(9) << solve() << endl;
      clean();
   }
   return 0;
}