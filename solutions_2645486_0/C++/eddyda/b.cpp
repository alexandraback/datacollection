#include <vector>
#include <valarray>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>
using namespace std;
#define ulli unsigned long long int

int v[10] = {0};
int maxGain = 0;

int getGain(vector<int> e)
{
  int retval = 0;
  for (int i = 0; i < e.size(); ++i)
    retval += e[i] * v[i];

  return retval;
}

int main()
{
  freopen("B-small-attempt0.in", "rt", stdin);
  freopen("B-small-attempt0.out", "wt", stdout);

  int T;
  int E, R, N;
  cin>>T;
  for (int c=1; c<=T; c++)
  {
    printf("Case #%d:", c);
    cin>>E>>R>>N;
    for (int i = 0; i < N; ++i)
      cin>>v[i];
    
    maxGain = 0;
    //DFS
    stack< pair< vector<int>, int > > st;

    st.push( pair< vector<int> , int> ( vector<int>(), E));
    while(!st.empty())
    {
      vector<int> current = st.top().first;
      int energy = st.top().second;
      st.pop();

      if (current.size() == N)
      {
        int gain = getGain(current);
        if (gain > maxGain) maxGain = gain;
      }
      else
      {
        for (int e = 0; e <= energy; ++e)
        {
          vector<int> next = current;
          int nextE = energy - e + R;
          if (nextE > E) nextE = E;
          next.push_back(e);
          st.push(pair< vector<int> , int> (next, nextE) );
        }
      }
      
    }

    printf(" %d\n", maxGain);
  }
}
