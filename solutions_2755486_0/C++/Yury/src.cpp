#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

#define fori(i,s, n)   for(llong (i) = (s); (i) < (n); (i)++)
#define foriz(i,n)     fori((i),0,(n))

typedef long long llong;

struct tribe_t {
  int     d, n, w, e, s, dd, dp, ds; 

  bool is_last() const {
    assert(n >= 1);
    return n == 1;
  }

  tribe_t next() const {
    return { d + dd, n - 1, w + dp, e + dp, s + ds, dd, dp, ds };
  }

  void adv() {
    d += dd;
    n -= 1;
    w += dp;
    e += dp;
    s += ds;
  }

  template <class Stream>
  void read_from(Stream& S) {
    S >> d >> n >> w >> e >> s >> dd >> dp >> ds; 
  }
  

  template <class Stream>
  void dump(Stream& S) const {
    S << d << " " << n << " " << w << " " << e << " " << s << " " << dd << " " << dp << " " << ds; 
    S << endl;
  }

};

struct input_t {
  int     N;

  vector<tribe_t>    trs;

  template <class Stream>
  void read_from(Stream& S) {
    S >> N;

    trs.reserve(N);

    foriz(i, N) {
      tribe_t   tr;
      tr.read_from(S);

      trs.push_back(tr);
    }
  }

  template <class Stream>
  void dump(Stream& s) const {
    foriz(i, N) {
      trs[i].dump(s);
    }
  }
};

struct wall_t {
  array<int, 10000>   d;

  void init (){
    for(auto& i : d) i = 0;
  }

  int& at(int p) {
    return d[p + 1000];
  }
};


int calc(input_t& in){
  // in.dump(cerr);

  //map<int, int>         wall;
  wall_t          wall;

  wall.init();

  multimap<int, tribe_t*>   atts;
  vector<tribe_t>      today;

  int     total = 0;


  for(auto& tr : in.trs) atts.emplace(tr.d, &tr);

  int   day = -1;

  for(;;){
    if(atts.empty()) goto end_day;

    {
      auto ne = *(atts.begin());

      if(ne.first != day) {

        day = ne.first;

        goto end_day;
      }

      atts.erase(atts.begin());

      auto& tr = *ne.second;

      today.push_back(tr);

      ///////

      if(!tr.is_last()) {
        tr.adv();
        atts.emplace(tr.d, &tr);
      }
    }

    continue;

  end_day:
    for(auto& tr : today) {
      bool brea = false;
      fori(i, tr.w, tr.e) {
        //cerr << wall.at(i) << " vs " << tr.s << endl;

        if(wall.at(i) < tr.s) {
          brea = true;
          break;
        }
      }

      if(brea) {
        total ++;
      }

      if(0)
      cerr << "a: [" << tr.w << " " << tr.e << "] * "
        << tr.s
        << " = " << brea
        << endl;

    }

    for(auto& tr : today) {
      fori(i, tr.w, tr.e) {
        int&  w = wall.at(i);
        w = max(w, tr.s);
      }
    }

    today.clear();

    cerr << "day: " << day << endl;

    if(atts.empty()) break;
  }

  return total;
}

int main(int argc, char* argv[]) {
  fstream     f(argv[1]);

  int T;
  f >> T;

  for(int t = 1; t <= T; t++) {
    input_t     in;

    in.read_from(f);

    cout << "Case #" << t << ": " << calc(in) << endl;
  }
}

