#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <list>

using namespace std;

int N;
int s[501];

bool solve(const int level, const int c, map<int, list<int> > sm, list<int> sl)
{
  if(level >= N)
    return false;
  for(int i = 0 ; i < N; ++i)
  {
    int tmp = c + s[i];
    list<int> tmpl = sl;
    tmpl.push_back(i);
    if(sm.find(tmp) != sm.end()) {
      // bingo
      printf("bingo %d\n", tmp);
      return true;
    }
    sm[tmp] = tmpl;
    bool f = solve(level + 1, tmp, sm, tmpl);
    if(f)
      return true;
  }
  return false;
}

int main() 
{
  int T;
  scanf("%d\n", &T);
  for(int tc = 1; tc <= T; ++tc)
  {
    printf("Case #%d:\n", tc);
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    {
      int S;
      scanf("%d", &S);
      s[i] = S;
    }
    map<int, set<int> > sm;
    bool find = false;
    for(int i = 0; i < N; ++i)
    {
      set<int> l;
      l.insert(s[i]);
      sm[s[i]] = l;
    }
    while(!find)
    {
      for(int i = 0; i < N; ++i)
      {
        map<int, set<int> >::iterator it    = sm.begin();
        map<int, set<int> >::iterator itEnd = sm.end();
        for(;it != itEnd; ++it)
        {
          int sum    = (*it).first;
          set<int> l = (*it).second;
          if(l.find(s[i]) != l.end())
            continue;
          sum += s[i];
          l.insert(s[i]);
          if(sm.find(sum) != sm.end()) {
            set<int> l2 = (*(sm.find(sum))).second;
            if(l2 != l) {
            //printf("sum %d ", sum);
            find = true;
            set<int>::iterator sit    = l.begin();
            set<int>::iterator sitEnd = l.end();
            for(;sit != sitEnd;++sit)
            {
              printf("%d ", *sit);
            }
            printf("\n");
            sit    = l2.begin();
            sitEnd = l2.end();
            for(;sit != sitEnd;++sit)
            {
              printf("%d ", *sit);
            }
            printf("\n");
            break;
            }
          }
          sm[sum] = l;
        }
        if(find)
          break;
      }
    }
  }
}
