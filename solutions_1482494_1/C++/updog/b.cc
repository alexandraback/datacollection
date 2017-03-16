#include "common.h"

int n;
int a[2000], b[2000];

void Readin() {  // process one case
  fin >> n;
  forint (i, 1, n) {
    fin >> a[i] >> b[i];
    CHECK(a[i] <= b[i]);
  }
}

void Work() {  // process one case
  const int inf = 99999999;

  int max = -inf;
  
  int ans = 0;
  int star = 0, completed = 0;
  forint (round, 1, 3*n) {
    forint (i, 1, n) {
      if (star >= b[i]) {
        ++ans;
        ++completed;
        star += (a[i] != inf) ? 2 : 1;
        a[i] = b[i] = inf;
        goto next;
      }
    }

    max = -inf;
    forint (i, 1, n) {
      if (star >= a[i]) {
        CHECK(b[i] != inf);
        CheckMax(max, b[i]);
      }
    }
    
    forint (i, 1, n) {
      if (star >= a[i] && b[i] == max) {
        ++ans;
        star += 1;
        a[i] = inf;
        goto next;
      }
    }

 next:;
  }

  if (completed < n) {
    fout << "Too Bad" << endl;
  } else {
    fout << ans << endl;
  }
}

int main() {
  const string main_filename = SetFile(/*@*/"     B-large      ");

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

