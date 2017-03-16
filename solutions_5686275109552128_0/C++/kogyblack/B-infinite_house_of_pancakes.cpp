#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> p;
int t, d, m, c;

int split()
{
  vector<int> backup = p;
  int v = p.back();
  int t = v;
  for (int i = 2; i <= v / 2; ++i)
  {
    //printf("split %d: %d %d\n", v, i, v - i);
    p.pop_back();
    p.push_back(i);
    p.push_back(v - i);
    sort(p.begin(), p.end());

    //printf("recursion\n");
    t = min(t, 1 + split());
    //printf("end recursion\n");
    p = backup;
  }

  return t;
}

int main()
{
  scanf("%d", &t);

  for (int i = 1; i <= t; ++i)
  {
    printf("Case #%d: ", i);

    scanf("%d", &d);
    p.clear();
    p.resize(d);
    for (int j = 0; j < d; ++j)
      scanf("%d", &p[j]);

    sort(p.begin(), p.end());

    printf("%d\n", split());
  }

  return 0;
}
