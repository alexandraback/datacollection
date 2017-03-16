//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<cstring>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
#include<ext/hash_set>
using namespace __gnu_cxx;
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

hash_set<string> dict;
string str;

const int SIZE = 5000;
int table[10][SIZE];
int get(int i, int last){
  
  last = min(last, 5);
  if (i >= s(str))
    return 0;
  if(table[last][i] != -1)
    return table[last][i];
  
  string w = "";
  int best = 1e9;
  for(int j = i ; j < s(str) ; j++){
    if(j-i >= 10)break;
    w += str[j];
    
    //no change
    if(dict.find(w) != dict.end()){
      int current = get(j+1, last+s(w));
      best = min(best, current);
    }
    for(int x = 0 ; x < s(w) ; x++){
      //first change
      if(last+x >= 5){
        for(int k = 0 ; k < 26 ; k++){
          char t = w[x];
          w[x] = 'a'+k;
          
          if(w == "jam"){
            int m = 0;
            m++;
          }
          
          if(dict.find(w) != dict.end()){
            int current = 1+get(j+1, s(w)-x);
            best = min(best, current);
          }
          
          //second change
          for(int y = x+5 ; y < s(w) ; y++){
            for(int kk = 0 ; kk < 26 ; kk++){
              char tt = w[y];
              w[y] = 'a'+kk;
              if(dict.find(w) != dict.end()){
                int current = 2+get(j+1, s(w)-y);
                best = min(best, current);
              }
              w[y] = tt;
            }
          }
          w[x] = t;
        }
      }
    }
  }
  
  return table[last][i] = best;
}

int main(){

//  freopen("/Users/hamza/1.in", "wt", stdout);
//  string s = "cxdejax", base = "cxdejax";
//  while(s(s)+7 <= 4000)
//    s += base;
//  cout << 1 << endl << s << endl;
//  return 0;
  
  freopen("/Users/hamza/Downloads/garbled_email_dictionary.txt", "rt", stdin);
  for(int i = 0 ; i < 521196 ; i++){
    string w; cin >> w;
    dict.insert(w);
  }
  
//  cout << (dict.find("code") != dict.end()) << endl;
//  cout << (dict.find("jam") != dict.end()) << endl;
//  
//  freopen("/Users/hamza/1.in", "rt", stdin);
  freopen("/Users/hamza/Downloads/C-large.in", "rt", stdin);
  freopen("/Users/hamza/Downloads/C-large.out", "wt", stdout);
  
	int TT; cin >> TT;
	for(int t = 1 ; t <= TT ; t++){
    
    cin >> str;
    memset(table, -1, sizeof table);
    int r = get(0, 5);
    cout << "Case #" << t << ": " << r << endl;
	}

	return 0;
}
