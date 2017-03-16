#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
  if (argc >= 1) {
    ifstream  file;
    int       cases;

    file.open(argv[1]);
    file >> cases;
    for (int c = 0; c < cases; c++) {
      int a, b, k;
      file >> a >> b >> k;
      unsigned long long sum = 0;
      for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
          if ((i&j) < k)
            ++sum;
      cout << "Case #" << c+1 << ": " << sum << endl;
    }
    file.close();
    return 0;
  }
  return 1;
}