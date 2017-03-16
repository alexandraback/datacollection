#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdint>

int main()
{
  int ncases = 0;
  scanf("%d", &ncases);
  for(int case_ = 1; case_ <= ncases; case_++)
  {
    int n, j;
    scanf("%d %d", &n, &j);
    printf("Case #%d:\n", case_);

    std::vector<int> primes;
    {
      std::vector<char> is_prime(1 << 20, 1);
      for(int i = 2; i < is_prime.size() / 2; i++)
        if(is_prime[i])
        {
          primes.push_back(i);
          for(int m = 2 * i; m < is_prime.size(); m += i) is_prime[m] = 0;
        }
    }

    int num_found = 0;

    for(int middle = 0; middle < (1 << (n - 2)) ; middle++)
    {
      int jc = (1 << (n - 1)) | (middle << 1) | 1;
      int divisors[10 + 1];
      std::fill_n(&divisors[0], 11, 0);
      bool none_prime = true;
      for(int base = 2; base <= 10 && none_prime; base++)
      {
        __int128_t value = 0;
        __int128_t power = 1;
        for(int i = 0; i < n; i++)
        {
          if(((jc >> i) & 1) == 1) value += power;
          power *= base;
        }
       
        for(__int128_t prime : primes)
          if(prime * prime > value)
            break;
          else if(value % prime == 0)
          {
            divisors[base] = int(prime);
            break;
          }

        none_prime = none_prime && divisors[base];
      }

      if(none_prime)
      {
        for(int i = 0; i < n; i++) printf("%d", (jc >> (n - i - 1)) & 1);
        for(int base = 2; base <= 10; base++) printf(" %d", divisors[base]);
        printf("\n"); 
        num_found++;
        if(num_found == j) break;
      }
    }
  }
}
