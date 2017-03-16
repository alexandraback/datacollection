#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

pair<int,char> prod(const pair<int,char>& a, const pair<int,char>& b){
  pair<int,char> ret;
  ret.first = a.first * b.first;
  char s = a.second;
  char t = b.second;

  if(s=='1' && t=='1'){ ret.first *= 1; ret.second = '1'; }
  if(s=='1' && t=='i'){ ret.first *= 1; ret.second = 'i'; }
  if(s=='1' && t=='j'){ ret.first *= 1; ret.second = 'j'; }
  if(s=='1' && t=='k'){ ret.first *= 1; ret.second = 'k'; }

  if(s=='i' && t=='1'){ ret.first *= 1; ret.second = 'i'; }
  if(s=='i' && t=='i'){ ret.first *= -1; ret.second = '1'; }
  if(s=='i' && t=='j'){ ret.first *= 1; ret.second = 'k'; }
  if(s=='i' && t=='k'){ ret.first *= -1; ret.second = 'j'; }

  if(s=='j' && t=='1'){ ret.first *= 1; ret.second = 'j'; }
  if(s=='j' && t=='i'){ ret.first *= -1; ret.second = 'k'; }
  if(s=='j' && t=='j'){ ret.first *= -1; ret.second = '1'; }
  if(s=='j' && t=='k'){ ret.first *= 1; ret.second = 'i'; }

  if(s=='k' && t=='1'){ ret.first *= 1; ret.second = 'k'; }
  if(s=='k' && t=='i'){ ret.first *= 1; ret.second = 'j'; }
  if(s=='k' && t=='j'){ ret.first *= -1; ret.second = 'i'; }
  if(s=='k' && t=='k'){ ret.first *= -1; ret.second = '1'; }

  return ret;
}

map<string,char> memo;


string solve(const string& str, int X){
  string text = "";
  rep(i,X) text += str;
  if(text.length()<3) return "NO";
  if(text == "ijk") return "YES";

  pair<int,char> seg, tmp;
  seg.first = 1; seg.second = '1';
  rep(i,text.length()){
    tmp.first = 1; tmp.second = text[i];
    seg = prod(seg, tmp);    
  }
  if(!(seg.first == -1 && seg.second == '1')) return "NO";
  
  pair<int,char> seg1;
  seg1.first = 1; seg1.second = '1';
  rep(i,text.length()){
    tmp.first = 1; tmp.second = text[i];
    seg1 = prod(seg1, tmp);

    if(!(seg1.first==1 && seg1.second=='i')) continue;
    
    pair<int,char> seg3;
    seg3.first = 1; seg3.second = '1';
    for(int k=text.length()-1; k>i+1; k--){
      tmp.first = 1; tmp.second = text[k];
      seg3 = prod(tmp, seg3);
      
      if(!(seg3.first==1 && seg3.second=='k')) continue;
    
      pair<int,char> seg2;
      seg2.first = 1; seg2.second = '1';
      string seg_str = "";
      REP(j,i+1,k){
        tmp.first = 1; tmp.second = text[j];
        seg2 = prod(seg2, tmp);
        seg_str += text[j];
      }
      
      if((seg2.first==1 && seg2.second=='j')){
        return "YES";
      }
    }
  }

  return "NO";
}

int main(){
  int T;

  cin >> T;
  rep(t,T){
    int L, X;
    string str;
    cin >> L >> X;
    cin >> str;
    
    cout << "Case #" << t+1 << ": " << solve(str, X) << endl;
  }
  
  return 0;
}
