#include <bits/stdc++.h>

using namespace std;

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1000000000;
const int MOD = INF + 7;
const int MAXN = 100010;

struct qa {
   char c;
   int s;
   qa(){}
   qa(char _c,int _s) {
      c = _c;
      s = _s;
   }
};

qa multiply(qa a, qa b){
   qa r;
   r.s = (a.s != b.s) ? -1 : 1;
   if(a.c == '1'){
      r.c = b.c;
   } else if(b.c == '1'){
      r.c = a.c;
   } else if(a.c == b.c){//ii jj kk
      r.s = (r.s == 1) ? -1 : 1;
      r.c = '1';
   } else {
      if(a.c == 'i' && b.c == 'j'){
         r.c = 'k';
      } else if(a.c == 'i' && b.c == 'k'){
         r.s = (r.s == 1) ? -1 : 1;
         r.c = 'j';
      } else if(a.c == 'j' && b.c == 'i'){
         r.s = (r.s == 1) ? -1 : 1;
         r.c = 'k';
      } else if(a.c == 'j' && b.c == 'k'){
         r.c = 'i';
      } else if(a.c == 'k' && b.c == 'i'){
         r.c = 'j';
      } else if(a.c == 'k' && b.c == 'j'){
         r.s = (r.s == 1) ? -1 : 1;
         r.c = 'i';
      }
   }
   return r;
}

qa v[MAXN];

int main(){
#ifndef ONLINE_JUDGE
   freopen("C-small-attempt1.in","r",stdin);
   freopen("C-small-attempt1.out","w",stdout);
   // freopen("in","r",stdin);
#endif
   int casos, n, x;
   string s,ss;
   bool first, sw, hasi;
   qa a,b;
   cin >> casos;
   for(int caso = 1 ; caso <= casos ; caso++){
      cin >> n >> x >> ss;
      s = "";
      for(int i = 0 ; i < x ; i++){
         s += ss;
      }
      n = s.size();
      first = true;
      for(int i = n-1 ; i >= 0 ; i--){
         a = qa(s[i],1);
         if( first ){
            b = a;
            first = false;
         } else {
            b = multiply(a,b);
         }
         v[i] = b;
      }
      first = true;
      hasi = false;
      sw = false;
      for(int i = 0 ; i < n ; i++){
         b = qa(s[i],1);
         if(first){
            a = b;
            first = false;
         } else {
            a = multiply(a,b);
         }
         if(a.c == 'i' && a.s == 1){
            hasi = true;
         }
         if(a.c == 'k' && a.s == 1 && hasi && i < n-1 && v[i+1].c == 'k' && v[i+1].s == 1){
            sw = true;
         }
      }
      cout << "Case #"<< caso <<": " << (sw ? "YES" : "NO") << endl;
   }
   return 0;
}