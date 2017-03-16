#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int flip(int x)
{
  int res = 0;
  while (x > 0)
  {
    res = res * 10 + (x % 10);
    x /= 10;
  }
  return res;
}

int main() {
  ifstream in("a-small.in");
  ofstream out("a-small.out");


  int ncases = 0;
  in >> ncases;
  auto arr = vector<int>(1000001);
  for (int icase = 0; icase < ncases; icase++)
  {
    int l;
    //long long n;
    int n;
    in >> n;
    //auto arr = vector<int>(n+1);
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
      arr[i] = arr[i - 1]+1;
      auto f = flip(i);
      if (i % 10 != 0 && f < i && (arr[f] + 1) < arr[i]) arr[i] = arr[f] + 1;
    }

    out << "Case #" << (icase + 1) << ": " << arr[n] << endl;  
  }

  in.close();
  out.close();
  return 0;
}

