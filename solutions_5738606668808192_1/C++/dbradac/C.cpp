#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 15000;

vector <int> Prosti;
int sito[MAX];
int p[100];
int djel[15];
map <string, int> M;

void Gen(int len)
{
  p[0] = p[len-1] = 1;
  for (int i=1; i<len-1; i++)
    p[i] = rand() & 1;
}

int Prov(int len)
{
  string s;
  for (int i=0; i<len; i++)
    s.push_back((char) ('0' + p[i]));

  if (M[s])
    return 0;

  for (int i=2; i<=10; i++) {
    int da = 0;
    for (auto it : Prosti) {
      int ost = 0;

      for (int j=0; j<len; j++)
        ost = (ost * i + p[j]) % it;
  
      if (!ost) {
        djel[i] = it;
        da = 1;
        break;
      }
    }

    if (!da)
      return 0;
  }

  return M[s] = 1;
}

void Sito()
{
  for (int i=2; i<MAX; i++) {
    if (!sito[i]) {
      Prosti.push_back(i);
      for (int j=i; j<MAX; j+=i)
        sito[j] = 1;
    }
  }
}

int main()
{
  Sito();

  int len, kol;

  scanf("%*d%d%d", &len, &kol);
  printf("Case #1:\n");

  for (; kol;) {
    Gen(len);
    if (Prov(len)) {
      for (int i=0; i<len; i++)
        printf("%d", p[i]);

      for (int i=2; i<=10; i++)
        printf(" %d", djel[i]);
      printf("\n");
      kol--;
    }
  }

  return 0;
}

