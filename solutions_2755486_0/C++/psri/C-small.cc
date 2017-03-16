#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <assert.h>

using std::map;
using std::pair;
using std::vector;
using std::sort;


#define FOR(i, a , b) for(int i = (a); i <= (b); ++i)
#define FOREACH(it, container) for(typeof(container.begin()) it = container.begin(); it != container.end(); ++it)

typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;

const int L = 210;
ull wall[2*L+1];

struct attack{
  attack(){}
  attack(ul d, ul t, ull s, int w, int e){
    day = d; 
    tribe = t;
    strength = s;
    west = w;
    east = e;
  }
  ul day;
  ul tribe;
  ull strength;
  int west;
  int east;
};

attack as[200];

bool compare(attack a, attack b){
  if (a.day == b.day)
    return a.tribe < b.tribe;
  else
    return a.day < b.day;
}

int west[12];
int east[12];
ul start[12];
ul interval[12];
int ni[12];
int pi[12];
ull strengths[12];
ll delta[12];

int main(){
  int N;
  scanf("%d", &N);
  FOR(I, 1, N){
    int n;
    FOR(i, 0, 2*L){
      wall[i] = 0;
    }
    scanf("%d", &n);
    int count = 0;
    FOR(i, 0, n - 1){
      scanf("%lu %d %d %d %llu %lu %d %lld",
	    &start[i], &ni[i], &west[i], &east[i],
	    &strengths[i], &interval[i], &pi[i], &delta[i]);
      west[i] += L;
      east[i] += L;
      FOR(j, 0, ni[i] - 1){
	as[count++] = attack(start[i] + j*interval[i], i, 
			     strengths[i]+j*delta[i], west[i] + j*pi[i],
			     east[i] + j*pi[i]);
      }
    }
    sort(as, as+count, compare);
    int index = 0; 
    ull success = 0;
    vector<int> which;
    while(true){
      int i = index + 1;
      while(i < count && as[index].day == as[i].day){
	++i;
      }
      FOR(j, index, i - 1){
	FOR(k, as[j].west, as[j].east - 1){
	  if (wall[k] < as[j].strength){
	    success++;
	    which.push_back(j);
	    break;
	  }
	}
      }
      FOREACH(it, which){
	int j = *it;
	FOR(k, as[j].west, as[j].east - 1){
	  if (wall[k] < as[j].strength){
	    wall[k] = as[j].strength;
	  }
	}
      }
      which.clear();
      index = i;
      if (index >= count)
	break;
    }
    printf("Case #%d: %llu\n", I, success);
  }
  return 0;
}

// Local Variables:
// compile-command: "g++ -O3 -o C C.cc"
// End:
