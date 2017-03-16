#include <iostream>

long long int A, B, K;
int T;

long long int compute();

int main(int argc, const char* argv[]) {
   std::cin >> T;
   for (int i = 1; i <= T; i++){
      std::cin >> A >> B >> K;
      std::cout << "Case #" << i << ": " << compute() << std::endl;
   }
   return 0;
}

long long int compute() {
   long long int r = 0;
   for (int i = 0; i < A; i++)
      for (int j = 0; j < B; j++) {
         if ((i & j) < K)
            ++r;
      }
   return r;
}

