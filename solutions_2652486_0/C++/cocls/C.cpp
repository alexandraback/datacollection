#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

vector<int> primes = {2, 3, 5};

void make(){
  int r, n, m, k;
  scanf("%d%d%d%d", &r, &n, &m, &k);
  printf("\n");
  vector<int> products(k);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < k; ++j) {
      scanf("%d", &products[j]);
    }
    vector<int> guess(m+1, 0);
    int guess_sum = 0;
    bool have2 = false;
    int max2 = 0;
    for (int j = 0; j < k; ++j) {
      int num = products[j];
      vector<int> prime_num(primes.size(), 0);
      int prime_p = 0;
      while (num > 1) {
	if (num%primes[prime_p] == 0) {
	  num /= primes[prime_p];
	  prime_num[prime_p]++;
	} else {
	  prime_p++;
	}
      }
      guess[3] = max(guess[3], prime_num[1]);
      guess[5] = max(guess[5], prime_num[2]);
      if (prime_num[0]%2 == 1) {
	have2 = true;
      }
      max2 = max(max2, prime_num[0]);
    }
    int left = n - guess[3] - guess[5];
    if (left >= max2) {
      guess[2] = left;
    } else if (have2) {
      if (max2%2 == 0) {
	guess[2] = 2;
	max2 -= guess[2];
	left -= guess[2];
	guess[4] += max2 - left;
	guess[2] += max2 - 2*guess[4];
      } else {
	guess[2] = 1;
	max2 -= guess[2];
	left -= guess[2];
	guess[4] += max2 - left;
	guess[2] += max2 - 2*guess[4];
      }
    } else {
      if (max2%2 == 0) {
	guess[2] = 0;
	max2 -= guess[2];
	left -= guess[2];
	guess[4] += max2 - left;
	guess[2] += max2 - 2*guess[4];
      } else {
	guess[2] = 1;
	max2 -= guess[2];
	left -= guess[2];
	guess[4] += max2 - left;
	guess[2] += max2 - 2*guess[4];
      }
    }
    for (int i = 2; i <= m; ++i) {
      for (int j = 0; j < guess[i]; ++j) {
	printf("%d", i);
      }
    }
    printf("\n");
  }
}

int main(){
  freopen("C-small-1-attempt1.in", "r", stdin);
  freopen("C-small.out", "w", stdout);
  
  int test_n;
  scanf("%d", &test_n);
  for (int test_i = 1; test_i <= test_n; ++test_i) {
    printf("Case #%d: ", test_i);
    make();
  }
  return 0;
}
