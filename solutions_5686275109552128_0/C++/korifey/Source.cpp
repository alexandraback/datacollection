#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
vector<int> a;

bool isPossible(int p)
{
  if (p == 0) return false;
  
  for (int n = 0; n < p; n++)
  {
    int cur = 0;
    int m = p - n;
    for (int i = 0; i < a.size(); i++)
    {
      cur += (a[i] + m - 1) / m - 1;
    }
    if (cur <= n) return true;
  }
  return false;
}

int main() {
  ifstream in("b-small.in");
  ofstream out("b-small.out");


  int ncases = 0;
  in >> ncases;
  cout << ncases;
  

  for (int icase = 0; icase < ncases; icase++)
  {
    int n;
    in >> n;
    
    a = vector<int>(n);
    for (int i = 0; i < n; i++) {
      in >> a[i];
    }

    int lo = 0;
    int hi = 1000;
    while (lo < hi - 1)
    {
      int m = (lo + hi) / 2;
      if (isPossible(m))
      {
        hi = m;
      } else
      {
        lo = m;
      }
    }

    out << "Case #"<<(icase+1)<<": " <<hi << endl;
  }

  in.close();
  out.close();
  return 0;
}

