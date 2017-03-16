#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mult[4][4] = {{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};

int div2(int i, int j) {
   int b=1;
   if(i<0 && j<0);
   else if(i<0 || j<0) b=-1;
   i=abs(i); j=abs(j);
   if(i==1 && j==1) return b*1;
   if(i==1 && j==2) return -2*b;
   if(i==2 && j==1) return b*2;
   if(i==1 && j==3) return -3*b;
   if(i==3 && j==1) return b*3;
   if(i==1 && j==4) return -4*b;
   if(i==4 && j==1) return b*4;
   if(i==2 && j==2) return b*1;
   if(i==2 && j==3) return 4*b;
   if(i==3 && j==2) return b*-4;
   if(i==2 && j==4) return -3*b;
   if(i==4 && j==2) return 3*b;
   if(i==3 && j==4) return 2*b;
   if(i==4 && j==3) return b*-2;
   if(i==3 && j==3) return b*1;
   if(i==4 && j==4) return b*1;
   return 0;
}
int main() {
   ios_base::sync_with_stdio(0);
   freopen("C-small-attempt2.in", "r", stdin);
   freopen("3.out", "w", stdout);
   int t;
   cin >> t;
   for(int a=1; a<=t; a++) {
      int b,l; string s1="",s="";
      cin >> l >> b >> s1;
      for(int x=0; x<b; x++)
         s += s1;
      int arr[s.length()+10];
      int c = 1;
      for(int x=0; x<s.length(); x++) {
         bool b=0;
         if(c<0) b=1;
         c=abs(c);
         switch(s[x]) {
            case 'i': c=mult[c-1][1]; break;
            case 'j': c=mult[c-1][2]; break;
            case 'k': c=mult[c-1][3]; break;
         }
         if(b) c=-1*c;
         arr[x]=c;
      }
      vector<int> v,v2;
      for(int x=0; x<s.length(); x++) {
         if(div2(arr[s.length()-1], arr[x])==4) v.push_back(x);
         else if(x<s.length()-2 && arr[x]==2) v2.push_back(x);
      }
      cout << "Case #" << a << ": ";
      bool e=0;
      for(int x=0; x<v2.size(); x++) {
         for(int y=v.size()-1; y>=0; y--) {
            if(v[y]<=v2[x]) break;
            if(div2(arr[v[y]],arr[v2[x]])==3) {
               cout << "YES" << endl;
		         e=1; break;
	         }
         }
	      if(e) break;
      }
      if(!e) cout << "NO" << endl;
   }
}
