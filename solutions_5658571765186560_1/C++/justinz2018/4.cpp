#include <bits/stdc++.h>
using namespace std;

const string p1 = "RICHARD", p2 = "GABRIEL";

int main() {
   freopen("D-large.in", "r", stdin);
   freopen("4.out", "w", stdout);
   int t; cin >> t;
   for(int a=1; a<=t; a++) {
      int b,r,c;
      cin >> b >> r >> c;
      if(b==1) {
         cout << "Case #" << a << ": " << p2 << endl;
         continue;
      }
      if((b>=r+c-1 && !((r==1 && c==2) || (r==2 && c==1))) || r*c%b || b>max(r,c) || (b>=7 && !(r==1 || c==1))) {
         cout << "Case #" << a << ": " << p1 << endl;
         continue;
      }
      else {
         bool b3 = 0;
         for(int x=1; x<=b; x++) {
            if((x>r && ceil(b/(x+0.0))>c) ||
               (x>c && ceil(b/(x+0.0))>r)) {
                  b3=1; cout << "Case #" << a << ": " << p1 << endl;
                  break;
            }
         }
         if(b3) continue;
         if(b>=min(r,c)*2-1) {
            bool b2=1;
            for(int x=0; x<=b-min(r,c); x++) {
               bool e = 0;
               for(int y=0; y<=max(r,c); y++) {
                  if(((y*min(r,c)+x)%b)==0) {e=1; break;}
               }
               if(!e) b2=0;
            }
            if(b2) cout << "Case #" << a << ": " << p2 << endl;
            else cout << "Case #" << a << ": " << p1 << endl;
            continue;
         } else {
            cout << "Case #" << a << ": " << p2 << endl;
            continue;
         }
      }
   }
}
