#include <cstdio>
#include <vector>

int main()
{
  int T;
  scanf("%d", &T);
  for(int cases=1; cases<=T; ++cases) {
    int N, M;
    scanf("%d%d", &N, &M);
    std::vector<std::pair<int, int> > a, b;
    for(int i=0; i<N; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      if(i != 0 && y==a.back().second)
	a.back().first += x;
      else
	a.push_back(std::make_pair(x, y));
    }
    for(int i=0; i<M; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      if(i != 0 && y==b.back().second)
	b.back().first += x;
      else
	b.push_back(std::make_pair(x, y));
    }
    std::vector<int> bp(a.size()+1, 0);
    bp.back() = b.size();
    int best = 0;
    for(;;) {
      //      for(int i=0; i<bp.size(); ++i)
      //	printf(" %d", bp[i]);
      //      printf("\n");
      //      printf("%d\n", (int)bp.size());
      int tot = 0;
      for(int i=0; i<a.size(); ++i) {
	//	printf("x %d\n", i);
	int sum=0;
	for(int j=bp[i]; j<bp[i+1]; ++j) {
	  //	  printf("y %d\n", j);
	  if(b[j].second==a[i].second)
	    sum += b[j].first;
	}
	tot += std::min(sum, a[i].first);
      }
      //      puts("adam");
      best = std::max(best, tot);
      if(bp[1] == bp.back())
	break;
      if(bp.size() == 4) {
	if(bp[2] < bp[3])
	  ++bp[2];
	else
	  bp[2] = ++bp[1];
      } else {
	++bp[1];
      }
    }
    if(a.size() == 3 && a[0] == a[2]) {
      int sum = 0;
      for(int i=0; i<b.size(); ++i)
	if(b[i].second == a[0].second)
	  sum += b[i].first;
      best = std::max(best, std::min(sum, a[0].first+a[2].first));
    }
    printf("Case #%d: %d\n", cases, best);
  }
  return 0;
}
