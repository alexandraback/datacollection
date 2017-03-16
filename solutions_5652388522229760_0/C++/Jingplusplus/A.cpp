#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

  if (argc != 3) {
    cout << "Useage: a.out file_in file_out" << endl;
    return -1;
  }


  ifstream file_in;
  ofstream file_out;
  file_in.open(argv[1]);
  file_out.open(argv[2]);

  int T;
  file_in >> T;

  int N;
  long value;
  int flag;
  int digit;
  int count;


  for (int t = 1; t <= T; t++) {
    file_in >> N;
    value = 0;
    flag = 0;
    count = 0;

    if (N == 0) {
      file_out << "Case #" << t << ": INSOMNIA" << endl;
      continue;
    }

    while (true) {
      count += 1;
      value = (long)count * (long)N;
      while (value > 0) {
        digit = value % 10;
        value = value / 10;
        flag |= 1 << digit;
      }

      if (flag == 1023) {
        file_out << "Case #" << t << ": " << (long)count * (long)N << endl;
        break;
      }

    }
  }

  file_in.close();
  file_out.close();
  return 0;
}
