
#include <cstdio>
#include <cstring>

using namespace std;

int a[1000], b[1000];
bool a_used[1000], b_used[1000];

void reset()
{
  memset(a_used, false, sizeof(a_used));
  memset(b_used, false, sizeof(b_used));
}

int main()
{
  int T;
  scanf("%d", &T);

  for (int case_id = 1; case_id <= T; case_id++)
  {
    reset();
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
      scanf("%d %d", &a[i], &b[i]);
    int stars = 0, levels = 0, progress = 0;
    while (progress < N)
    {
      int stars_cpy = stars;
      for (int i = 0; i < N; i++)
      {
	if (!b_used[i] && b[i] <= stars)
	{
	  stars += a_used[i] ? 1 : 2;
	  levels++;
	  progress++;
	  b_used[i] = true;
	}
      }
      if (stars_cpy < stars) continue;
      int max_idx = -1;
      for (int i = 0; i < N; i++)
      {
	if (!a_used[i] && a[i] <= stars)
	{
	  if (max_idx == -1 || b[max_idx] < b[i]) max_idx = i;
	}
      }
      if (max_idx != -1)
      {
	stars++;
	levels++;
	a_used[max_idx] = true;
      }
      if (stars_cpy == stars) break;
    }

    if (progress < N) printf("Case #%d: Too Bad\n", case_id);
    else printf("Case #%d: %d\n", case_id, levels);
  }
}
