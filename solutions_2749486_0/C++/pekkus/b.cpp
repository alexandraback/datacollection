#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF 100000000

int main()
{
  int T; cin >> T;
  for(int test_case = 1; test_case <= T; ++ test_case)
  {
    int X, Y; cin >> X >> Y;
    int x = 0, y = 0;
    int c = 1;
    stringstream ss;
    if (abs(X) < abs(Y))
    {
      while (x != X)
      {
        if (c == abs(Y))
        {
          if (Y < 0)
          {
            y -= c;
            ss << 'S';
          }
          else
          {
            y += c;
            ss << 'N';
          }
          c++;
        }
        if (x < X)
        {
          x -= c;
          c++;
          x += c;
          c++;
          ss << 'W' << 'E';
        }
        else if (x > X)
        {
          x += c;
          c++;
          x -= c;
          c++;
          ss << 'E' << 'W';
        }
      }
      while (y != Y)
      {
        if (y < Y)
        {
          y -= c;
          c++;
          y += c;
          c++;
          ss << 'S' << 'N';
        } 
        else if (y > Y)
        {
          y += c;
          c++;
          y -= c;
          c++;
          ss << 'N' << 'S';
        }
      }
    }
    else
    {
      while (y != Y)
      {
        if (c == abs(X))
        {
          if (X < 0)
          {
            x -= c;
            ss << 'W';
          }
          else if (X > 0)
          {
            x += c;
            ss << 'E';
          }
          c++;
        }
        if (y < Y)
        {
          y -= c;
          c++;
          y += c;
          c++;
          ss << 'S' << 'N';
        } 
        else if (y > Y)
        {
          y += c;
          c++;
          y -= c;
          c++;
          ss << 'N' << 'S';
        }
      }
      while (x != X)
      {
        if (x < X)
        {
          x -= c;
          c++;
          x += c;
          c++;
          ss << 'W' << 'E';
        }
        else if (x > X)
        {
          x += c;
          c++;
          x -= c;
          c++;
          ss << 'E' << 'W';
        }
      }
    }
    cout << "Case #" << test_case << ": " << ss.str() << endl;
  }
}

