#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
string str;

inline string func(string x) {
   if (x == "") {
      return "";
   }
   char last = 'A';
   for (int i = 0 ; i < (int)x.size() ; i++) {
      last = max(last, x[i]);
   }
   int pos = 0;
   while (x[pos] != last) {
      pos++;
   }
   string ret = func(x.substr(0, pos));
   for (int i = pos ; i < (int)x.size() ; i++) {
      if (x[i] == last) {
         string blank_str = "";
         blank_str += x[i];
         ret = blank_str + ret;
      }
      else {
         ret += x[i];
      }
   }
   return ret;
}

int main() {
   cin >> N;
   for(int t = 1 ; t <= N ; t++) {
      cin >> str;
      cout << "Case #" << t << ": " << func(str) << endl;
   }
   return 0;
}
