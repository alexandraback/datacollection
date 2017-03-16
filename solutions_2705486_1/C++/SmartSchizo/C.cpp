#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

#define D 600000
#define L 12
#define NL 26

int W;

int start[D][L];
int end[D][L];
int next[D][L][NL];

char words[D][L];
char S[D];

map<pair< pair<int,int>, pair<int,int> >, int> DP;

int f(int cur, int st, int en, int ind, int prev) {
  int i,n,e;
  int let = S[cur]-'a';
  int ans = -1, c;
  
  if(prev > 5) prev = 5;

  pair< pair<int,int>, pair<int,int> > state = make_pair( make_pair(cur, prev), make_pair(st,ind) );
  
  if(DP[state]>0) return DP[state]-2;
  
  if(!S[cur]) {
    if(words[st][ind] == 0) return 0;
    return -1;
  }
  n = next[0][0][let];
  if(words[st][ind] == 0 && n>=0) {
    e = end[n][0];
    c = f(cur+1, n, e, 1, prev+1);
    if(c>=0) if(ans < 0 || ans > c) ans = c;
  }
  n = next[st][ind][let];
  if(n>=0) {
    e = end[n][ind];
    c = f(cur+1, n, e, ind+1, prev+1);
    if(c>=0) if(ans < 0 || ans > c) ans = c;
  }
  if( prev >= 5 ) {
    for(i=0;i<NL;i++) {
      if(i==let) continue;
      n = next[0][0][i];
      if(words[st][ind] == 0 && n>=0) {
        e = end[n][0];
        c = f(cur+1, n, e, 1, 1);
        if(c>=0) if(ans < 0 || ans > c) ans = c + 1;
      }
      n = next[st][ind][i];
      if(n>=0) {
        e = end[n][ind];
        c = f(cur+1, n, e, ind+1, 1);
        if(c>=0) if(ans < 0 || ans > c) ans = c + 1;
      }
    }
  }
  DP[state] = ans+2;
  return ans;
}

void go(int t) {
  int i,j,k;
  scanf("%s",S);
  DP.clear();
  printf("Case #%d: %d\n",t,f(0,0,W-1,0,5));
}

void buildTrie() {
  int i,j,k;
  for(i=0;i<W;i++) {
    for(j=0;j<L;j++) start[i][j] = i;
    if(i>0)
    for(j=0;j<L && words[i][j] == words[i-1][j];j++) start[i][j] = start[i-1][j];
  }

  for(i=W-1;i>=0;i--) {
    for(j=0;j<L;j++) end[i][j] = i;
    for(j=0;j<L;j++) {
      for(k=0;k<NL;k++) {
        if( words[i][j] == ('a'+k) ) next[i][j][k] = i;
        else next[i][j][k] = -1;
      }
    }
    if(i+1<W) {
      for(j=0;j<L && words[i][j] == words[i+1][j];j++) {
        end[i][j] = end[i+1][j];
        for(k=0;k<NL;k++) if(next[i][j][k] < 0) next[i][j][k] = next[i+1][j][k];
      }
      for(k=0;k<NL;k++) if(next[i][j][k] < 0) next[i][j][k] = next[i+1][j][k];
    }
  }
}

int main() {
  int t,T;
  
  FILE *fin = fopen("dict.txt","r");
  while(fscanf(fin,"%s",words[W])==1) {
    W++;
  }
  fclose(fin);
  buildTrie();

  scanf("%d",&T);
  for(t=1;t<=T;t++) go(t);
  return 0;
}
