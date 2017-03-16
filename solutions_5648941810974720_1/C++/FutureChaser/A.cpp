#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

const int MAXL = 2010;

char s[MAXL];

const char NUMS[][10] = {
  "ZERO",
  "ONE",
  "TWO",
  "THREE",
  "FOUR",
  "FIVE",
  "SIX",
  "SEVEN",
  "EIGHT",
  "NINE",
};

map<char, int> nums[10];
map<char, int> obj;
int digit_counts[10];
bool ans_found = false;

void dfs(int cnt)
{
  bool all_clear = true;
  for (map<char, int>::iterator it = obj.begin(); it != obj.end(); ++it)
  {
    if (it->second > 0) { all_clear = false; break; }
  }
  if (all_clear)
  {
    ans_found = true;
    for (int i = 0; i < 10; ++i)
    {
      for (int j = 0; j < digit_counts[i]; ++j) printf("%d", i);
    }
    printf("\n");
    return;
  }
  if (cnt >= 10) return;

  int maxcount = 2000;
  for (map<char, int>::iterator it = nums[cnt].begin(); it != nums[cnt].end(); ++it)
  {
    maxcount = min(maxcount, obj[it->first] / it->second);
  }

//  printf("cnt = %d, maxcount = %d\n", cnt, maxcount);
  for (int i = maxcount; i >= 0; ++i)
  {
    digit_counts[cnt] = i;

    for (map<char, int>::iterator it = nums[cnt].begin(); it != nums[cnt].end(); ++it)
    {
      obj[it->first] -= it->second * i;
    }

//    fprintf(stderr, "cnt = %d, i = %d\n", cnt, i);
    dfs(cnt + 2);
//    fprintf(stderr, "i === %d\n", i);
    if (ans_found) break;

    for (map<char, int>::iterator it = nums[cnt].begin(); it != nums[cnt].end(); ++it)
    {
      obj[it->first] += it->second * i;
    }
  }
}

int main()
{
  for (int i = 0; i < 10; ++i)
  {
    for (int j = 0; j < strlen(NUMS[i]); ++j)
      nums[i][NUMS[i][j]] += 1;
  }

  int cases;
  scanf("%d", &cases);
  for (int k = 1; k <= cases; ++k)
  {
    printf("Case #%d: ", k);
    scanf("%s", s);
    int n = strlen(s);
    obj.clear();
    for (int i = 0; i < n; ++i) obj[s[i]] += 1;
    for (int i = 0; i < 10; ++i) digit_counts[i] = 0;

    digit_counts[0] = obj['Z'];
    digit_counts[2] = obj['W'];
    digit_counts[4] = obj['U'];
    digit_counts[6] = obj['X'];
    digit_counts[8] = obj['G'];

    for (int i = 0; i < 10; ++i)
    {
      for (map<char, int>::iterator it = nums[i].begin(); it != nums[i].end(); ++it)
      {
        obj[it->first] -= it->second * digit_counts[i];;
      }
    }

    ans_found = false;
    dfs(1);
  }
  return 0;
}
