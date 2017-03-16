#include "common.h"

void Readin() {  // process one case
}

void Work() {  // process one case
  int n, s, lb;
  cin >> n >> s >> lb;

  int re = 0;
  forint (i, 1, n) {
    int sum, x;
    cin >> sum;
    x = sum / 3;
    if (sum % 3 == 0) {
      if (x >= lb) { ++re; continue; }
      if (s > 0 && x > 0 && x < 10 && x + 1 >= lb) { --s; ++re; continue; }
    } else if (sum % 3 == 1) {
      if (x + 1 >= lb) { ++re; continue; }
    } else {
      if (x + 1 >= lb) { ++re; continue; }
      if (s > 0 && x + 2 <= 10 && x + 2 >= lb) { --s; ++re; continue; }
    }
  }
  cout << re << endl;
}

int main() {
  const string main_filename = 
      SetFile("      B-small-attempt1          ");

  int num_test;  cin >> num_test;
  assert(Eoln(cin));  Readln(cin);
  
  showvar(num_test);
  forint (number, 1, num_test) { 
    cout << "Case #" << number << ": ";
    cerr << "Running on Case #" << number << endl;

    Readin();
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

