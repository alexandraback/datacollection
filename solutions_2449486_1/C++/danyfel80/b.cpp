#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <climits>
#include <cstring>
#include <string>
#include <iterator>
#include <cstdio>

using namespace std;

int lawn[100][100];
bool visited[100][100];

int main()
{
  int cases, caseno = 1, n, m;
  cin >> cases;
  while(cases--)
  {
    cout << "Case #" << caseno++ << ": ";
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
      for(int j = 0 ; j < m; j++)
      {
        cin >> lawn[i][j];
        visited[i][j] = false;
      }
    }
    bool possible = true;
    for(int i = 0; i < n && possible; i++)
    {
      for(int j = 0; j < m && possible; j++)
      {
        //check horizontally
        for(int k = 0; k < n && possible; k++)
        {
          if(lawn[i][j] < lawn[k][j])
            possible = false;
        }
        if(!possible)
        {
          possible = true;
          //check vertically
          for(int k = 0; k < m && possible; k++)
          {
            if(lawn[i][j] < lawn[i][k])
              possible = false;
          }
        }
      }
    }
    cout << ((possible)? "YES": "NO");
    cout << endl;
  }
  return 0;
}
