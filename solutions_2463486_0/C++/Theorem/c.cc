
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#define T long long unsigned

bool palindrome (T v)
{
    int value[32];
    int i = 0;

    while (v) {
        value[i] = v%10;
        v /= 10;
        ++i;
    }

    for (int j = 0; j < i; ++j)
       if (value[j] != value[i - 1 - j]) return false;

    return true;
}


void solve (int CASE)
{
    T a, b;
    cin >> a >> b;

    T low  = sqrt((long double)a);
    while (low*low < a) ++low;

    int t = 0;
    for (T i = low; i*i <= b; i++) {
        if (palindrome(i) && palindrome(i*i)) {
            //printf("%llu %llu\n", i, i*i);
            t++;
        }
    }

    printf("Case #%d: %d\n", CASE, t);
}

int main ()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) solve(i);
  return 0;
}

