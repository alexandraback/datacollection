#include "common.h"

string GetDeci(int x) {
  string deci_x;
  for (int tmp = x; tmp != 0; tmp /= 10) deci_x.push_back('0' + tmp % 10);
  reverse(deci_x.begin(), deci_x.end());
  return deci_x;
}
  

int Process(int x, const string &deci_lb, const string &deci_ub) {
  const string deci_x = GetDeci(x);

  string deci_cur = deci_x;
  vector<string> a;
  forall (i, deci_x) {
    if ((deci_cur.size() > deci_lb.size() || deci_cur >= deci_lb) &&
        (deci_cur.size() < deci_ub.size() || deci_cur <= deci_ub)) {
      if (deci_cur[0] == '0') continue;
      a.push_back(deci_cur);
    }
    std::rotate(deci_cur.begin(), deci_cur.begin() + 1, deci_cur.end());
  }
  
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  assert(!a.empty());
  if (a.front() != deci_x) return 0;

  //if (a.size() >= 2) showall(a);
  
  return a.size() * (a.size() - 1) / 2;
}

void Work() {  // process one case
  int lb, ub;
  cin >> lb >> ub;
  const string deci_lb = GetDeci(lb);
  const string deci_ub = GetDeci(ub);

  int re = 0;
  forint (x, lb, ub) {
    re += Process(x, deci_lb, deci_ub);
  }
  cout << re << endl;
}

int main() {
  const string main_filename = 
      SetFile("       C-small-attempt0.in.         ");

  int num_test;  cin >> num_test;
  assert(Eoln(cin));  Readln(cin);
  
  showvar(num_test);
  forint (number, 1, num_test) { 
    cout << "Case #" << number << ": ";
    cerr << "Running on Case #" << number << endl;

    Work();
    //cout << ans << endl;
  }

  if (!SeekEof(cin)) ABORT("Wrong! Not at EOF!");
  fclose(stdin);
  fclose(stdout);

  cerr << "\n\n--------------- OUTPUT: ----------------" << endl;
  system(("cat " + main_filename + ".out >&2").c_str());
  return 0;
}

