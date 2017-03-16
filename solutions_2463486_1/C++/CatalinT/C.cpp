#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

inline int ispali(long long X) {
  long long Y = 0;
  long long x = X;
  while (x) Y *= 10, Y += x % 10, x /= 10;
  return X == Y;
}

inline int isok(long long x, int X) {
//  if (x <= X && ispali(x*x))
//    printf("%d\n", x);

  return x <= X && ispali(x*x);
}

int paliLessThan(int X) {
  if (X == 1000000) return 0 + paliLessThan(X - 1);

//  printf("lessThan %d\n", X);

  int ret = 0;

  for (int i = 1; i <= 9; ++i)
    ret += isok(i, X);

  for (int x = 1; x < 1000; ++x) {
    int cp = x;
    int y = 0;
    int len = 1;
    while(cp) y *= 10, y += cp % 10, cp /= 10, len *= 10;
    
    ret += isok(x * len + y, X);
    for (int i = 0; i < 10; ++i)
      ret += isok(x * (len * 10) + i * len + y, X);
  }

  return ret;
}

int answer(long long X) {
  if (X == 0) return 0;
  int root = (int) sqrt(X);
  return paliLessThan(root);  
}

int main() {
  int T;
  long long A, B;

  //freopen("C.in", "r", stdin);
  //freopen("C.out", "w", stdout);

  scanf("%d", &T);

  for (int i = 1; i <= T; ++i) {
    cin >> A >> B;
    cout << "Case #" << i << ": " << answer(B) - answer(A-1) << endl; 
  }
/*
  long long res = 0;
  for (long long i = 1; i * i <= 100000000000000LL; ++i)
    if (ispali(i) && ispali(i*i))
      ++res;
  cout << "brute = " << res << endl;
*/
}
