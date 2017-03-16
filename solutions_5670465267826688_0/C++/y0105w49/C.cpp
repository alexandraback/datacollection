#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define MAXN 1200
#define INF 200000

typedef long long ll;

int T;
ll L,X;
string s;

// ints are 1,i,j,k,-1,-i,-j,-k

ll minq(ll a, ll b) {
  if (a<b) return a;
  return b;
}

int mult(int a, int b) {
  if (a>=4) return (4+mult(a-4,b))%8;
  if (b>=4) return (4+mult(a,b-4))%8;
  if (a==0) return b;
  if (b==0) return a;
  if (a==b) return 4;
  if ((a+1 - b + 3)%3 == 0) return (b%3)+1;
  if ((b+1 - a + 3)%3 == 0) return 4+(a%3)+1;
  assert(0);
  return 0;
}
int powq(int a, ll e) {
  if (e%4==0) return 0;
  return mult(a,powq(a,e-1));
}

string things[8]={"1","i","j","k","-1","-i","-j","-k"};

bool go() {
  int prod=0;
  REP(i,L) prod=mult(prod,s[i]-'i'+1);
  prod=powq(prod,X);
  if (prod!=4) return false;

  prod=0;
  ll ctr=0;
  while (ctr<minq(15,X)*L) {
    prod=mult(prod,s[ctr++%L]-'i'+1);
    if (prod==1) break;
  }
  while (ctr<minq(15,X)*L) {
    prod=mult(prod,s[ctr++%L]-'i'+1);
    if (prod==3) break;
  }
  return ctr<minq(15,X)*L;
}

int main() {
  cin >> T;
  REP(zz,T) {
    cin >> L >> X;
    cin >> s;
    cout << "Case #" << (zz+1) << ": " << (go()?"YES":"NO") << endl;
  }
}
