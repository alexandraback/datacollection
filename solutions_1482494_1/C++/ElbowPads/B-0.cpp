#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <iomanip>
#include <stdint.h>

using namespace std;

bool mycompare (pair<int, int> j,pair<int, int> i)
{
  if (i.second<j.second)
    return true;
  if (i.second==j.second)
    return i.first > j.first;
  return false;
}

int doTurn(list<pair<int, int> > &cost_vec, int stars)
{
  // first go from the back and see if you can finish a level off, if you can,
  // do this
  auto riter = cost_vec.end();
  riter--;
  int firstval = riter->first;
  int secondval = riter->second;
  if(secondval <= stars)
  {
    cost_vec.erase(riter);
    //cout << "DEBUG-rem2: " << riter->first << " " << riter->second << endl;
    if(firstval == -1)
      return 1;
    return 2;
  }
  // otherwise go down the front till you find the highest v
  for(auto iter = cost_vec.begin(); iter != cost_vec.end(); iter++)
  {
    if(iter->first <= stars && iter->first != -1)
    {
      iter->first = -1;
      //cout << "DEBUG-rem1: " << iter->first << " " << iter->second << endl;
      return 1;
    }
    if(iter->second <= stars)
    {
      cost_vec.erase(iter);
      //cout << "DEBUG-rem1: " << iter->first << " " << iter->second << endl;
      return 1;
    }
  }


  return 0;
}

string doCase(istream & in)
{
  int N;
  in >> N;
  list<pair<int, int> > cost_vec;
  for(int i=0; i < N; i++)
  {
    int a, b;
    in >> a >> b;
    bool ins = false;
    for(auto mi = cost_vec.begin(); mi != cost_vec.end(); mi++)
    {
      //cout << "DEBUGL: " << mi->first << " " << mi->second << endl;
      pair<int, int> item = make_pair(a,b);
      if(!mycompare(*mi, item))
      {
        //cout << "DEBUGIS: " << item.first << " " << item.second << endl;
        cost_vec.insert(mi, item);
        ins = true;
        break;
      }
    }
    if(!ins)
    {
      //cout << "DEBUGEND: " << a << " " << b << endl;
      cost_vec.push_back(make_pair(a,b));
    }
      //cout << "DEBUG=============" << endl;
  }
  //sort(cost_vec.begin(), cost_vec.end(), mycompare);
  for(auto it = cost_vec.begin(); it != cost_vec.end(); it++)
  {
    //cout << "DEBUG: " << it->first << " " << it->second << endl;
  }

  int plays = 0;
  int stars = 0;


  do{
    int starreduc = doTurn(cost_vec, stars);
    if(starreduc == 0)
      return "Too Bad";
    stars += starreduc;
    plays++;
  }while(!cost_vec.empty());
  ostringstream oss;
  oss << plays;
  return oss.str();
}

int main() {
  uint64_t T;
  cin >> T;
  for (uint64_t Ti = 1; Ti <= T; ++Ti) {
    cout << "Case #" << Ti << ": " << doCase(cin) << endl;
  }
  return 0;
}
