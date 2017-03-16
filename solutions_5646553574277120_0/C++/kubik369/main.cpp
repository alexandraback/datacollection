#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>

#define LL long long

using namespace std;

int main() {

  int t, T;
  cin >> T;

  for (t=0; t<T; t++) {
    int C, D, V;
    cin >> C >> D >> V;

    int a[V+1];
    for (int i = 0; i <= V; i++) a[i] = 0;
    a[0] = 1;
    int getDone = 0;
    for (int i=0; i<D; i++)
    {
        int den;
        cin >> den;
        for (int v = V; v >= 0; v--)
        {
            if (v + den <= V && a[v] && !a[v+den])
            {
              a[v+den] = 1;
              getDone++;
            }
        }
    }
    getDone--;
    int miss = 0;
    while (getDone < V)
    {
        int num = -1;
        for (int i = 0; i <= V; i++)
        {
            if (!a[i])
            {
                num = i;
                break;
            }
        }
        if (num == -1) break;
        for (int v = V; v >= 0; v--)
        {
            if (v + num <= V && a[v] && !a[v+num])
            {
                a[v+num] = 1;
                getDone++;
            }
        }
        miss++;
    }
    cout << "Case #" << t + 1 << ": " << miss << endl;
  }
  return 0;
}

