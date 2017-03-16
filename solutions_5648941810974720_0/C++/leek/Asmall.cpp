#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
string ph;
int cnt[27];
bool ce(char x, int num) {

  int xxx = x - 'A';
  if(cnt[xxx] >= num){ 
    return true;
  }
  else
    return false;
}
void de(char x, int num) {
  cnt[x- 'A'] -= num;
}

vector<int> getNumber(){
  vector<int> ret;
  while(ce('Z', 1) && ce('E', 1) && ce('R', 1) && ce('O', 1)) {
    de('Z', 1);
    de('E', 1);
    de('R', 1);
    de('O', 1);
    ret.push_back(0);
  }
  while(ce('S', 1) && ce('I', 1) && ce('X', 1)) {
    de('S', 1);
    de('I', 1);
    de('X', 1);
    ret.push_back(6);
  }
  while(ce('E', 1) && ce('I', 1) && ce('G', 1) && ce('H', 1) && ce('T', 1)) {
    de('E', 1);
    de('I', 1);
    de('G', 1);
    de('H', 1);
    de('T', 1);
    ret.push_back(8);
  }

  while(ce('F', 1) && ce('O', 1) && ce('U', 1) && ce('R', 1)) {
    de('F', 1);
    de('O', 1);
    de('U', 1);
    de('R', 1);
    ret.push_back(4);
  }
  while(ce('T', 1) && ce('H', 1) && ce('R', 1) && ce('E', 2)) {
    de('T', 1);
    de('H', 1);
    de('R', 1);
    de('E', 2);
    ret.push_back(3);
  }  

  while(ce('T', 1) && ce('W', 1) && ce('O', 1)) {
    de('T', 1);
    de('W', 1);
    de('O', 1);
    ret.push_back(2);
  }

  while(ce('F', 1) && ce('E', 1) && ce('I', 1) && ce('V', 1)) {
    de('F', 1);
    de('I', 1);
    de('V', 1);
    de('E', 1);
    ret.push_back(5);
  }

  while(ce('S', 1) && ce('E', 2) && ce('V', 1) && ce('N', 1)) {
    de('S', 1);
    de('E', 2);
    de('V', 1);
    de('N', 1);
    ret.push_back(7);
  }

  while(ce('I', 1) && ce('E', 1) && ce('N', 2)) {
    de('N', 2);
    de('I', 1);
    de('E', 1);
    ret.push_back(9);
  }
  while(ce('O', 1) && ce('E', 1) && ce('N', 1)) {
    de('O', 1);
    de('N', 1);
    de('E', 1);
    ret.push_back(1);
  }

  sort(ret.begin(), ret.end());
  return ret;
}

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    for(int i=0; i<27;i ++)
      cnt[i] = 0;
    cin >> ph;

    for(int i=0; i<ph.size(); i++) {
      cnt[ph[i] - 'A'] ++;
    }
    vector<int> ret = getNumber();

    printf("Case #%d: ",tc);
    for(int i=0; i<ret.size(); i++) printf("%d", ret[i]);
    printf("\n");

  }

  return 0;
}