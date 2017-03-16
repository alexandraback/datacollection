#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "Usage: a.out file_in file_out" << endl;
    return -1;
  }

  ifstream file_in;
  ofstream file_out;
  file_in.open(argv[1]);
  file_out.open(argv[2]);

  int T;
  file_in >> T;

  string sequence;
  char sign;
  int count;

  for (int t = 1; t <= T; t++) {
    file_in >> sequence;
    sign = sequence[0];
    count = 0;
    for (int i = 1; i < sequence.size(); i++) {
      cout << sign;
      if (sequence[i] != sign) {
        count += 1;
        sign = sequence[i];
      }
    }
    cout << sign << endl;
    if (sign == '-') {
      count += 1;
    }

    file_out << "Case #" << t << ": " << count << endl;

  }

  file_in.close();
  file_out.close();
}
