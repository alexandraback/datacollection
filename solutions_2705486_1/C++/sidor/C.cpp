#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int INF = 1000000;
const int MAXN = 5000;
char s[MAXN];

string input;
vector<string> dict;

void preprocess() {
  for(int i=0; i<521196; ++i) {
    scanf("%s ", s);
    dict.push_back(string(s));
  }
}

class edge {
 public:
  int noerr, lerror, rerror, length;
  edge(int a, int b, int c,int d) {
    noerr = a;
    lerror = b;
    rerror = c;
    length = d;
  }
};

vector<edge> edges[MAXN];
int dp[MAXN][10];
int ntc;
void solve() {
  scanf("%s", s);
  input = string(s);
  //printf("%s\n", input.c_str());
  ///*
  for(int i=0; i< input.size(); ++i) {
    edges[i].clear();
    for (int j=0; j<dict.size(); ++j) {
      const string& w = dict[j];
      if (i+w.size()>input.size()) continue;
      bool can_be = true;
      int lerror= -1, rerror = -1, noerr = 0;
      for(int k=0; k<w.size(); ++k) {
        if (w[k] != input[i+k]) {
          ++noerr;
          if (lerror == -1) lerror = k;
          if (rerror != -1 && k - rerror < 5) { can_be = false; break; }
          rerror = k;
        }
      }
      if(!can_be) continue;
      //printf("%d:(%d,%d,%d) -%s\n", i,lerror,rerror, i+w.size(), w.c_str());
      edges[i].push_back(edge(noerr, lerror, rerror, w.size()));
    }
  }
  //*/
  //edges[0].push_back(edge(1,1,1,4));
  //edges[4].push_back(edge(1,2,2,3));

  for(int i=0; i<=input.size(); ++i) {
    for(int j=0; j<10; ++j) {
      dp[i][j] = INF;
    }
  }
  for(int j=0; j<10; ++j) {
    dp[0][j] = 0;
  }


  for(int i=0; i<input.size(); ++i) {
    for (int e=0; e<edges[i].size(); ++e) {
      const edge& ed = edges[i][e];
      int start_res = INF;
      for (int free_spots = 3; free_spots >=0; --free_spots)
        dp[i][free_spots] = min(dp[i][free_spots+1], dp[i][free_spots]);
      for (int free_spots = 0; free_spots < 5; ++free_spots) {
        if(ed.noerr == 0) {
          int& nxt = dp[i+ed.length][min(free_spots+ed.length,4)];
          nxt = min(nxt, dp[i][free_spots]);
        } else {
          if (free_spots + ed.lerror < 4) continue;
          int new_spots = min(ed.length - 1 - ed.rerror,4);
          int& nxt = dp[i+ed.length][new_spots];
          nxt = min(nxt, dp[i][free_spots]+ed.noerr);
        } 
      }
    }
  }
 /* 
  for (int i=0; i<=input.size(); ++i) {
    for(int j=0; j<5; ++j) {
      printf("%d ", dp[i][j]);
    }
    printf("\n");
  }
  
  */
  int res = INF;
  for(int j=0; j<5; ++j) {
    res = min(res, dp[input.size()][j]);
  }
  // ADD ASSERT!!!!!!
  printf("%d\n", res);

}

int main() {
  preprocess();
  scanf("%d", &ntc);
  for(int c=1; c<=ntc; ++c) {
    printf("Case #%d: ", c);
    solve();
  }  

}
