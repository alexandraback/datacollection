#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define all(a)  a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define fill(a, x) memset(a, x, sizeof(a));
#define mod 1000000007
#define _for(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

using namespace std;

string S1;
string S2;
string Min1;
string Min2;
int GMin;
int CMin;
int JMin;

int stoint(string x){
   int res = 0ll;
   for(int n = 0; n < x.sz; ++n){
      res = res * 10;
      res += (x[n] - '0');
   }
   return res;
}

void check(string x, string y){
   if(abs(stoint(x) - stoint(y)) < GMin){
      GMin = abs(stoint(x) - stoint(y));
      CMin = stoint(x);
      JMin = stoint(y);
      Min1 = x;
      Min2 = y;
   }
   else if(abs(stoint(x) - stoint(y)) == GMin){
      if(stoint(x) < CMin){
         Min1 = x;
         Min2 = y;
         CMin = stoint(x);
         JMin = stoint(y);
      }
      else if(stoint(x) == CMin){
         if(stoint(y) < JMin){
            Min1 = x;
            Min2 = y;
            CMin = stoint(x);
            JMin = stoint(y);    
         }
      }
   }
}

void recurse(string p, string q){
   if(p.sz == S1.sz){
      check(p, q);
      return;
   }
   if(S1[p.sz] == '?' && S2[p.sz] == '?'){
      for(char c = '0'; c <= '9'; ++c){
         for(char i = '0'; i <= '9'; ++i){
            string pp = p;
            string qq = q;
            pp += c;
            qq += i;
            recurse(pp, qq);
         }
      }
   }
   else if(S1[p.sz] == '?' && S2[p.sz] != '?'){
      for(char c = '0'; c <= '9'; ++c){
         string pp = p;
         string qq = q;
         pp += c;
         qq += S2[q.sz];
         recurse(pp, qq);
      }
   }
   else if(S1[p.sz] != '?' && S2[p.sz] == '?'){
      for(char c = '0'; c <= '9'; ++c){
         string pp = p;
         string qq = q;
         qq += c;
         pp += S1[q.sz];
         recurse(pp, qq);
      }
   }
   else{
      string pp = p;
      string qq = q;
      pp += S1[q.sz];
      qq += S2[q.sz];
      recurse(pp, qq);
   }
}

void get(){
   Min1 = "";
   Min2 = "";
   GMin = 1e9;
   CMin = 1e9;
   JMin = 1e9;
   recurse("", "");
   cout << Min1 << " " << Min2 << endl;
}

int main() {
   int T;
   cin >> T;
   for(int test = 1; test <= T; ++test){
      cin >> S1 >> S2;
      cout << "Case #" << test << ": ";
      get();
      cerr << test << endl;
   }
   return 0;
}