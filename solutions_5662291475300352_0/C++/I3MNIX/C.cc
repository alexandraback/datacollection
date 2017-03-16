#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

const long double EPS = 1e-15;
using namespace std;
typedef pair<int, int> ii;
typedef long long LL;
vector <ii> hiker;

LL gcd(LL a, LL b){
  return (b == 0) ? a : gcd(b, a % b);
}

struct frac {
  LL num, den;
  frac () {}
  frac(LL num, LL den) : num(num), den(den) {} 
};

frac reduce(frac a){
  if (a.num == 0) return frac(0,1);
  LL g = gcd(a.num, a.den);
  return frac(a.num/g, a.den/g);
}
frac recip(frac a) { return frac(a.den, a.num); }
frac operator * (frac a, frac b){
  LL g1 = gcd(a.num, b.den), g2 = gcd(a.den, b.num);
  return frac((a.num/g1) * (b.num/g2), (a.den/g2) * (b.den/g1));
}
frac operator / (frac a, frac b){
  return a * recip(b);
}
bool operator == (frac a, frac b) {
  a = reduce(a); b = reduce(b);
  return a.num == b.num && a.den == b.den;
}
frac operator + (frac a, frac b){
  LL g = gcd(a.den, b.den);
  return reduce(frac(a.num*(b.den/g) + b.num*(a.den/g), (a.den/g)*b.den));
}
bool operator < (frac a, frac b) { return (a.num * b.den) < (b.num * a.den); }

int solve(){
  int n;
  cin >> n;
  hiker.clear();
  for (int i = 0; i < n; i++){
    int p, deg, sp;
    cin >> deg >> p >> sp;
    hiker.push_back(ii(sp, deg));
    for (int j = 1; j < p; j++){
      hiker.push_back(ii(++sp, deg));
    }
  }
  sort(hiker.rbegin(), hiker.rend());
  if (hiker.size() == 1) return 0;
  // 2 hikers
  int s1 = hiker[0].first;
  int s2 = hiker[1].first;
  int d1 = hiker[0].second;
  int d2 = hiker[1].second;

  if (s1 == s2) return 0;

  frac t1 = frac(360 - d1, 1) / frac(360, s1);
  frac dist = frac(360, s2) * t1  + frac(d2, 1);

  frac final = frac(360, 1);
  if (d2 >= d1) final = final * frac(2, 1);

  if (dist == final || final < dist) return 1;
  return 0;
}

int main(){
  int t;
  cin >> t;
  for (int cs = 1; cs <= t; cs++){
    cout << "Case #" << cs << ": ";
    cout << solve() << endl;
  }
  return 0;
}
