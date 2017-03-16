#include <vector>
#include <string>
#include <iostream>
using namespace std;

int g[4][4],h[4][4];

void init() {
  g[0][0]=0;
  g[0][1]=1;
  g[0][2]=2;
  g[0][3]=3;
  g[1][0]=1;
  g[1][1]=0;
  g[1][2]=3;
  g[1][3]=2;
  g[2][0]=2;
  g[2][1]=3;
  g[2][2]=0;
  g[2][3]=1;
  g[3][0]=3;
  g[3][1]=2;
  g[3][2]=1;
  g[3][3]=0;
  h[0][0]=0;
  h[0][1]=0;
  h[0][2]=0;
  h[0][3]=0;
  h[1][0]=0;
  h[1][1]=1;
  h[1][2]=0;
  h[1][3]=1;
  h[2][0]=0;
  h[2][1]=1;
  h[2][2]=1;
  h[2][3]=0;
  h[3][0]=0;
  h[3][1]=0;
  h[3][2]=1;
  h[3][3]=1;
}

int exp(int finalState, int power) {
  if(power==0) return 0;
  if(power%2==0) {
    int state2=exp(finalState,power/2);
    return g[state2][state2];
  }
  else {
    int state2=exp(finalState,power/2);
    return g[finalState][g[state2][state2]];
  }
}

int doit2(string s, long long X) {
  int state=0;
  int neg=0;
  int substring=0;
  int iterations=min((long long)s.size()*X,2000000ll)/s.size();
  for(int i=0;i<s.size();i++) {
    int next=(s[i]=='i')?1:(s[i]=='j')?2:3;
    int state2=g[state][next];
    int neg2=h[state][next]^neg;
    state=state2,neg=neg2;
  }
  int cycleState=state,cycleNeg=neg;
  state=0;
  neg=0;
  for(int i=0;i<s.size()*iterations;i++) {
    int j=i%s.size();
    int next=(s[j]=='i')?1:(s[j]=='j')?2:3;
    int state2=g[state][next];
    int neg2=h[state][next]^neg;
    state=state2,neg=neg2;
    if(state==1&&neg==0&&substring==0) substring=1,state=0;
    else if(state==2&&neg==0&&substring==1) substring=2,state=0;
  }
  if(substring!=2) return 0;
  state=g[state][exp(cycleState,X-iterations)];
  neg=neg^((((X-iterations)%2==0)||(cycleNeg==0))?0:1);
  if(state==3&&neg==0&&substring==2) return 1;
  return 0;
}

int main() {
  int tests;
  cin >> tests;
  init();
  for(int i = 0; i < tests; i++) {
    long long L,X;
    string s;
    cin >> L >> X >> s;
    string ret;
    if(doit2(s,X)) ret="YES"; else ret="NO";
    cout << "Case #" << (i+1) << ": " << ret << endl;
  }
  return 0;
}
