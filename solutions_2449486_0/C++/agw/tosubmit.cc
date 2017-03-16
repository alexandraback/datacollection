#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


#define ALL(x) (x).begin(), (x).end()
#define EACH(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); ++ i)


class solver
{
public:
  solver(const std::vector<std::vector<int> >& lawn) :
    lawn_(lawn), w_(lawn_[0].size()), h_(lawn_.size()), op_(101)
  {
  };

public:
  std::string operator()() {
    for (int i = 0; i < h_; i ++)
      op_[*std::max_element(ALL(lawn_[i]))].push_back(i + 1);

    for (int j = 0; j < w_; j ++) {
      int hp = 0;

      for (int i = 0; i < h_; i ++)
        hp = std::max(lawn_[i][j], hp);

      op_[hp].push_back((j + 1) * 1000);
    }

    std::vector<std::vector<int> > lawn(h_, std::vector<int>(w_, 100));

    for (int k = 100; k > 0; k --) {
      EACH (it, op_[k]) {
        if (*it < 999) {
          int i = *it - 1;

          std::fill(ALL(lawn[i]), k);
        }
        else {
          int j = *it / 1000 - 1;

          for (int i = 0; i < h_; i ++)
            lawn[i][j] = k;
        }
      }
    }

    for (int i = 0; i < h_; i ++)
      if (lawn[i] != lawn_[i])
        return "NO";

    return "YES";
  };

private:
  std::vector<std::vector<int> > lawn_;

  int w_;
  int h_;

  std::vector<std::vector<int> > op_;
};

int main(int argc, char** argv)
{
  std::istream_iterator<int> it(std::cin);

  int T, N, M;

  T = *it ++;

  for (int t = 1; t <= T; t ++) {
    N = *it ++;
    M = *it ++;

    std::vector<std::vector<int> > lawn(N, std::vector<int>(M));

    for (int i = 0; i < N; i ++)
      for (int j = 0; j < M; j ++)
        lawn[i][j] = *it ++;

    std::cout << "Case #" << t << ": " << solver(lawn)() << std::endl;
  }

  return 0;
}
