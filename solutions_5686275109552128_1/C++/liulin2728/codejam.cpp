#include <iostream>
#include <cmath>
#include <string>
#include <set>

using namespace std;

int rankPank(multiset<int> pank)
{
  if (*pank.rbegin() <= 3) return *pank.rbegin();
  else {
    int i = *pank.rbegin();
    int use9 = 10;
    if (i == 9) {
      multiset<int> nPank(pank);
      nPank.erase(--nPank.end());
      nPank.insert(3);
      nPank.insert(3);
      nPank.insert(3);
      use9 = rankPank(nPank) + 2;
    }

    int x = i/2;
    int y = i/2 + i%2;
    pank.erase(--pank.end());
    pank.insert(x);
    pank.insert(y);
    int use = rankPank(pank) + 1;
    use = use < use9 ? use : use9;
    return  use < i ? use : i;  
  }
}

int main(int argc, char *argv[])
{
  string name = "B-large";
  string path = "";

  freopen((path + name + ".in").c_str(), "r", stdin);
  freopen((path + name + ".out").c_str(), "w", stdout);

  int test_cases;
  cin >> test_cases;
  for (int test_case = 1; test_case <= test_cases; test_case++) {
    int number;
    cin >> number;
    multiset<int> pank;
    for (int i = 0; i < number; i++) {
      int x = 0;
      cin >> x;
      pank.insert(x);  
    }
    int best = 1000;

    for (int i = 1; i <= *pank.rbegin(); i++) {
      int use = 0;
      auto iter = pank.rbegin();
      while (iter != pank.rend() && *iter > i) {
        use += (*iter + i - 1)/i - 1;
        iter++;
      } 
      use += i;
      best = best < use ? best : use;
    }
  
    cout << "Case #" << test_case << ": " << best << endl;
    cout.flush();
  }
  fclose(stdout);
  fclose(stdin);
  return 0;
}
