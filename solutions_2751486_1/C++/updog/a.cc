#include "common.h"

void Readin() {  // process one case
}

void Work() {  // process one case
  string s;
  int kmin;

  fin >> s >> kmin;

  int b = 0, cnt = 0;
  int64 ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' &&
        s[i] != 'u' && s[i] != 'o') {
      ++cnt;
    } else {
      cnt = 0;
    }

    if (cnt == kmin) {
      ans += int64(s.size() - i) * int64(i - kmin + 1 - b + 1);
      b = i - kmin + 2;
      cnt = kmin - 1;
    }
  }

  fout << ans << endl;
}

int main(const int argc, const char** argv) {
  CHECK(argc == 1);
  const string main_filename = SetFile(/*@*/" A-large      ");

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
  fclose(stdin);
  fclose(stdout);

  cerr << "\n\n---------- OUTPUT of " + main_filename + ": ----------" << endl;
  system(("cat " + main_filename + ".out >&2").c_str());
  return 0;
}

