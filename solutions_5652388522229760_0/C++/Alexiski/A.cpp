#include <iostream>
#include <set>

using namespace std;

int test(int n)
{
  set<int> digits;
  for (int i=0; i<100; i++)
  {
    int k = i*n;
    while (k)
    {
      digits.insert(k % 10);
      k /= 10;
    }
    if (digits.size() == 10) return i*n;
  }
  return 0;
}

int main()
{
  int T; cin >> T;
  for (int t=0; t<T; t++)
  {
    cout << "Case #" << t+1 << ": ";
    int n; cin >> n;
    if (n) 
      cout << test(n);
    else 
      cout << "INSOMNIA";
    cout << endl;
  }
  return 0;
}