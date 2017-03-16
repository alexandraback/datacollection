#include <cstdio>
#include <set>
#include <utility>

using namespace std;

struct node
{
  set<int> ancestors;
};

node nodes[1001];
bool checked[1001];
bool checking[1001];

bool check(int i)
{
  if (checked[i]) return false;
  if (checking[i]) {
    return true;
  }
  checking[i] = true;
  set<int>& ancestors = nodes[i].ancestors;
  set<int> toAdd;

  for (set<int>::const_iterator it = ancestors.begin(), end = ancestors.end(); it != end; ++it)
  {
    if (check(*it))
    {
      return true;
    } else
    {
      for (set<int>::const_iterator ait = nodes[*it].ancestors.begin(), aend = nodes[*it].ancestors.end(); ait != aend; ++ait)
      {
        pair< set<int>::iterator, bool> res = toAdd.insert(*ait);
        if (!res.second)
        {
          return true;
        }
      }
    }
  }

  for (set<int>::const_iterator it = toAdd.begin(), end = toAdd.end(); it != end; ++it)
  {
    pair< set<int>::iterator, bool> res = ancestors.insert(*it);
    if (!res.second)
    {
      return true;
    }
  }
  checking[i] = false;
  checked[i] = true;
  return false;
}

int main()
{
  int T;

  scanf("%d", &T);

  for (int case_ = 1; case_ <= T; ++case_)
  {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
    {
      int Mi;
      set<int>& ancestors = nodes[i].ancestors;
      ancestors.clear();
      checked[i] = false;
      checking[i] = false;
      scanf("%d", &Mi);
      for (int j = 0; j < Mi; ++j)
      {
        int parent;
        scanf("%d", &parent);
        ancestors.insert(parent);
      }
    }

    bool ok = false;
    for (int i = 1; i <= N; ++i)
    {
      if (check(i))
      {
        printf("Case #%d: Yes\n", case_);
        ok = true;
        break;
      }
    }

    if (!ok)
    {
      printf("Case #%d: No\n", case_);
    }

  }
  return 0;
}
