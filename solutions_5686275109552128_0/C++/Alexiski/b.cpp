#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int T; cin >> T;
  for (int ii = 0; ii<T; ii++)
  {
    int d; cin >> d;
    vector<int> data(d);
    int m = 0;
    for (int i=0; i<d; i++) 
    {
      cin >> data[i];
      if (data[i] > m) m = data[i];
    }
    int rec = m;
    for (int k=1; k<m; k++)
    {
      int cur = k;
      for (int i=0; i<d; i++) 
      {
        cur += (data[i]-1)/k;
      }
      //cout << k << ":" << cur << endl;
      if (cur < rec) rec = cur;
    }
	
    cout << "Case #" << ii+1 << ": " << rec << endl;
  }
  return 0;
}
