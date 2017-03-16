#include <iostream>
#include <set>

using namespace std;

void recordDigit(uint64_t n, set<uint64_t>& s) {
   uint64_t x = n;
   while (x) { s.insert(x % 10); x /= 10; }
}

void print(uint64_t n) {
   if (n == 0) {
      cout << "INSOMNIA";
      return;
   }
   uint64_t x = n;
   set<uint64_t> s; s.clear();
   while (true) {
      recordDigit(x, s);
      //cout << "count " << x << endl;
      if (s.size() == 10) break;
      x += n;
   }
   cout << x;
}

int main() {
   uint64_t T; cin >> T;
   for (uint64_t i = 1; i <= T; ++i) {
      uint64_t N; cin >> N;
      cout << "Case #" << i << ": ";
      print(N); cout << endl;
   }
   return 0;
}
