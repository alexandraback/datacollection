#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <cassert>
#include <map>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> pii;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);
  
  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

map<string, int> words[2];

int readstr(int side)
{
    char buf[30];
    scanf(" %s", buf);
    string s(buf);
    if(!words[side].count(s))
    {
        int k = words[side].size();
        words[side][s] = k;
    }
    return words[side][s];
}

int main()
{
    int TT;
    scanf("%d", &TT);
    for(int TI = 1; TI <= TT; TI++)
    {
        int n;
        scanf("%d", &n);
        words[0].clear();
        words[1].clear();
        int ea[n], eb[n];
        
        for(int i=0;i<n;i++)
        {
            ea[i] = readstr(0);
            eb[i] = readstr(1);
            //printf("%d %d\n", ea[i], eb[i]);
        }
        int A = words[0].size(), B = words[1].size();
        VVI w(A);
        for(int i=0;i<A;i++)
            w[i] = VI(B);
        for(int i=0;i<n;i++)
            w[ea[i]][eb[i]]++;
        VI mr(A), mc(B);

        int match = BipartiteMatching(w, mr, mc);
        int edgeCover = A + B - match;
        int ans = n - edgeCover;
              
        printf("Case #%d: %d\n", TI, ans);
    }
}
