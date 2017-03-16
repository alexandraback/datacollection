#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stdio.h>

using namespace std;

int main() {
   int total;
   cin >> total;
   for (int totalcount = 0; totalcount < total; ++totalcount) {
      int m, n;
      cin >> m >> n;
      int size = n - m + 1;
      bool* used = new bool[size];
      for (int i = 0; i < size; ++i) {
         used[i] = false;
      }
      int r = 0;
      for (int i = m; i <= n; ++i) {
         if (!used[i - m]) {
            used[i - m] = true;
            char buf[512];
            sprintf(buf, "%d", i);
            string s(buf);
            string tmp = s;
            int count = 1;
            if (tmp.size() >= 2) {
               //cout << "ori:" << s << endl;
               do {
                  char c = tmp[0];
                  tmp.erase(tmp.begin());
                  tmp += c;
                  int t = atoi(tmp.c_str());
                  if (t >= i && t <= n && !used[t - m]) {
                     //cout << tmp << endl;
                     used[t - m] = true;
                     ++count;
                  }
               } while (tmp != s);
            }
            r += count * (count - 1) / 2;
         }
      }
      delete[] used;
      cout << "Case #" << totalcount + 1 << ": " << r << endl;
   }
   return 0;
}
