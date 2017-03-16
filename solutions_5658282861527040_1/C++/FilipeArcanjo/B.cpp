#include <iostream>
#include <vector>

using namespace std;

enum tribool {TRUE = 1, FALSE = 0, X = 2 };
typedef vector<tribool> mask;
typedef long long int64;

void pmask(mask & m)
{
  for (auto & it : m) switch (it) {
    case TRUE:  cout << 1; break;
    case FALSE: cout << 0; break;
    case X:     cout << 'X'; break;
  }
  cout << endl;
}

vector<mask> masks(int64 x)
{
  //cout << x << endl;
  vector<mask> result;
  mask base_mask;;
  for (int64 m = (1ll << 62ll); m > 0; m >>= 1) {
    if (x & m) base_mask.push_back(TRUE);
    else base_mask.push_back(FALSE);
  }
  //cout << "sz = " << base_mask.size() << endl;
  //pmask(base_mask);
  for (int64 m = (1ll << 62ll), i = 0; m > 0; m >>= 1, ++i) {
    if (x & m) {
      result.push_back(base_mask);
      result.back()[i] = FALSE;
      for (int j = i + 1; j < base_mask.size(); ++j) result.back()[j] = X;
      //pmask(result.back());
    }
  }
  return result;
}

int64 nv(tribool val)
{
  if (val == X) return 2;
  return 1;
}

int64 count(tribool a, tribool b, tribool k)
{
  if (k == X) {
    return nv(a) * nv(b);    
  } else if (k == TRUE) {
    bool c1 = a == TRUE and b == TRUE;
    bool c2 = a == TRUE and b == X;
    bool c3 = a == X and b == TRUE;
    bool c4 = a == X and b == X;
    if (c1 or c2 or c3 or c4) return 1;
    return -1;
  } else if (k == FALSE) {
    if (a == FALSE) return nv(b);
    if (b == FALSE) return nv(a);
    if (a == TRUE and b == X) return 1;
    if (b == TRUE and a == X) return 1;
    if (a == X    and b == X) return 3;
    return -1;
  }
  return -1;
}

int64 count(mask & a, mask & b, mask & k) {
  int64 result = 1;
  for (int i = 0; i < a.size(); ++i) {
    int64 ct = count(a[i], b[i], k[i]);
    if (ct == -1) return 0;
    result *= ct;
  }
  return result;
}

int64 solve(int64 A, int64 B, int64 K)
{
  //cout << A << "  "<< B << " " << K << endl;
  vector<mask> ma = masks(A);
  vector<mask> mb = masks(B);
  vector<mask> mk = masks(K);
  int64 result = 0;
  for (int i = 0; i < ma.size(); ++i) 
    for (int j = 0; j < mb.size(); ++j)
      for (int k = 0; k < mk.size(); ++k) 
        result += count(ma[i], mb[j], mk[k]);
  return result;
}

int main()
{
  int ntc; cin >> ntc;
  for (int tc = 1; tc <= ntc; ++tc) {
    int64 A, B, K; cin >> A >> B >> K;
    cout << "Case #" << tc << ": " << solve(A, B, K) << endl;
  }
}


