#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> stringvec;

#define MOD 1000000007

int lets[26];

typedef long long int ll;

void resetLets() {
  for(int i = 0; i < 26; i++) {
    lets[i] = 0;
  }
}

ll fact(int no) {
  ll ret = 1;
  for(int i = 1; i <= no; i++) {
    ret *= i;
    ret %= MOD;
  }
  return ret % MOD;
}


void printvec() {
  for(vector<string>::iterator it = stringvec.begin(); it < stringvec.end(); it++) {
    cout << *it << " ";
  }
  cout << "\n";
}
    


void work(int caseno) {
  cout << "Case #" << caseno << ": ";
  int N;
  cin >> N;
  int i;
  string tempstr;
  stringvec.clear();
  for(i = 0; i < N; i++) {
    cin >> tempstr;
    stringvec.push_back(tempstr);
  }
  vector<string>::iterator it;
  // for(it = stringvec.begin(); it < stringvec.end(); it++) {
  //   tempstr = *it;
  //   cout << tempstr << " ";
  // }
  // cout << "\n";

  ll ans = 1;
  string st;
  char c;
  int cnt;
  for(c = 'a'; c <= 'z'; c++) {
    tempstr = "";
    cnt = 0;
    for(it = stringvec.begin(); it < stringvec.end(); it++) {
      st = *it;
      if(st.at(0) == c && c == st.at(st.length() - 1)) {
	tempstr += st;
	stringvec.erase(it);
	cnt++;
	it--;
      }
    }
    ans *= fact(cnt);
    if(tempstr != "") {
      stringvec.push_back(tempstr);
    }
  }

  //cout << "hit\n";
  
  vector<string>::iterator it1, it2;
  char lastchar;
  char firstchar;
  int flag;
  for(it1 = stringvec.begin(); it1 < stringvec.end(); it1++) {
    tempstr = *it1;
    lastchar = tempstr.at(tempstr.length() - 1);
    flag = 0;
    
    for(it2 = stringvec.end() - 1; it2 >= stringvec.begin(); it2--) {
      if(it1 == it2) continue;
      st = *it2;
      firstchar = st.at(0);
      
      if(lastchar == firstchar) {
	tempstr += st;
	stringvec.erase(it1);
	if(it1 < it2) it2--;
	else it1--;
	stringvec.erase(it2);
	it1--;
	//printvec();
	flag = 1;
	break;
      }
    }
    if(flag == 1) {
      stringvec.insert(it1 + 1, tempstr);
      //printvec();
    }
  }
  //printvec();

  tempstr = "";
  for(it = stringvec.begin(); it < stringvec.end(); it++) {
    tempstr += *it;
  }

  char prevc, currc;
  flag = 0;
  resetLets();
  for(i = 0; i < (int)tempstr.length(); i++) {
    if(i == 0) {
      prevc = tempstr.at(i);
      lets[prevc - 'a'] = 1;
      continue;
    }
    currc = tempstr.at(i);
    if(currc == prevc) continue;
    if(lets[currc - 'a'] == 1) {
      flag = 1;
      break;
    }
    lets[currc - 'a'] = 1;
    prevc = currc;
  }
  if(flag == 1) {
    cout << "0\n";
    return;
  }

  ans *= fact((int)stringvec.size());

  ans %= MOD;

  cout << ans << "\n";  
}

int main() {
  int T;
  cin >> T;
  for(int cnt = 1; cnt <= T; cnt++) {
    work(cnt);
  }
  return 0;
}
