#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

string s1, s2;

vector<int> p1;
vector<int> p2;

void gen(string &pattern, int pos, int cur, vector<int> &db)
{
  if(pos == pattern.size())
  {
    db.push_back(cur);
    return;
  }

  if(pattern[pos] == '?')
  {
    for(int i = 0; i < 10; i++)
    {
      gen(pattern, pos + 1, cur * 10 + i, db);
    }
  }
  else
  {
    gen(pattern, pos+1, cur * 10 + pattern[pos] - '0', db);
  }
}

void solve( )
{
  cin >> s1 >> s2;

  p1.clear();
  p2.clear();

  gen(s1, 0, 0, p1);
  gen(s2, 0, 0, p2);

  sort(p1.begin(), p1.end());
  sort(p2.begin(), p2.end());

  int i, j;
  pair <int, int> ret = make_pair(p1[0], p2[0]);
  int retD = fabs(p1[0] - p2[0]);

  for(i = 0; i < p1.size(); i++)
    for(j = 0; j < p2.size(); j ++)
    {
      int delta = fabs(p1[i] - p2[j]);
      if(delta < retD)
      {
        retD = delta;
        ret = make_pair(p1[i], p2[j]);
      }
    }

    char buff[100];
    snprintf(buff, sizeof(buff), "%d", (int)s1.size());
    string fmt = buff;

    fmt = "\%0" + fmt + "d " + "\%0" + fmt + "d\n";
    //cout << fmt << endl;
    printf(fmt.c_str(), ret.first, ret.second);
}

int main ()
{
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++)
  {
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}
