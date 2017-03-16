#include <bits/stdc++.h>
#define LL long long
#define ABS(a) (((a) > 0) ? (a) : (-(a)))
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORIT(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
template<typename T> ostream& operator<<(ostream& s, vector<T>& v)
{ s << '{'; for (int i = 0 ; i < v.size(); ++i) s << (i ? "," : "") << v[i]; return s << '}'; }
template<typename S, typename T> ostream& operator<<(ostream &s, pair<S,T>& p)
{ return s << "(" << p.first << "," << p.second << ")"; }

double EPS = 0.0000000001;

double solve_chase(double d, double v1, double v2){
  assert(d>=0);
  assert(v1 < v2);
  double t = d / (v2-v1);
  cerr << d << " " << v1 << " " << v2 << " " << t << endl;
  return v2*t;
}

int main(){
  int TC;cin>>TC;
  FOR(tc,TC){
    int ans = 0;
    int NG;cin>>NG;
    vector<double> speeds;
    vector<double> locs;
    FOR(ng,NG){
      int st,N,sp;
      cin>>st>>N>>sp;
      FOR(i,N){
        speeds.pb(sp+i);
        locs.pb(st);
      }
    }

    int NHIK = speeds.size();
    assert(speeds.size() == NHIK);
    assert(locs.size() == NHIK);
    assert(NHIK == 2);
    cerr << speeds << " " << locs << endl;

    // subtract min{loc}
    double goal = 360;
    double firstloc = MIN(locs[0],locs[1]);
    goal -= firstloc;
    locs[0] -= firstloc;
    locs[1] -= firstloc;

    double slowguy_loc, fastguy_loc, slowguy_speed, fastguy_speed;
    if(speeds[0] > speeds[1]){
      fastguy_speed = speeds[0];
      fastguy_loc = locs[0];
      slowguy_speed = speeds[1];
      slowguy_loc = locs[1];
    }
    else{
      fastguy_speed = speeds[1];
      fastguy_loc = locs[1];
      slowguy_speed = speeds[0];
      slowguy_loc = locs[0];
    }
    cerr << "fast guy " << fastguy_loc << " " << fastguy_speed << "... slow guy " << slowguy_loc << " " << slowguy_speed << endl;

    if(speeds[0] == speeds[1]){
      ans = 0;
    }
    else{

      // Follow the fast guy until we reach slow guy
      if(fastguy_loc < EPS){
        double x = solve_chase(slowguy_loc, slowguy_speed, fastguy_speed);
        goal -= x;
        slowguy_loc = 0;
        fastguy_loc = 0;
        cerr << "after catching up to slow guy" << endl;
        cerr << "fast guy " << fastguy_loc << " " << fastguy_speed << "... slow guy " << slowguy_loc << " " << slowguy_speed << endl;
        cerr << "goal " << goal << endl;
      }
      else{
        // do nothing, already caught up with slow guy
      }

      // we are behind the slow guy.
      // follow until fast guy catches up
      double trail = slowguy_loc - fastguy_loc;
      if(trail < EPS) trail += 360;
      double x = solve_chase(trail,slowguy_speed,fastguy_speed) - trail;
      cerr << "x=" << x << endl;

      goal -= x;
      if(goal < -EPS){
        ans = 0;
      }
      else{
        ans = 1;
      }
    }

    FIN:
    cout << "Case #" << tc+1 << ": " << ans << endl;
  }
}

