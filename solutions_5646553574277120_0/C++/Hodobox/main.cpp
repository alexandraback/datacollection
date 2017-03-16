#include <cstdio>
#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>




#ifdef DEBUG
#else
#define DBG(...)
#endif

using namespace std;

typedef long long ll;


int main() {

  int t, T;
  cin >> T;

  for (t=1; t<=T; t++)
    {
        int C, D, V;
        cin >> C >> D >> V;

        int values[V+1];
        for (int i=0; i<=V; i++) values[i] = 0;
        values[0] = 1;

        int completed = 0;
        for (int i=0; i<D; i++)
        {
              int denom;
              cin >> denom;
              for (int v = V; v >= 0; v--)
              {
                    if (v + denom <= V && values[v] && !values[v+denom])
                    {
                      values[v+denom] = 1;
                      completed++;
                    }
              }
        }

        for (int i=0; i<=V;i++) completed--;

        int added = 0;

        while (completed < V)
        {

              int num = -1;
              for (int i=0; i<=V; i++)
                {
                    if (!values[i]) { num = i; break; }
                }

              if (num == -1) break;

              for (int v = V; v >= 0; v--)
                {
                    if (v + num <= V && values[v] && !values[v+num])
                    {
                          values[v+num] = 1;
                          completed++;
                    }
                }

            added++;

        }

        cout << "Case #" << t << ": " << added << endl;
  }

  return 0;
}

