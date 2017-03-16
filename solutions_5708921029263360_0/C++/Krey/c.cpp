#include<bits/stdc++.h>
#define ft first
#define sd second
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 1100000;

struct outfit{
  int j,p,s;
  outfit(int j, int p, int s) : j(j), p(p), s(s) {}
};

bool ok(vector<outfit>& q, int maska, int k){
  for(int i = 0; i < q.size(); i++){
    if(maska & (1<<i)){
      pair<int,int> jp = {q[i].j, q[i].p};
      int o = 1;
      for(int ii = i + 1; ii < q.size(); ii++){
	if(maska & (1<<ii) and q[ii].j == jp.ft and q[ii].p == jp.sd) o++;
      }
      if(o > k) return 0;
      
      pair<int,int> js = {q[i].j, q[i].s};
      o = 1;
      for(int ii = i + 1; ii < q.size(); ii++){
	if(maska & (1<<ii) and q[ii].j == js.ft and q[ii].s == js.sd) o++;
      }
      if(o > k) return 0;
      
      pair<int,int> ps = {q[i].p, q[i].s};
      o = 1;
      for(int ii = i + 1; ii < q.size(); ii++){
	if(maska & (1<<ii) and q[ii].p == ps.ft and q[ii].s == ps.sd) o++;
      }
      if(o > k) return 0;
    }
  }
  return 1;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  for(int tt = 1; tt <= t; tt++){
    int J, P, S, K;
    cin >> J >> P >> S >> K;
    vector<outfit> q;
    for(int jj = 0; jj < J; jj++) for(int pp = 0; pp < P; pp++) for(int ss = 0; ss < S; ss++){
      q.pb({jj, pp, ss});
    }
    int wyn = 0;
    int bestmaska;
    int n = q.size();
    for(int maska = 1; maska < (1<<n); maska++){
      int l = __builtin_popcount(maska);
      if(l <= wyn) continue;
      if(ok(q, maska, K)){
	bestmaska = maska;
	wyn = l;
      }
    }
    cout<<"Case #"<<tt<<": "<<wyn<<"\n";
    for(int i = 0; i < n; i++) if(bestmaska & (1<<i)){
      cout << q[i].j + 1 << " " << q[i].p + 1 << " " << q[i].s + 1 << "\n";
    }
  } 
}