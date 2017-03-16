#include <stdio.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;

const int MAXN = 1010;

int n;
int n_first, n_second;
int first_topics[MAXN], second_topics[MAXN];

int faked[MAXN];
int ans = 0;

void dfs(int cnt)
{
  if (cnt == n)
  {
//    for (int i = 0; i < n; ++i)
//      printf("%d ", faked[i]);
//    printf("\n");

    int num_faked = 0, num_guess_faked = 0;
    for (int k = 0; k < n; ++k)
    {
      if (!faked[k]) continue;
      num_guess_faked += 1;
      bool is_faked = false;
      for (int i = 0; i < n; ++i)
      {
        if (faked[i]) continue;
        for (int j = i + 1; j < n; ++j)
        {
          if (faked[j]) continue;
          if (((first_topics[k] == first_topics[i]) && (second_topics[k] == second_topics[j])) || ((first_topics[k] == first_topics[j]) && (second_topics[k] == second_topics[i])))
            is_faked = true;
        }
      }
      if (is_faked) num_faked += 1;
    }
//    printf("====%d %d\n", num_faked, num_guess_faked);
    if ((num_faked == num_guess_faked) && (num_faked > ans))
      ans = num_faked;
    return;
  }
  for (faked[cnt] = 0; faked[cnt] < 2; faked[cnt]++)
  {
    dfs(cnt + 1);
  }
}

int main()
{
  int cases;
  cin >> cases;
  for (int k = 1; k <= cases; ++k)
  {
    printf("Case #%d: ", k);
    cin >> n;

    n_first = 0, n_second = 0;
    map<string, int> first_map, second_map;
    for (int i = 0; i < n; ++i)
    {
      string s1, s2;
      cin >> s1 >> s2;

      if (first_map.find(s1) == first_map.end()) first_map[s1] = n_first++;
      if (second_map.find(s2) == second_map.end()) second_map[s2] = n_second++;

      first_topics[i] = first_map[s1];
      second_topics[i] = second_map[s2];
    }
    for (int i = 0; i < n; ++i)
    {
//      fprintf(stderr, "%d %d\n", first_topics[i], second_topics[i]);
    }
    
    ans = 0;
    dfs(0);
    printf("%d\n", ans);
  }
  return 0;
}

