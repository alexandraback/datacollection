#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class attack {
public:
  int d; //day
  int w,e; //range
  int s; //strength

  attack(int _d, int _w, int _e, int _s) : d(_d), w(_w), e(_e), s(_s) {};

};

unsigned long long int prev_wall[2000001];
unsigned long long int wall[2000001];
int zero = 1000000;

inline bool operator<(const attack &a, const attack &b) {
  return a.d < b.d;
}

vector<attack> attacks;

int simulate() {
  int n = attacks.size();  

  sort(attacks.begin(), attacks.end());

  int min_dist = 0;
  int max_dist = 0;

  for (int i=0; i<n; i++) {
    min_dist = min(min_dist, attacks[i].w);
    max_dist = max(max_dist, attacks[i].e);
  }

  fprintf(stderr, "distance: %d\n",max_dist-min_dist);

  for (int i=zero+min_dist*2; i<=zero+max_dist*2; i++)
    wall[i] = 0;
  
  
  int res = 0;
  int prev_day = -1;

  for (int i=0; i<n; i++) {
    attack a = attacks[i];
    bool successful = false;

    //    printf("attack on day %d, %d-%d, s %d\n",a.d, a.w,a.e,a.s);

    if (a.d != prev_day) {
      prev_day = a.d;
      for (int i=zero+min_dist*2; i<=zero+max_dist*2; i++)
	prev_wall[i] = wall[i];
    }

    for (int i=zero+a.w*2; i<=zero+a.e*2; i++) {
      if (prev_wall[i] < a.s) {
	if (!successful) {
	  //	  printf("succeeded at %f\n",float(i-zero)/2.0);
	}
	successful = true;
	if (wall[i] < a.s)
	  wall[i] = a.s;
      }
    }
    res += successful;
  }

  return res;
}

int main() {
  int T;
  int N;
  int d, n, w, e, s, delta_d, delta_p, delta_s;

  scanf("%d",&T);
  for (int tc=1; tc<=T; tc++) {
    attacks.clear();
    
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
      scanf("%d %d %d %d %d %d %d %d",&d,&n,&w,&e,&s,&delta_d,&delta_p,&delta_s);
      attacks.push_back(attack(d,w,e,s));

      for (int j=1; j<n; j++) {
	d += delta_d;
	w += delta_p;
	e += delta_p;
	s += delta_s;
	attacks.push_back(attack(d,w,e,s));
      }
    }
    printf("Case #%d: %d\n",tc,simulate());
  }
}
