#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char** argv) {
  ifstream ifs(argv[1]);
  ofstream ofs(argv[2]);

  const char code[27] = "yhesocvxduiglbkrztnwjpfmaq";

  unsigned T = 0;
  ifs >> T;

  string dummyLine;
  getline(ifs, dummyLine);

  for (unsigned t = 0; t < T; ++t) {
    string line;
    getline(ifs, line);

    for (unsigned p = 0; p < line.size(); ++p) {
      const char c = line[p];
      if (c == ' ') continue;
      line[p] = code[c - 'a'];
    }

    // Output.
    ofs << "Case #" << t + 1 << ": " << line.c_str() << endl;
  }

  return 0;
}
