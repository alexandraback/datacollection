#include <iostream>
#include <fstream>

using namespace std;

int min(int a, int b)
{
  if (a < b)
    return (a);
  else
    return (b);
}

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
      for (int i = 0; i < a; i++)
      {
        if (i < k)
          sum += b;
        else
        {
          sum += min(k, b);
          for (int j = k; j < b; j++)
          {
            // cout << i << " & " << j << " = " << (i&j) << endl;
            if ((i&j) < k)
              sum++;
          }
        }
      }
      cout << "Case #" << c+1 << ": " << sum << endl;
    }
    file.close();
    return 0;
  }
  return 1;
}