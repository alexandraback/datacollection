#include <bits/stdc++.h>

using namespace std;

#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rep(a,b) fr(a,0,b)
#define fst first
#define snd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
 
const int oo = 0x3f3f3f3f;
 
typedef long long ll;
typedef pair<int,int> pii;

const int EQUAL = 0;
const int GREATER = 1;
const int LESSER = 2;

int N;
string ans_coders, ans_jammers;
ll best;

ll pot[19];

void prec() {
  pot[0] = 1;
  for (int i = 1; i < 18; ++i) pot[i] = pot[i-1] * 10;
}

ll diff_pos(int dig1, int dig2, int pos) {
  return pot[N - pos - 1] * dig1 - pot[N - pos - 1] * dig2;
}

void go(int pos, int status, string& coders, string& jammers, ll diff) {
  string coders_ = coders;
  string jammers_ = jammers;
  
  fprintf(stderr, "start %d %d %s %s\n", pos, status, coders.c_str(), jammers.c_str());
  
  auto rec = [&] (int new_status) {
    fprintf(stderr, "go %d %d %s %s\n", pos, status, coders_.c_str(), jammers_.c_str());
    
    go(pos + 1, new_status, coders, jammers,
        diff + diff_pos(coders[pos] - '0', jammers[pos] - '0', pos));
    
    fprintf(stderr, "back %d %d %s %s\n", pos, status, coders_.c_str(), jammers_.c_str());
  };
  
  if (pos == N) {
    auto update = [&] {
      ans_coders = coders;
      ans_jammers = jammers;
      best = llabs(diff);
    };
    
    fprintf(stderr, "end %lld %s %s\n", diff, coders.c_str(), jammers.c_str());
    
    if (best == -1 || llabs(diff) < best) {
      update();
    } else if (llabs(diff) == best && make_pair(coders, jammers) < make_pair(ans_jammers, ans_jammers)) {
      update();
    }
    
    return;
  }
  
  if (coders[pos] != '?' && jammers[pos] != '?') {
    int new_status = status;
    if (status == EQUAL) new_status = (coders[pos] < jammers[pos] ? LESSER : GREATER);
    rec(new_status);
    
    return;
  }
  
  if (coders[pos] == '?' && jammers[pos] == '?') {
    if (status == EQUAL) {
      coders[pos] = jammers[pos] = '0';
      rec(EQUAL);
      
      coders[pos] = '0'; jammers[pos] = '1';
      rec(LESSER);
      
      coders[pos] = '1'; jammers[pos] = '0';
      rec(GREATER);
      
      coders[pos] = jammers[pos] = '?';
      
      return;
    }
  }
  
  char savec = coders[pos], savej = jammers[pos];
  if (coders[pos] == '?') {
    if (status == LESSER) coders[pos] = '9';
    else if (status == GREATER) coders[pos] = '0';
    else {
      if (jammers[pos] != '9') {
        coders[pos] = jammers[pos] + 1;
        rec(GREATER);
      }
      if (jammers[pos] != '0') {
        coders[pos] = jammers[pos] - 1;
        rec(LESSER);
      }
      
      coders[pos] = jammers[pos];
      rec(EQUAL);
      return;
    }
  }
  
  if (jammers[pos] == '?') {
    if (status == GREATER) jammers[pos] = '9';
    else if (status == LESSER) jammers[pos] = '0';
    else {
      if (coders[pos] != '9') {
        jammers[pos] = coders[pos] + 1;
        rec(LESSER);
      }
      if (coders[pos] != '0') {
        jammers[pos] = coders[pos] - 1;
        rec(GREATER);
      }
      
      jammers[pos] = coders[pos];
      rec(EQUAL);
      
      jammers[pos] = savej;
      return;
    }
  }
  
  go(pos + 1, status, coders, jammers,
      diff + diff_pos(coders[pos] - '0', jammers[pos] - '0', pos)); 
   
   coders[pos] = savec;
   jammers[pos] = savej;
}

int main() {
  prec();
  
  int T;
  cin >> T;
  fr(caso,1,T+1) {
    
    string coders, jammers;
    cin >> coders >> jammers;
    
    N = coders.size();
    best = -1;
    go(0,EQUAL,coders,jammers,0);
    printf("Case #%d: ", caso);
    cout << ans_coders << " " << ans_jammers << endl;
  }
  
  return 0;
}