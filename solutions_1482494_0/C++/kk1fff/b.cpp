#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

struct Tab {
  int level;
  int star;
  bool operator<(const Tab& t) const {
    return star<t.star;
  }
};

typedef vector<Tab> VT;

void print(VT& v) {
  for (int i = 0; i < v.size(); ++i) {
    cout<<v[i].level<<" "<<v[i].star<<endl;
  }
  cout<<endl;
}

void run(istream& in, ostream& ou, int t) {
  int N;
  in >> N;
  int mark2[1001], mark1[1001];
  memset(mark1, 0, sizeof(mark1));
  memset(mark2, 0, sizeof(mark2));

  VT star1, star2;
  int mystar = 0;
  for (int i = 0; i < N; i++) {
    int s1, s2;
    in >> s1 >> s2;
    Tab t;
    t.level = i;
    t.star=s1;
    star1.push_back(t);
    t.star=s2;
    star2.push_back(t);
  }
  sort(star1.begin(), star1.end());
  sort(star2.begin(), star2.end());
  // print(star1);
  // print(star2);
  int count = 0;
  int i1 = 0, i2 = 0;
  bool fail = false;
  for (; i2 < star2.size();count++) {
    // cout << "i1 = "<< i1 << ", i2 = "<<i2;
    if (mark2[star2[i2].level] == 0 && star2[i2].star <= mystar) {
      int l = star2[i2].level;
      if (mark1[l] == 1) {
        mystar+=1;
      } else {
        mystar+=2;
      }
      mark1[l] = 1;
      mark2[l] = 1;
      i2++;
    } else {
      for (;mark1[star1[i1].level] == 1 && i1 < star1.size(); ++i1);
      if (i1 == star1.size() || star1[i1].star > mystar) {
        fail = true;
        break;
      }
      int l = star1[i1].level;
      mystar++;
      mark1[l] = 1;
      i1++;
    }
  }
  ou << "Case #" << t << ": ";
  if (fail) {
    ou << "Too Bad" <<endl;
  } else {
    ou << count <<endl;
  }
}

int main(int argc, char** argv) {
  ifstream in(argv[1]);
  int c;
  in >> c;
  for (int i = 0; i < c; ++i) {
    run(in, cout, i+1);
  }
}
