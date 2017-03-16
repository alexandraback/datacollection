#include<iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <cmath>
#include <list>
#include <sstream>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;
typedef long long LL;
typedef vector<int> VI;
typedef pair<LL,LL> PLL;
typedef vector<pair<int,int> > VPII;
typedef vector<LL> VLL;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef long double LD;
typedef vector<char> VC;

#define PI 3.14159265358979323
#define EE 2.71828182845
#define EPS 10e-10
#define INF 10000000

inline LL MAX(LL a, LL b){ return a < b ? b : a;}
inline LL MIN(LL a, LL b){ return a < b ? a : b;}

#define FOR(i,n)      for(int i=0;i<(n);i++)
#define FORD(i,n)     for(int i=(n)-1;i>=0;i--)

#define MP make_pair
#define PB push_back

#define MOD 1000000007


bool kontrola(string S[], int N){

  char zacina[N], konci[N]; vector<char> vnutri[N];
  FOR(i, N) vnutri[i].resize(0);

  FOR(i, N){
    //v kazdom stringu kazde pismenko suvislo
    zacina[i] = S[i][0];
    konci[i] = S[i][S[i].length() - 1];
    int bolo[26];
    memset(bolo, 0, sizeof(bolo));
    int M  = S[i].length();
    FOR(j, M){
      if (j > 0 && S[i][j] != S[i][j-1] && bolo[S[i][j] - 'a'] == 1) return false;
      if (bolo[S[i][j]-'a'] == 0 && zacina[i] != S[i][j] && konci[i] != S[i][j]) vnutri[i].PB(S[i][j]);
      bolo[S[i][j] - 'a'] = 1;
    }
  }

  //ak pismenko v dvoch roznych stringoch, potom nesmie byt vnutri
  for(char c = 'a'; c <= 'z'; c++){
    FOR(i, N) FOR(j, N) if (i != j){
      bool vnutri1 = false, vnutri2 = false;
      FOR(k, vnutri[i].size()) if (vnutri[i][k] == c) vnutri1 = true;
      FOR(k, vnutri[j].size()) if (vnutri[j][k] == c) vnutri2 = true;
      if (vnutri1 && vnutri2) return false;
      if (vnutri1 && (zacina[j] == c || konci[j] == c)) return false;
      if (vnutri2 && (zacina[i] == c || konci[i] == c)) return false;
    }
  }

  FOR(i, N) FOR(j, N) if (i != j){
    if (S[i][0] == S[i][S[i].length() - 1]) continue;
    if (S[j][0] == S[j][S[j].length() - 1]) continue;
    if (S[i][0] == S[j][0]) return false;
    if (S[i][S[i].length() - 1] == S[j][S[j].length() - 1]) return false;
  }
  return true;

}

LL fakmod(int n){
  LL ans = 1;
  FOR(i, n + 1) if (i){
    ans *= i;
    ans %= MOD;
  }
  return ans;
}

//vsetky stringy, ktore zacinaju a koncia rovnakym pismenkom mergne
pair<LL, int> preprocess(string S[], int N){
  int sz = N;
  LL fak = 1;
  for(char c = 'a'; c <= 'z'; c++){
    int poc = 0;
    FOR(i, sz) if (S[i][0] == c && S[i][S[i].length() - 1] == c) poc++;
    if (poc > 1){
      fak *= fakmod(poc);
      fak %= MOD;
      set<string> SS;
      int bol = 0;
      FOR(i, sz){
        if (S[i][0] != c || S[i][S[i].length() -1] != c) SS.insert(S[i]);
        else{
          if (bol == 0){
            SS.insert(S[i]);
            bol = 1;
          }
        }
      }
      int i = 0;
      for(set<string>::iterator it = SS.begin(); it != SS.end(); it++, i++) S[i] = *it;
      sz = i;
    }  
  }
  return MP(fak, sz);
}

string merge(string s1, string s2){
  if (s1[0] == s2[s2.length() - 1]) return s2 + s1;
  return s1 + s2;
}

LL compute(string S[], int N){
//  FOR(i, N) cout << S[i] << " ";
//  cout << endl;

  //ak rovnake pismeno, zapiseme najpr pred a po, ak sa da
  /*
  int targetf = N;
  for(char c = 'a'; c <= 'z'; c++){
    int index = -1;
    FOR(i, N) if (S[i][0] == c && S[i][S[i].length()-1] == c) index = i;
    if (index == -1) continue;
    FOR(i, N) if (i != index && (S[i][0] == c || S[i][S[i].length() - 1] == c)){
      targetf--;
      break;
    }

  }*/

  if (!kontrola(S, N)) return 0;

  for(char c = 'a'; c <= 'z'; c++){
    int index = -1;
    FOR(i, N) if (S[i][0] == c && S[i][S[i].length()-1] == c) index = i;
    if (index == -1) continue;
    FOR(i, N) if (i != index && (S[i][0] == c || S[i][S[i].length() - 1] == c)){
      S[i] = merge(S[i], S[index]);
      S[index] = S[N - 1];
      return compute(S, N - 1);
    }
  }

 // cout << "targetf: " << targetf << endl;

  //vieme napojit i na j?
  FOR(i, N){
    FOR(j, N)if (i < j){
      if (S[i][0] == S[i][S[i].length()-1]) continue;
      if (S[j][0] == S[j][S[j].length()-1]) continue;
      if (S[i][0] == S[j][S[j].length() - 1]){
        S[i] = merge(S[i], S[j]);
        S[j] = S[N - 1];
        return compute(S, N - 1);
      }
      if (S[j][0] == S[i][S[i].length() - 1]){
        S[i] = merge(S[i], S[j]);
        S[j] = S[N - 1];
        return compute(S, N - 1);
      }
    }
  }

  return fakmod(N);
  
}

void solve(int tc){
  int N;
  cin >> N;
  string S[105];
  FOR(i, N) cin >> S[i];
  cout << "Case #" << tc << ": ";
  if (!kontrola(S, N)) cout << "0" << endl;
  else{
    pair<LL, int> p = preprocess(S, N);
  //  cout << "preprocess: " << p.first << ", " << p.second << endl;

    LL ans = p.first * compute(S, p.second);
    cout << ans % MOD << endl;
  }
}

int main(){
  int TT;
  cin >> TT;
  FOR(tt, TT) solve(tt + 1);
  return 0;
}
