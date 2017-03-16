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

struct Node
{
  bool t;
  Node *c[26];

  Node ()
  {
    t = false;
    memset(c, 0, sizeof(Node*) * 26);
  }
};

Node *root;

int L;
string S;

int numChange[maxL][minDis];

void buildDict (string word)
{
  Node *p = root;
  for (int i = 0; i < word.size(); ++i)
  {
    int d = word[i] - 'a';
    if (!p->c[d])
      p->c[d] = new Node();
    p = p->c[d];
  }
  p->t = true;
}

void inputDict ()
{
  ifstream fin(dictFileName);
  string w;
  root = new Node();
  while (getline(fin, w))
    buildDict(w);
  fin.close();
}

void input ()
{
  getline(cin, S);
  L = S.size();
}

int getNumChange (int p, int md);

int searchWord (Node *p, int p1, int diff, int md)
{
  if (!p)
    return inf;
  if (p1 > L)
    return inf;
  int ret = inf;
  int r;
  if (p->t)
  {
    r = getNumChange(p1, md) + diff;
    ret = min2(ret, r);
  }
  r = searchWord(p->c[S[p1] - 'a'], p1 + 1, diff, md > 0 ? md - 1 : 0);
  ret = min2(ret, r);
  if (md == 0)
  {
    for (int i = 0; i < 26; ++i)
      if (S[p1] - 'a' != i)
      {
        r = searchWord(p->c[i], p1 + 1, diff + 1, minDis - 1);
        ret = min2(ret, r);
      }
  }
  return ret;
}

int getNumChange (int p, int md)
{
  if (p == L)
    return 0;
  int &ret = numChange[p][md];
  if (ret != -1)
    return ret;
  return ret = searchWord(root, p, 0, md);
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
