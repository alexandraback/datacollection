#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>



using namespace std;


pair<int, char> mult(pair<int, char> a, pair<int, char> b){
  map<char, map<char, pair<int, char>>> table =
    {{'1', {{'1', {1, '1'}}, {'i', {1, 'i'}}, {'j', {1, 'j'}}, {'k', {1, 'k'}}}},
     {'i', {{'1', {1, 'i'}}, {'i', {-1, '1'}}, {'j', {1, 'k'}}, {'k', {-1, 'j'}}}},
     {'j', {{'1', {1, 'j'}}, {'i', {-1, 'k'}}, {'j', {-1, '1'}}, {'k', {1, 'i'}}}},
     {'k', {{'1', {1, 'k'}}, {'i', {1, 'j'}}, {'j', {-1, 'i'}}, {'k', {-1, '1'}}}}};
  pair<int, char> product = table[a.second][b.second];
  product.first *= (a.first * b.first);
  return product;
}



bool good_product(string base, long long multiple){
  pair<int, char> prod = {1, '1'};
  long long reduced = multiple % 8LL;
  if (multiple >= 8LL){
    reduced += 8LL;
  }
  bool seen_i = false, seen_k = false;
  for (int i = 0; i < reduced; ++i){
    for (int j = 0; j < base.size(); ++j) {
      pair<int, char> factor = {1, base[j]};
      prod = mult(prod, factor);
      if (prod.first == 1 && prod.second == 'i'){
	seen_i = true;
      }
      if (seen_i && (prod.first == 1 && prod.second == 'k')){
	seen_k = true;
      }
    }
  }
  return (prod.first == -1 && prod.second == '1' && seen_i && seen_k);
}




int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T = 0;
  cin >> T;
  for (int i = 1; i <= T; ++i){
    int L = 0;
    long long X;
    cin >> L >> X;
    string base;
    cin >> base;
    auto result = good_product(base, X) ? "YES" : "NO";
    cout << "Case #" << i << ": " << result << '\n';
  }

  return 0;
}
