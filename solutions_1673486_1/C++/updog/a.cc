#include "common.h"

int n, total;

vector<double> a;

void Readin() {  // process one case
  fin >> n >> total;
  a.clear();
  forint (i, 1, n) {
    double x;
    fin >> x;
    a.push_back(x);
  }
}

void Work() {  // process one case
  double ans = 1 + total;

  vector<double> prob(a.size());
  double tmp = 1.0;
  forall (i, a) prob[i] = tmp = tmp * a[i];

  forall (i, prob) {
    double val = prob[i] * (total - i - 1 + (n - i - 1)) +
                 (1 - prob[i]) * (total - i - 1 + (n - i - 1) + 1 + total);
    CheckMin(ans, val);
  }

  CheckMin(ans, (double)(n + total));

  fout << setprecision(12) << fixed;
  fout << ans + 1 << endl;
}

int main() {
  const string main_filename = SetFile(/*@*/"  A-large         ");

  int num_test;  fin >> num_test;
  assert(Eoln(fin));  Readln(fin);
  
  showvar(num_test);
  forint (number, 1, num_test) { 
    fout << "Case #" << number << ": ";
    cerr << "Running on Case #" << number << endl;

    Readin();
    Work();
    //fout << ans << endl;
  }

  if (!SeekEof(fin)) ABORT("Wrong! Not at EOF!");
  fclose(stdin);
  fclose(stdout);

  cerr << "\n\n---------- OUTPUT of " + main_filename + ": ----------" << endl;
  system(("cat " + main_filename + ".out >&2").c_str());
  return 0;
}

