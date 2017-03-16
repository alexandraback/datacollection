/*
ID: nongeek1
PROG: my
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;

ifstream fin("my.in");
ofstream fout("my.out");

ifstream din("dictionary.txt");

const int DLEN = 521196;

int maxlen=0;
string d[DLEN];
int n;
inline void output(long long ret){
  static int t=0;
  fout << "Case #"<< ++t <<": " << ret << endl;
}
inline int max(int x, int y){
  return x>y?x:y;
}
struct node{
  int l,nl;
  int num;
  string s;
  node(){}
  node(int ll, int nnll, int nn,const string &ss):l(ll),nl(nnll),num(nn),s(ss){}
};
vector<node> rec[5000][5000];
string s;
int f[5][5000];

void compare(const string &key, int begin){
  int last = -5;
  int l=-1,nextl,num=0;
  for(int i=0; i<key.size(); i++)
    if(s[begin+i]!=key[i]){
      if(i-last<5) return;
      last = i;
      num++;
      if(l<0) l = i;
    }
  if(l<0) l = 5;
  nextl = max(0, 5-(key.size() - last));
  node x(l, nextl, num, key);
  rec[begin][begin+key.size()-1].push_back(x);
}

int cal(int t, int k){
  if(k==n) return 0;
  if(f[t][k]!=INT_MAX) return f[t][k];
  for(int j=k; j<n&&j<k+maxlen; j++)
    for(const node & x: rec[k][j]){
      if(x.l>=t){
	int temp = cal(x.nl, j+1);
	if(temp == -1) continue;
	f[t][k] = min(f[t][k], temp+x.num);
      }
    }
  if(f[t][k]==INT_MAX) f[t][k]=-1;
  return f[t][k];
}
void solve(){
  fin >> s;
  n=s.size();
  for(int i=0; i<n; i++)
    for(int j=i; j<n&&j<i+maxlen; j++){
      rec[i][j].clear();
    }
  for(int k=0; k<DLEN; k++)
    for(int i=0; i+d[k].size()-1<n; i++){
      compare(d[k],i);
    }
  for(int t=0; t<5; t++)
    for(int i=0; i<n; i++)
      f[t][i] = INT_MAX;
  output(cal(0,0));
}
int main(){
  int caseN;
  for(int i=0; i<DLEN; i++){
    din >> d[i];
    maxlen = max(maxlen, d[i].size());
  }
  fin >> caseN;
  while(caseN--){
    solve();
  }
  return 0;
}
