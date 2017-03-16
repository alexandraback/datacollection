#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int num_dig(ll n) {
  int counter = 0;
  while (n > 0) {
    n /= 10;
    ++counter;
  }
  return counter;
}

ll swap(ll n) {
  ll ret (0);
  while (n > 0) {
    ret = ret * 10 + n % 10;
    n /= 10;
  }

  return ret;
}

ll pow10(int n) {
  ll ret = 1;
  while (n--)
    ret *= 10;
  return ret;
}

vector<int> vec(17, 0);

int main() {

  vec[1] = 1;
  vec[2]= 10;
  ll t1(10), t2(9);
  for (int i = 3; i < 17; i += 2) {
    vec[i] = vec[i - 1] + t1 + t2;
    t2 = 10 * t2 + 9;
    vec[i + 1] = vec[i] + t1 + t2;
    t1 *= 10;
    //printf("%d %d ", vec[i], vec[i + 1]);
  }

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  unsigned nn;
  scanf("%d", &nn);
  for(unsigned ii = 1; ii <= nn; ++ii) {
    printf("Case #%d: ", ii);

    ll num;
    scanf("%ld", &num);
    ll counter = 0;
    bool flag (false);
    if (num % 10 == 0) {
      --num;
      flag = true;
      ++counter;
    }
    int nd = num_dig(num);
    ll cc = pow10(nd / 2);
    counter += swap(num / cc);
    counter += vec[nd];
    counter += num % cc;
    counter = min(counter, flag + vec[nd] + swap(swap(num) - 1));
    printf("%ld\n", counter);
  }

  return 0;

}