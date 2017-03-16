#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int MAX_ACTIONS = 0;

int
getMinActions(int size, const vector<int>& aMotes, unsigned int idx, int actions)
{
  if (idx == aMotes.size()) {
    return actions;
  }
  if (actions >= MAX_ACTIONS) {
    return MAX_ACTIONS;
  }

  if (size > aMotes[idx]) {
    return getMinActions(size+aMotes[idx], aMotes, idx+1, actions);
  }

  int suppressAction = actions + (aMotes.size() - idx);// getMinActions(size, aMotes, idx+1, actions+1);
  int addAction = getMinActions(size+(size-1), aMotes, idx, actions+1);

  return suppressAction < addAction ? suppressAction : addAction;
}

int main()
{
  int T;
  scanf("%d\n", &T);

  for (int t=1; t<=T; ++t) {
    int size, nbMotes;
    scanf("%d %d\n", &size, &nbMotes);

    vector<int> motes;

    for (int i=0; i<nbMotes; ++i) {
      int tmp;
      scanf("%d", &tmp);
      motes.push_back(tmp);
    }

    int result;

    if (size == 1) {
      result = nbMotes;
    } else {
      sort(motes.begin(), motes.end());
      MAX_ACTIONS = nbMotes;
      result = getMinActions(size, motes, 0, 0);
    }

    printf("Case #%d: %d\n", t, result);
  }

  return 0;
}
