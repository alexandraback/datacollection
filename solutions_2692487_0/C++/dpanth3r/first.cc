#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve()
{
  uint a, n;
  cin >> a >> n;
  
  vector<uint> motes(n);
  for(uint i = 0; i < n; i++)
    cin >> motes[i];
  
  if(a == 1)
  {
    cout << n;
    return;
  }
  
  sort(motes.begin(), motes.end());
  vector<uint> mods;
  
  uint mod = 0;
  for(uint i = 0; i < n; i++)
  {
    uint m = motes[i];
    if(m < a)
      a += m;
    else
    {
      mods.push_back(mod + (n - i));
      
      do
      {
        mod += 1;
        a += a - 1;
      }
      while(a <= m);

      a += m;
    }
  }
  
  mods.push_back(mod);
  
  cout << *min_element(mods.begin(), mods.end());
}

int main(int argc, char *argv[])
{
  int N;
  cin >> N;
  
  for(int i = 1; i <= N; i++)
  {
    cout << "Case #" << i << ": ";
    solve();
    cout << endl;
  }
  
  return 0;
}


