#include <iostream>
using namespace std;

int main()
{
  int T;
  cin >> T;
  
  int caseNum = 1;
  while(caseNum <= T)
  {
    long long r,t;
    cin >> r >> t;
    int count = 0;
    while(t > 0)
    {
      t -= (2 * r + 1);
      r += 2;
      if(t >= 0) count++;    
    }
    cout << "Case #" << caseNum << ": " << count << endl; 
  
    caseNum++;
  }

}
