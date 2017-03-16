#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream fin("/usr/local/google/home/zhouyuanl/Downloads/A-large.in");
  // ifstream fin("/tmp/temp.txt");
  ofstream fout("/usr/local/google/home/zhouyuanl/Downloads/A-large-practice.out");
  int T;
  fin >> T;
  int original[1001];
  int accumulation[1001];
  int difference[1001];
  for (int i = 1; i <= T; i++) {
    int s_max;
    fin >> s_max;
    char c;
    while ((c = fin.get()) == ' ');
    original[0] = c - '0';
    for (int j = 1; j <= s_max; j++) {
      original[j] = fin.get() - '0';
    }
    accumulation[0] = original[0];
    for (int j = 1; j <= s_max; j++) {
      accumulation[j] = accumulation[j - 1] + original[j];
    }

    for (int j = 0; j < s_max; j++) {
      if (j + 1 > accumulation[j]) {
        difference[j] = j + 1 - accumulation[j];
      }
      else {
        difference[j] = 0;
      }
    }
    int need = 0;
    for (int j = 0; j < s_max; j++) {
      if (difference[j] > need) {
        need = difference[j];
      }
    }
    fout << "Case #" << i << ": " << need << endl;
  }
	return 0;
}
