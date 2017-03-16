#include <algorithm>
#include <iterator>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>


#define ALL(x) (x).begin(), (x).end()
#define EACH(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); ++ i)


class solver
{
public:
  solver(const std::vector<int>&               keys,
         const std::vector<int>&               key_types,
         const std::vector<std::vector<int> >& keys_inside) :
    keys_(keys), key_types_(key_types), keys_inside_(keys_inside)
  {
  };

public:
  std::string operator()() {
    int size = key_types_.size();

    memo_.assign(size, std::vector<bool>(1 << size, true));

    if (dfs(0, 0)) {
      std::ostringstream oss;

      for (int i = 0; i < size - 1; i ++)
        oss << result_[size - 1 - i] << ' ';

      oss << result_.front();

      return oss.str();
    }
    else {
      return "IMPOSSIBLE";
    }
  };

private:
  bool dfs(int i, int mask) {
    int size = key_types_.size();

    if (i == size)
      return true;

    if (! memo_[i][mask])
      return false;

    std::set<int> key_types(ALL(keys_));

    for (int j = 0; j < size; j ++) {
      int key_type = key_types_[j];

      if (key_types.count(key_type)) {
        if ((mask & (1 << j)) == 0) {
          std::vector<int> keys(keys_);

          keys_.erase(std::find(ALL(keys_), key_type));

          EACH (it, keys_inside_[j])
            keys_.push_back(*it);
          
          if (dfs(i + 1, mask | (1 << j))) {
            result_.push_back(j + 1);
            
            return true;
          }
          
          keys_.assign(ALL(keys));
        }
      }
    }

    return memo_[i][mask] = false;
  };

private:
  std::vector<int>               keys_;
  std::vector<int>               key_types_;
  std::vector<std::vector<int> > keys_inside_;

  std::vector<int> result_;

  std::vector<std::vector<bool> > memo_;
};

int main(int argc, char** argv)
{
  std::istream_iterator<int> it(std::cin);

  int T, K, N;

  T = *it ++;

  for (int t = 1; t <= T; t ++) {
    K = *it ++;
    N = *it ++;

    std::vector<int> keys(K), key_types(N);

    std::vector<std::vector<int> > keys_inside(N);
    
    for (int i = 0; i < K; i ++, ++ it)
      keys[i] = *it;

    for (int i = 0; i < N; i ++) {
      key_types[i] = *it ++;

      for (int j = 0, size = *it ++; j < size; j ++, ++ it)
        keys_inside[i].push_back(*it);
    }

    std::cout << "Case #" << t << ": " << solver(keys, key_types, keys_inside)() << std::endl;
  }

  return 0;
}
