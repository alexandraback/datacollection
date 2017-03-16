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
         int i = N - 2;
         while ((i >= 1) && (v[i] == 1))
         {
            v[i] = 0;
            i--;
         }
         if ( i < 1) break;
         v[i]++;

         int count1 = 0;
         for (int i = 0; i < N; i++)
            if (v[i] == 1)
               ++count1;
         // handle 3,5,7,9
         if (count1 % 2 == 1)
            continue;
         // handle 4, 10
         if (count1 % 3 != 0)
            continue;
         int count2 = 0;
         for (int i = 0; i < N; i++)
            if ((v[i] == 1) && (i % 2 == 0))
               ++count2;
            else if ((v[i] == 1) && (i % 2 == 1))
               --count2;
         //handle 2, 8
         if (count2 % 3 != 0)
            continue;
         // handle 6
         if ((count1 % 5 != 0) && (count2 % 7 != 0))
            continue;
         ++found;
         for (int i = 0; i < N; i++)
            std::cout << v[i];
         for (int i = 2; i <= 10; i++)
            if (i % 2 == 1)
               std::cout << " 2";
            else if ((i == 4) || (i == 10))
               std::cout << " 3";
            else if ((i == 2) || (i == 8))
               std::cout << " 3";
            else if (count1 % 5 == 0)
               std::cout << " 5";
            else 
               std::cout << " 7";
         std::cout << std::endl;
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

