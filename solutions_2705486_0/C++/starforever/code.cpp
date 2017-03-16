#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <ctime>
#include <cassert>
using namespace std;

#define max2(a,b) (((a) > (b)) ? (a) : (b))
#define min2(a,b) (((a) < (b)) ? (a) : (b))

#define debug(x) cout << (#x) << ": " << (x) << endl
#define echo(x) cout << (#x) << endl
#define TIMER_A(timer) int timer = clock()
#define TIMER_B(timer) cerr << (#timer) << ": " << (double)(clock() - timer) / CLOCKS_PER_SEC << endl

typedef long long LL;
const double eps = 1e-9;
const double pi = M_PI;
const int inf = 2000000000; // 2e9
const LL inf64 = 9000000000000000000LL; // 9e18

const int dictSize = 521196;
const char *dictFileName = "dict.txt";

const int maxL = 4000;
const int minDis = 5;

int TN, TC;

string dict[dictSize];

int L;
string S;

int numChange[maxL][minDis];

void inputDict ()
{
  ifstream fin(dictFileName);
  string w;
  int n = 0;
  while (getline(fin, w))
    dict[n++] = w;
  fin.close();
}

void input ()
{
  getline(cin, S);
  L = S.size();
}

bool calcWordDiff (int p, int w, int &md, int &diff)
{
  if (p + dict[w].size() > L)
    return false;
  diff = 0;
  for (int i = 0; i < dict[w].size(); ++i)
  {
    if (dict[w][i] != S[p + i])
    {
      if (md > 0)
        return false;
      ++diff;
      md = minDis;
    }
    if (md > 0)
      --md;
  }
  return true;
}

int getNumChange (int p, int md)
{
  if (p == L)
    return 0;
  int &ret = numChange[p][md];
  if (ret != -1)
    return ret;
  ret = inf;
  for (int i = 0; i < dictSize; ++i)
  {
    int diff;
    int md2 = md;
    if (calcWordDiff(p, i, md2, diff))
    {
      int d = getNumChange(p + dict[i].size(), md2) + diff;
      ret = min2(ret, d);
    }
  }
  return ret;
}

void solve ()
{
  memset(numChange, -1, sizeof(numChange));
  printf("%d\n", getNumChange(0, 0));
}

int main ()
{
  inputDict();
  scanf("%d ", &TN);
  for (TC = 1; TC <= TN; ++TC)
  {
    input();
    printf("Case #%d: ", TC);
    solve();
  }
}
