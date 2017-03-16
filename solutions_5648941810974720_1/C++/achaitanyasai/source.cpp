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

string S;

string get(){
   map<char, int> c;
   for(int n = 0; n < S.sz; ++n){
      c[S[n]]++;
   }
   string res = "";
   for(int n = 0; n < c['Z']; ++n){
      res += '0';
      c['E']--;
      c['R']--;
      c['O']--;
   }
   for(int n = 0; n < c['W']; ++n){
      res += '2';
      c['T']--;
      c['O']--;
   }
   for(int n = 0; n < c['U']; ++n){
      res += '4';
      c['F']--;
      c['O']--;
      c['R']--;
   }
   for(int n = 0; n < c['F']; ++n){
      res += '5';
      c['I']--;
      c['V']--;
      c['E']--;
   }
   for(int n = 0; n < c['O']; ++n){
      c['N']--;
      c['E']--;
      res += '1';
   }
   for(int n = 0; n < c['X']; ++n){
      c['S']--;
      c['I']--;
      res += '6';
   }
   for(int n = 0; n < c['S']; ++n){
      c['E']--;
      c['V']--;
      c['E']--;
      c['N']--;
      res += '7';
   }
   for(int n = 0; n < c['N'] / 2; ++n){
      c['I']--;
      c['E']--;
      res += '9';
   }
   for(int n = 0; n < c['G']; ++n){
      c['E']--;
      c['I']--;
      c['H']--;
      c['T']--;
      res += '8';
   }
   for(int n = 0; n < c['H']; ++n){
      c['T']--;
      c['R']--;
      c['E']--;
      c['E']--;
      res += '3';
   }
   sort(all(res));
   return res;
}

int main() {
   int T;
   cin >> T;
   for(int test = 1; test <= T; ++test){
      cin >> S;
      cout << "Case #" << test << ": " << get() << endl;
      cerr << test << endl;
   }
   return 0;
}