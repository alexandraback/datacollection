#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

const int maxVal = 1000;

void Solve(multiset<int> &d, int depth, int count, int &min)
{
  if(depth != 0)
  {
    int max = *prev(d.end());

    for(int i=1; i<=max/2; i++)
    {
      int a, b;
      a=i;
      b=max-i;

      multiset<int> d2=d;

      auto last = prev(d2.end());

      d2.erase(last);

      d2.insert(a);
      d2.insert(b);

      int curmin = *prev(d2.end()) + count + 1;

      if(curmin < min)
        min = curmin;

      Solve(d2, depth-1, count + 1, min);
    }
  }
}

int main()
{
  int T;

  //ifstream in("test.in");
  //ofstream out("test.out");

  //ifstream in("B-small-attempt1.in");
  //ofstream out("B-small-attempt1.out");

  ifstream in("B-large.in");
  ofstream out("B-large.out");

  in >> T;

  vector<pair<int,int>> minSteps(maxVal + 1);

  for(int i=1; i<=maxVal; i++)
  {
    int min = i, del = 0;

    for(int j=1; j<=i;j++)
    {
      int curmin = j-1 + i/j;
      if(i%j != 0)
        curmin++;

      if(min > curmin)
      {
        min = curmin;
        del = j-1;
      }
    }

    minSteps[i] = pair<int,int>(del,min-del);
  }

  for(int i=0; i<T; ++i)
  {
    int solve = 0; 
    int n;
    multiset<int> d;

    in >> n;

    for(int j=0; j<n; j++)
    {
      int v;
      in >> v;
      d.insert(v);
    }

    vector<int> steps;
    int count = 0;
    int maxel = *prev(d.end());

    solve=maxel;
    //Solve(d,maxel,count,solve);

    vector<vector<int>> times(n+1, vector<int>(maxel+1, maxel + 1000));

    for(int j=0; j<=maxel; j++)
    {
      int curTime = j + maxel/(j+1);
      if(maxel%(j+1) != 0)
        curTime++;

      if(j > maxel)
        break;

      times[0][j] = curTime-j;
    }

    int st = 0;
    for(auto el = ++d.rbegin(); el != d.rend(); el++)
    {
      int elem = *el;
      for(int k=0;k<=maxel;k++)
      {
        int del = k;
        int time = times[st][k];

        for(int j=0; j<=minSteps[elem].first; j++)
        {
          int curTime = j + elem/(j+1);
          if(elem%(j+1) != 0)
            curTime++;

          if(del+j > maxel)
            break;

          if(times[st+1][del+j] == maxel + 1000 || times[st+1][del+j] > max(time,curTime-j))
            times[st+1][del+j] = max(time,curTime-j);
        }
      }

      st++;
    }

    vector<int> &sol = times[n-1];

    for(int k=0;k<=maxel;k++)
      if(solve > (k + sol[k]))
        solve = k + sol[k];

    out << "Case #"<<i+1<<": ";

    out << solve << endl;
  }

  return 0;
}