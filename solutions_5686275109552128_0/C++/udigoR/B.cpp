#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

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

  ifstream in("B-small-attempt1.in");
  ofstream out("B-small-attempt1.out");

  //ifstream in("B-large.in");
  //ofstream out("B-large.out");

  in >> T;

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

    Solve(d,maxel,count,solve);

    //while(count < maxel)
    /*while(1)
    {
    auto last = prev(d.end());
    int max = *last, a, b;

    steps.push_back(count + max);

    if(max == 1)
    break;

    a = max / 2;
    b = max - a;

    d.erase(last);

    d.insert(a);
    d.insert(b);

    count ++;
    }

    steps.push_back(count + *(prev(d.end())));

    solve = steps[0];

    for(auto it = steps.begin(); it!= steps.end(); it++)
    if(solve > *it)
    solve = *it;*/

    out << "Case #"<<i+1<<": ";

    out << solve << endl;
  }

  return 0;
}