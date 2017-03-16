#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int T; cin >> T;
  for (int t=0; t<T; t++)
  {
    cout << "Case #" << t+1 << ": ";

    int n; cin >> n;
    vector<int> link(n);
    vector<int> data(n, -1);
    vector<int> mmax(n, 0);
    vector<int> tail(n, -1);
    
    int M = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> link[i];
      link[i]--; 
    }
    
    for (int i = 0; i < n; i++)
    {
      int k = link[i];
      if (link[k] == i)
      {
        data[i] = 1; 
        data[k] = 1; 
        tail[i] = i; 
        tail[k] = k;
        mmax[i] = 1; 
        mmax[k] = 1;
      }
    }
    
    for (int i = 0; i < n; i++)
    {
      if (data[i] < 1)
      {
        vector<int> temp(n, -1);
        int ko, k = i;
        for (int j = 0; data[k] < 0; j++)
        {
          temp[k] = j;
          data[k] = 0;
          ko = k;
          k = link[k];
        }
        
        if (temp[k] < 0)
        {
          if (data[k] > 0)
          {
            int m = temp[ko] + data[k] + 1;
            int r = tail[k]; 
            if (mmax[r] < m) mmax[r] = m;
            
            k = i;
            while (data[k] == 0)
            {
              data[k] = m--;
              tail[k] = r;
              k = link[k];
            }
          }
        }
        else
        {
          int m = temp[ko] - temp[k] + 1 ;
          if (M < m) M = m;
        }
      }  
    }

    for (int i = 0; i < n; i++)
    {
      int k = link[i];
      if (link[k] == i)
      {
        int m = mmax[i] + mmax[k];
        if (M < m) M = m;
      }
    }

    //for (int i = 0; i < n; i++) cout << data[i] << ":"; cout << endl;
    //for (int i = 0; i < n; i++) cout << tail[i] << ":"; cout << endl;
    //for (int i = 0; i < n; i++) cout << mmax[i] << ":"; cout << endl;
    
    cout << M << endl;
  }
  return 0;
}