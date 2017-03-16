#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 100030;    // Change as necessary
const ll  MODD = 1000000009; //

void do_case(int J,int P,int S,int K){
  int m = J*P*S;
  int best = 0;
  for(int i=1;i<(1 << m);i++){
    if(m == 27) if(__builtin_popcount(i) != (K > 3 ? 3 :K)*9) continue;
    if(__builtin_popcount(i) < __builtin_popcount(best)) continue;
    map<tuple<int,int,int>,int> M;
    bool okay = true;
    for(int j=0;j<m && okay;j++)
      if((i >> j) & 1){
        int x = j;
        int ss = x % S; x /= S;
        int pp = x % P; x /= P;
        int jj = x % J; x /= J;
        assert(x == 0);
        
        M[make_tuple(ss,pp,-1)]++;
        if(M[make_tuple(ss,pp,-1)] > K) okay = false;
        
        M[make_tuple(ss,-1,jj)]++;
        if(M[make_tuple(ss,-1,jj)] > K) okay = false;
        
        M[make_tuple(-1,pp,jj)]++;
        if(M[make_tuple(-1,pp,jj)] > K) okay = false;
      }
    if(okay)
      best = i;
  }
  
  cout << __builtin_popcount(best) << endl;
  for(int j=0;j<m;j++)
    if((best >> j) & 1){
      int x = j;
      int ss = x % S; x /= S;
      int pp = x % P; x /= P;
      int jj = x % J; x /= J;
      assert(x == 0);
      
      cout << jj+1 << " " << pp+1 << " " << ss+1 << "\n";
    }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  /*
  for(int J=1;J<=3;J++)
    for(int P=1;P<=3;P++)
      for(int S=1;S<=3;S++){
        for(int K=1;K<=10;K++)
          do_case(J,P,S,K);
        cout << endl;
      }
  */
  
  int T,C=1; cin >> T;
  
  while(T--){
    cout << "Case #" << C++ << ": ";
    int J,P,S,K;
    cin >> J >> P >> S >> K;
    do_case(J,P,S,K);
  }
  return 0;
}
