#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define FOR(i,b,n) for(int i = b; i < n; i++)
#define REP(i, n) FOR(i,0,n)

using namespace std;

typedef long long ll;

struct Box {
  ll cnt;
  int type;
};

struct Data {
  int ca, cb;
  ll sum;
  vector<Box> A, B;
};


int T, N, M;
vector<Box> A, B;

ll solve(){
  queue<Data> Q;
  ll ans = 0l;

  Data d;
  d.ca = 0;
  d.cb = 0;
  d.sum = 0;
  d.A = A;
  d.B = B;

  Q.push(d);

  while(!Q.empty()){
    d = Q.front(); Q.pop();

    if(d.ca == N || d.cb == M){
      //cout << "sum = " << d.sum << endl;
      ans = max(ans, d.sum);
      
      continue;
    }
    //cout << "D, sum = " << d.sum << ", ca = " << d.ca << ", cb = " << d.cb << ", A[current]. cnt = " << A[d.ca].cnt << ", type = " << A[d.ca].type << ", B[]. cnt = " << B[d.cb].cnt << ", type = " << B[d.cb].type << endl;
    
    if(A[d.ca].type == B[d.cb].type){
      ll cnt = min(d.A[d.ca].cnt, d.B[d.cb].cnt);
      Data c;
      c.sum = d.sum + cnt;
      c.ca = d.ca;
      c.cb = d.cb;
      c.A = d.A;
      c.B = d.B;
      c.A[d.ca].cnt -= cnt;
      c.B[d.cb].cnt -= cnt;
      if(!c.A[d.ca].cnt){ //cnt == A[d.ca].cnt){
	c.ca++;
      }else{// if (!c.B[d.cb].cnt){
	c.cb++;
      }
      //cout << "check a: " << d.A[d.ca].cnt << ":" << c.A[d.ca].cnt << ",  b: " << d.B[d.cb].cnt << ":" << c.B[d.cb].cnt << endl;

      //cout << "sum = " << c.sum << ", ca = " << c.ca << ", cb = " << c.cb << endl;
      Q.push(c);
    }else{
      Data na, nb;
      na.sum = nb.sum = d.sum;
      na.ca = d.ca + 1;
      na.cb = d.cb;
      nb.ca = d.ca;
      nb.cb = d.cb + 1;
      na.A = nb.A = d.A;
      na.B = nb.B = d.B;
      Q.push(na);
      Q.push(nb);
    }

  }
  return ans;
}

int main(){
  while(cin >> T && T){
    REP(cases, T){
      ll ans = 0;

      A.clear();
      B.clear();
      cin >> N >> M;
      REP(i, N){
	Box t;
	cin >> t.cnt >> t.type;
	A.push_back(t);
      }
      //REP(i, N) cout << A[i].cnt << ", " << A[i].type << endl;

      
      REP(i, M){
	Box t;
	cin >> t.cnt >> t.type;
	B.push_back(t);
      }
      //cout << "B" << endl; REP(i, M) cout << B[i].cnt << ", " << B[i].type << endl;

      ans = solve();

      printf("Case #%d: %lld\n", cases + 1, ans);
    }
  }
  
  return 0;
}
