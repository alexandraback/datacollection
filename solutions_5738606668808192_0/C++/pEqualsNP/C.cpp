#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <cmath> 

using namespace std;
typedef long long LL;

typedef unsigned long long int ULL;


ULL get_divisor(ULL n);
ULL base(const std::vector<int>& N, int base);

main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": " << std::endl;
      int N, J;
      std::cin >> N >> J;
      std::vector<int> v(N);
      v[0] = 1;
      v[N - 1] = 1;
      for (int i = 1; i < N - 1; i++)
         v[i] = 0;
      int found = 0;
      while (found < J)
      {
         std::vector<ULL> divisor(11);
         bool isPrime = true;
         for (int i = 2; i <= 10; i++) 
         {
            ULL num = base(v, i);
            divisor[i] = get_divisor(num);
            if (divisor[i] == 0) {
               isPrime = false;
               break;
            }
         }
         if (isPrime) {
            for (int i = 0; i < N; i++)
               std::cout << v[i];
            for (int i = 2; i <= 10; i++)
               std::cout << " " << divisor[i];
            std::cout << std::endl;
            found++;
         }
         int i = N - 2;
         while ((i >= 1) && (v[i] == 1))
         {
            v[i] = 0;
            i--;
         }
         if ( i < 1) break;
         v[i]++;
      }

   }
	exit(0);
}

ULL get_divisor(ULL n)
{
   if (n <= 3)
      return 0;
   if (n == 4)
      return 2;
   for (int i = 2; i <= (ULL) (sqrt(n)) + 1; i++)
      if (n % i == 0)
         return i;
   return 0;
}

ULL base(const std::vector<int>& N, int base)
{
   ULL exp = 1;
   ULL num = 0;
   for (int i = N.size() - 1; i >= 0; i--)
   {
      num += N[i] * exp;
      exp = exp * base;
   }
   return num;
}

