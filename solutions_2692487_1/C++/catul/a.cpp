#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

int find_req(unsigned int *A, unsigned int m) {
  int n = 0;
  while (*A <= m) {
    n++;
    *A += *A - 1;
  }
  return n;
}

int main() {
  int T, num=1;
  unsigned int N;
  unsigned int A;
  unsigned int s[101];

  int best;
  int i;
  vector<unsigned int>::iterator it;

  for (cin >> T; T--;) {
    cin >> A >> N;
    for (i = 0; i < N; i++)
      cin >> s[i];
    best = -1;

    vector<unsigned int> motes (s, s+N);

    // Sort in ascending order
    sort(motes.begin(), motes.end());

    // shortcut and avoid infinite loop in find_req
    if (A == 1) {
      best = N;
      goto exit;
    }

    unsigned int added = 0;
    i = 0;

consume:

    for (it = motes.begin() + i; it != motes.end(); it++, i++) {
      if (*it >= A)
        goto stuck;
      A += *it;
      //cout << *it << ' ';
    }
    best = added;
    goto exit;

stuck:
    //cout << "i = " << i << " mote=" << *it << endl;
    int torem = N - i;
    int toadd = find_req(&A, *it);

    // if what he have already added and what we need to remove is better than the previous one good
    //cout << "current best = " << best << " added=" << added << " torem=" << torem << " toadd=" << toadd << endl;
    if (best == -1 || ((added + torem) <= best))
      best = added + torem;

    if (toadd >= torem) {
      // if to add would be greater than removing everything left, don't bother continuing
      //cout << "bailout" << endl;
      goto exit;
    } else {
      // we need to add less than what we need to remove
      added += toadd;
      //cout << "new branch, total added =" << added << endl;
      goto consume;
    }

exit:
    //cout << "A = " << A << " best=" << best << endl;
    if (best == -1)
      best = 0;
    printf("Case #%d: %d\n", num++, best);
  }
}
