#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

FILE *in = fopen("B.in", "r");
FILE *out = fopen("B.out", "w");
FILE *dict = fopen("dict.txt", "r");

#define INF 444444

int trie[1200000][26], ntrie;
bool flag[1200000];

char strNode[1111];
int NN;
int getNode(){
  int cur = 0;
  for(int q = 0; q < NN; q++){
    int l = strNode[q] - 'a';
    if(trie[cur][l] == -1) return -1;
    cur = trie[cur][l];
  }
  return cur;
}

char inp[4444];
int n;
int dp[4444][10];

int main(){
  ntrie = 1;
  memset(flag, 0, sizeof flag);
  memset(trie, -1, sizeof trie);
  
  while(fscanf(dict, "%s", inp) != EOF){
    int cur = 0, e = strlen(inp);
    
    for(int q = 0; q < e; q++){
      int l = inp[q] - 'a';
      if(trie[cur][l] == -1){
        trie[cur][l] = ntrie ++;
      }
      cur = trie[cur][l];
    }
    flag[cur] = 1;
  }
  
  int ntest;
  fscanf(in, "%d\n", &ntest);
  for(int test = 1; test <= ntest; test++){
    fscanf(in, "%s", inp);
    n = strlen(inp);
    for(int q = 0; q <= 5; q++){
      dp[n][q] = 0;
    }
    for(int q = n - 1; q >= 0; q--){
      for(int last = 0; last <= 5; last++){
        int &ret = dp[q][last];
        ret = INF;
        /// No Changes
        for(int e = q; e < n && e - q <= 10; e++){
          NN = 0;
          for(int i = q; i <= e; i++){
            strNode[NN ++] = inp[i];
          }
          int node = getNode();
          if(node != -1 && flag[node]){
            int newlast = last + e - q + 1;
            if(newlast > 5) newlast = 5;
            ret = min(ret, dp[e + 1][newlast]);
          }
        }
        /// 1 Change
        for(int e = 0; e < n && e - q <= 10; e++){
          for(int changei = q + (5 - last); changei <= e; changei++){
            for(int newchar = 'a'; newchar <= 'z'; newchar++){
              NN = 0;
              for(int i = q; i <= e; i++){
                if(i == changei) strNode[NN ++] = newchar;
                else strNode[NN ++] = inp[i];
              }
              int node = getNode();
              if(node != -1 && flag[node]){
                int newlast = e - changei + 1;
                if(newlast > 5) newlast = 5;
                ret = min(ret, 1 + dp[e + 1][newlast]);
              }
            }
          }
        }
        /// 2 Changes
        for(int e = 0; e < n && e - q <= 10; e++){
          for(int changei = q + (5 - last); changei <= e; changei++){
            for(int newchar = 'a'; newchar <= 'z'; newchar++){
              for(int changeb = changei + 5; changeb <= e; changeb++){
                for(int newcharb = 'a'; newcharb <= 'z'; newcharb++){
                  NN = 0;
                  for(int i = q; i <= e; i++){
                    if(i == changei) strNode[NN ++] = newchar;
                    else if(i == changeb) strNode[NN ++] = newcharb;
                    else strNode[NN ++] = inp[i];
                  }
                  int node = getNode();
                  if(node != -1 && flag[node]){
                    int newlast = e - changeb + 1;
                    if(newlast > 5) newlast = 5;
                    ret = min(ret, 2 + dp[e + 1][newlast]);
                  }
                }
              }
            }
          }
        }
      }
    }
    
    fprintf(out, "Case #%d: %d\n", test, dp[0][5]);
  }
  
  return 0;
}
