#include <iostream>
#include <vector>
#include <map>


int N, M;

std::vector<long long> a, A, b, B;

std::map<std::pair<int, int>, long long> memo;


long long search(int i, int j)
{
  std::pair<int, int> key(i, j);

  if (i == a.size())
    return 0;
  
  if (j == b.size())
    return 0;

  if (memo.count(key))
    return memo[key];

  long long& r = memo[key];

  if (A[i] == B[j]) {
    long long c = std::min(a[i], b[j]), t1 = a[i], t2 = b[j];

    a[i] -= c;
    b[j] -= c;

    if (a[i] == 0) {
      r = std::max(search(i + 1, j) + c, r);
    }
    else {
      r = std::max(search(i, j + 1) + c, r);
    }

    a[i] = t1;
    b[j] = t2;
  }

  return r = std::max(std::max(search(i + 1, j),
			       search(i,     j + 1)),
		      r);
}


long long main2()
{
  std::cin >> N >> M;

  a.resize(N);
  A.resize(N);

  b.resize(M);
  B.resize(M);
  
  for (int i = 0; i < N; i ++)
    std::cin >> a[i] >> A[i];

  for (int i = 0; i < M; i ++)
    std::cin >> b[i] >> B[i];

  memo.clear();

  return search(0, 0);
}

int main(int argc, char** argv)
{
  int T;

  std::cin >> T;

  for (int t = 1; t <= T; t ++)
    std::cout << "Case #" << t << ": " << main2() << std::endl;
}
