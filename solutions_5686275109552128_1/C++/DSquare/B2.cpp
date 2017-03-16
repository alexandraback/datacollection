#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
  bool dev = false;
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t)
  {
    int D;
    cin >> D;
    vector<int> height(D, 0);
    for (int i = 0; i < D; ++i) 
    {
      cin >> height[i];
    }
    
    sort(height.begin(), height.end(), greater<int>());

    bool done = false;
    int sol = height[0];
    int top = sol;
    while(!done)
    {
      done = true;
      for (int i = top; i >= 2; --i)
      {
        double target = i;
        int accCost = 0;
        //cout << " target " << target << endl;
        for(int j = 0; j < D; ++j)
        {
          double h = height[j];
          if (h <= target) continue;
          int nTowers = ceil(h/target);
          accCost += (nTowers - 1); // - numTowers[i]
          
          //cout << h << " -> " << nTowers << endl;
        }      
        if (sol > target + accCost)
        {
          sol = target + accCost;
        }
      }
    }
    cout << "Case #" << t << ": " << sol << endl;
    
  }
  
  return 0;
}








