#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
int T;
string s;

ll zz(int x){
  int a = 1;
  for(int i = 0; i < x; i++){
    a *= 10;
  }
  return a;
}

ll sti(string x){
  ll a = 0;
  for(int i = 0; i < (int)x.size(); i++){
    a *= 10;
    a += x[i]-'0';
  }
  return a;
}

int main(void){
  cin >> T;
  for(int t = 1; t <= T; t++){
    ll ans = 0;
    
    cin >> s;
    if(s[s.size()-1] == '0'){
      for(int i = s.size()-1; i >= 0; i--){
	if(s[i] == '0'){
	  s[i] = '9';
	}else{
	  s[i]--;
	  break;
	}
      }
      if(s[0] == '0'){
	s = s.substr(1);
      }
      ans++;
    }


    for(int i = 1; i < (int)s.size(); i++){
      ans += zz(i/2) +  zz(i/2+i%2) - 1;
    }

    string bs = s.substr(0,s.size()/2);
    reverse(bs.begin(),bs.end());
    string es = s.substr(s.size()/2);

    //cout << bs << " " << es << endl;
    ll aa = sti(bs);
    if(aa  > 1) ans += aa;
    ans += sti(es);

    cout << "Case #" << t << ": " << ans << endl;
  }
}
