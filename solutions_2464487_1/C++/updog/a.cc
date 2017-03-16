#include "common.h"

bool Check(const int64 n, const int64 r0, const int64 vol) {
  double area_d = 2.0 * n * r0;
  area_d += n * (2.0 * n - 1.0);
  if (area_d > vol * 1.1) return false;
  
  int64 area = 2 * n * r0;
  area += n * (2*n - 1);
  return area <= vol;
}

void Work() {  // process one case
  int64 r0, vol;
  fin >> r0 >> vol;

  int c = 1, d = 807106780;
  while (c <= d) {
    const int mid = (c + d) >> 1;
    if (Check(mid, r0, vol)) {
      c = mid + 1;
    } else {
      d = mid - 1;
    }
  }
  fout << d << endl;
}

int main(const int argc, const char** argv) {
  CHECK(argc == 1);
  const string main_filename = SetFile(/*@*/" A-large    ");

  int num_test;  fin >> num_test;
  CHECK(Eoln(fin));  Readln(fin);
  
  showvar(num_test);
  forint (number, 1, num_test) { 
    fout << "Case #" << number << ": ";
    cerr << "Running on Case #" << number << endl;

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

