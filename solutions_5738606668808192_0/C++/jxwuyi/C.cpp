#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<numeric>
#include<deque>
using namespace std;
#define LL long long
#define ULL unsigned long long

const int MAX = 1000000;
const int M = 1000;
vector<int> prime;
bool isprime[MAX];

void solve(int L, int K, vector<ULL> &key, vector<vector<ULL> > &proof) {
  printf("Start Solve [ L=%d, K=%d ] ... \n", L, K);
  int t = clock();
  set<ULL> hash;
  key.resize(K);
  proof.resize(K);
  for(int k=0;k<K;++k){
    proof[k].resize(9);
    vector<ULL > &T = proof[k];
    ULL &cur = key[k];
    while(true) {
      cur = 0;
      for(int i=0;i<L;++i){
        cur <<= 1;
        if(i==0||i==L-1||(rand()&1))cur|=1;
      }
      if(hash.count(cur)) continue;
      
      bool ok=true;
      for(int p = 2; p <= 10 && ok; ++p) {
        ULL & now = T[p - 2];
        now = 0;
        for(int i=0;i<prime.size() && !now;++i) {
          ULL rem = 0;
          int pr = prime[i];
          for(int j = 0; j < L; ++ j) {
            rem = (rem * p + !!(cur & 1ull << j)) % pr;
          }
          if(rem == 0) {
            now = pr;
            break;
          }
        }
        if(now == 0) ok=false;
      }
      if(ok) {
        break;
      }
    }
    
    hash.insert(cur);
    int det = clock()-t;
    printf("  >>> %d / %d finished! Time Elapsed = %d.%03ds\n", k+1,K,det/1000,det%1000);
  }
}

int main() {
  srand(3137);
  fill(isprime+2,isprime+MAX,true);
  for(int i=4;i<MAX;i+=2)isprime[i]=false;
  for(int i=3;i<MAX && prime.size() < M;++i){
    if(isprime[i]){
      prime.push_back(i);
      for(int j=i+i;j<MAX;j+=i)
        isprime[j]=false;
    }
  }
  
  vector<ULL> key;
  vector<vector<ULL> > proof;
  
  //int L = 6, K = 3;
  int L = 16, K = 50;
  //int L = 32, K = 500;
  solve(L, K, key, proof);
  
  ofstream fout("text.txt");
  fout << "Case #1:"<<endl;
  for(int i=0;i<K;++i){
    ULL now = key[i];
    for(int j=0;j<L;++j)
      if((now & 1ull << j)) fout << '1';
      else fout << '0';
    for(int j=2;j<=10;++j)
      fout <<" " << proof[i][j - 2] ;
    fout << endl;
  }
}

