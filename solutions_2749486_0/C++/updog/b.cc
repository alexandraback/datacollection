#include "common.h"

void Readin() {  // process one case
}

void Jump(const int len, const char ch1, const char ch2) {
  showvar(len);
  showvar(ch1);
  showvar(ch2);
  for (int i = 0; i < len; ++i) fout << ch1 << ch2;
}

void Work() {  // process one case
  int x, y;
  fin >> x >> y;
  cerr << x << ' ' << y << endl;

  if (x < 0) Jump(-x, 'E', 'W'); else Jump(x, 'W', 'E');
  if (y < 0) Jump(-y, 'N', 'S'); else Jump(y, 'S', 'N');
  fout << endl;
}

int main(const int argc, const char** argv) {
  CHECK(argc == 1);
  const string main_filename = SetFile(/*@*/"B-small-attempt0    ");

  int num_test;  fin >> num_test;
  CHECK(Eoln(fin));  Readln(fin);
  
  showvar(num_test);
  forint (number, 1, num_test) { 
    fout << "Case #" << number << ": ";
    cerr << "Running on Case #" << number << endl;

    Readin();
    Work();
    //fout << ans << endl;
  }

  if (!SeekEof(fin)) ABORT("Wrong! Not at EOF!");
  fin.close();
  fout.close();

  cerr << "\n\n---------- OUTPUT of " + main_filename + ": ----------" << endl;
  system(("cat " + main_filename + ".out >&2").c_str());
  return 0;
}

