#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

typedef long long Int;

Int tonum(string str){
  Int res = 0;
  for(int i = 0;i < str.size();i++){
    res *= 10;
    res += (int)(str[i] - '0');
  }
  return res;
}

string rans1, rans2;
Int nowmin;

void _solve(char *str1, char *str2, Int n){

  char ans1[108], ans2[108];
  ans1[n] = ans2[n] = 0;
  Int last = -1;
  Int big = 1;
  for(Int i = 0;i < n;i++){
    ans1[i] = str1[i];
    ans2[i] = str2[i];
  }
  for(Int i = 0;i < n;i++){
  
    
    if(str1[i] == str2[i] && str1[i] == '?'){
      ans1[i] = ans2[i] = '0';
      continue;
    }
    if(str1[i] == str2[i])continue;
    if(str1[i] == '?' && str2[i] != '?'){
      ans1[i] = str2[i];
      continue;
    }
    if(str1[i] != '?' && str2[i] == '?'){
      ans2[i] = str1[i];
      continue;
    }
    last = i;
    if(str1[i] < str2[i])big = 2;
    break;
  }
  if(last != -1){

 
    for(Int i = last;i < n;i++){
 
      if(ans1[i] == '?'){
	if(big == 1)ans1[i] = '0';
	if(big == 2)ans1[i] = '9';
      }
      if(ans2[i] == '?'){
	if(big == 1)ans2[i] = '9';
	if(big == 2)ans2[i] = '0';
      }
    }
  }
  Int result = tonum(ans1) - tonum(ans2);
  if(result < 0)result = -result;
  if(nowmin > result){
    nowmin = result;
    rans1 = ans1;
    rans2 = ans2;
  }
  else if(nowmin == result && tonum(ans1) < tonum(rans1)){
    nowmin = result;
    rans1 = ans1;
    rans2 = ans2;
  }
  else if(nowmin == result && tonum(ans1) == tonum(rans1) && tonum(ans2) < tonum(rans2)){
    nowmin = result;
    rans1 = ans1;
    rans2 = ans2;
  }  
};

void solve(){
  nowmin = 1LL << 62;
  string stri1, stri2;
  char str1[1080], str2[1080];
  Int n;
  cin >> stri1 >> stri2;
  n = stri1.size();
  str1[n] = str2[n] = 0;
  for(Int i = 0;i < n;i++)str1[i] = stri1[i], str2[i] = stri2[i];
  for(Int i = 0;i < n;i++){
    for(Int j = 0;j <= 9;j++){
      if(str1[i] != '?' && str1[i] - '0' != j)continue;
      bool back = str1[i] == '?';
      str1[i] = (char)('0' + j);
      for(Int k = 0;k <= 9;k++){
	if(str2[i] != '?' && str2[i] - '0' != k)continue;
	bool back2 = str2[i] == '?';
	str2[i] = (char)('0' + k);
	_solve(str1, str2, n);
	if(back2)str2[i] = '?';
      }
      if(back)str1[i] = '?';
    }
  }
  cout << rans1 << " " << rans2;
}

int main(){
  Int t;
  cin >> t;
  for(Int i = 1;i <= t;i++){
    cout << "Case #" << i << ": ";
    solve();
    cout << endl;
  }
  return 0;
}
