#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int T;
  cin >> T;
  int caseNum = 1;
  
  while(caseNum <= T)
  {
    int M,N;
    cin >> M >> N;
    
    vector< vector<float> > h(M,0);
    for(int i=0;i<M;i++)
    {
      vector<float> v(N,0);
      h[i] = v;
    }
    
    for(int i=0;i<M;i++)
    {
      for(int j=0;j<N;j++)
      {
        cin >> h[i][j];
      }
    }
    
    bool ok = true;
    for(int i=0;i<M;i++)
    {
      for(int j=0;j<N;j++)
      {
        bool ok_x = true, ok_y = true;
        for(int k=0;k<M;k++)
        {
          if(h[k][j] > h[i][j]) {ok_x = false; break;}
        }
        
        for(int k=0;k<N;k++)
        {
          if(h[i][k] > h[i][j]) {ok_y = false; break;}
        }
        
        if(!(ok_x) && !(ok_y)) {ok = false; break;}
      }      
    }
    if(ok) cout << "Case #" << caseNum << ": YES" << endl;
    else cout << "Case #" << caseNum << ": NO" << endl;
  
    caseNum++;
  }

  return 0;
}
