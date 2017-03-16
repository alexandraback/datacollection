#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

void testcase(int case_no)
{
  int t;
  vector<pii> levels;
  vector<pii> l2;
  vector<pii> l1;
  vector<bool> used_l1;
  vector<bool> used_l2;

  scanf("%d",&t);

  for(int i=0;i<t;i++) {
    int a,b;
    scanf("%d%d",&a,&b);
    levels.push_back(pii(a,b));
    l1.push_back(pii(a,i));
    l2.push_back(pii(b,i));
    used_l1.push_back(false);
    used_l2.push_back(false);
  }
  sort(l1.begin(), l1.end());
  sort(l2.begin(), l2.end());
  //for(int i=0;i<t;i++) printf("(%d,%d) ",l2[i].first,l2[i].second);
  
  priority_queue<pii> l1q;
  int stars=0;
  int k=0;
  int extras=0;
  for(int j=0; j<t; j++) {
    int required = l2[j].first;
    // obtenir les 1* requises
    while ( stars < required ) {
      // remplir la queue
      while ( k < t && l1[k].first <= stars ) {
	int n = l1[k].second;
	//	printf("Added %d ( %d ) to queue\n", n+1, levels[n].second);
	l1q.push(pii(levels[n].second,n));
	k++;
      }
      // prendre le premier
      if ( l1q.empty() ) {
	printf("Case #%d: Too Bad\n", case_no);
	return;
      }
      pii t = l1q.top();
      l1q.pop();
      used_l1[t.second]=true;
      if ( !used_l2[t.second] ) {
	//fprintf(stderr,"Done 1* %d\n",t.second+1);
	extras++;
	stars++;
      }
    }
    // faire le 2*
    used_l2[l2[j].second]=true;
    //fprintf(stderr, "Done 2* %d\n", l2[j].second+1);
    stars++;
    if ( !used_l1[l2[j].second] ) stars++;
  }
  
  printf("Case #%d: %d\n", case_no, t+extras);
}

int main()
{
  int ncases;
  scanf("%d",&ncases);
  for(int i=1;i<=ncases;i++)
    testcase(i);

  return 0;
}
