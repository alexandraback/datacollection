#include <iostream>
#include <algorithm>
#include <vector>

typedef unsigned long long ull;
typedef long long ll;
using namespace std;
#define N 51

int code = 0;
int jam = 0;
int cur = 2e6;


void check(string s, int c, int j, int pos){
  if(pos == s.size()){
    if(abs(c - j) < cur){
      code = c;
      jam = j;
      cur = (int)abs(c-j);
    }
    else if(abs(c-j) == cur){
      if(c < code){
	code = c;
      }
      else if(c == code){
	if(j < jam){
	  jam = j;
	}
      }
    }
  }
  else{
    if(pos < s.size()/2){
      if(s[pos] == '?'){
	for(int i=0; i<10; i++){
	  check(s,c*10 + i,j,pos + 1);
	}
      }
      else{
	check(s, c*10 + s[pos] - '0',j, pos + 1);
      }
    }
    else{
      if(s[pos] == '?'){
	for(int i=0; i<10; i++){
	  check(s,c,j*10 + i,pos + 1);
	}
      }
      else{
	check(s, c, j*10 + s[pos] - '0', pos + 1);
      }
    }
  }
}

int digits(int val){
  int c =0;
  while(val != 0){
    c++;
    val /= 10;
  }
  return c;
}

int main(){

  int T;
  cin >> T;
  for(int i=0; i< T; i++){
    code = jam = 0;
    cur = 2e6;
    string s;
    string c;
    cin >> c >> s;
    check(c+s,0,0,0);

    cout << "Case #" << i+1 << ": ";
    //cout << s.size() << " " << c.size() << endl;
    for(int j=0; j<s.size() - to_string(code).size(); j++){
      cout << "0";
    }
    cout << code << " ";
    for(int j=0; j<c.size() - to_string(jam).size(); j++){
      cout << "0";
    }
    cout << jam << endl;
  }  
}


