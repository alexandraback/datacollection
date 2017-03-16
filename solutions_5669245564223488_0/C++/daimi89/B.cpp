#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

const long long MOD=1000000007;

string cars[100];

long long fac(long long x) {
  if (x<=1) return 1;
  else return (fac(x-1)*x) % MOD;
};

int main() {
  int suf[256],pre[256],only[256],internal[256],pre_car[256];
  bool lead[256];

  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    int N; 
    cin >> N;
    for (int i=0; i<N; i++) cin >> cars[i];

    for (int ch='a'; ch<='z'; ch++)
      lead[ch]=true, pre[ch]=only[ch]=suf[ch]=internal[ch]=0, pre_car[ch]=-1;
    bool valid = true;
    for (int c=0; c<N; c++) {
      bool present[256];
      for (int ch='a'; ch<='z'; ch++) present[ch]=false;
      int len=cars[c].length();
      
      // check multiple blocks in car
      for (int i=0; i<len; i++) {
	if (i>0 && present[cars[c][i]] && cars[c][i]!=cars[c][i-1])
	  valid = false;
	present[cars[c][i]]=true;
      };
      
      // setup suf, pre, only, internal for car c
      char first = cars[c][0], last = cars[c][len-1];
      if (first == last) only[first] ++;
      else pre[first] ++, pre_car[first]=c, suf[last] ++, lead[last]=false;
      for (char ch='a'; ch<='z'; ch++) 
	if (present[ch] && ch!=first && ch!=last) 
	  internal[ch]++;
      
      // internal possible?
      for (char ch='a'; ch<='z'; ch++) 
	if (internal[ch]>=1 && internal[ch]+only[ch]+pre[ch]+suf[ch]>1
	    || suf[ch]>=2
	    || pre[ch]>=2
	    )
	  valid = false;
    };
    //    for (char ch='a'; ch<='z'; ch++) cout << ch << " : " << pre[ch] << " " <<  only[ch] << " " << suf[ch] << " " << internal[ch] << " " << pre_car[ch] << endl;
    if (!valid)
      cout << "Case #" << t << ": 0" << endl;
    else {
      int blocks=0;
      long long answers=1;
      int used = 0;
      
      for (int ch='a'; ch<='z'; ch++)
	if (lead[ch] && pre[ch]+only[ch]>0) {
	  blocks++;
	  char nc=ch;
	  answers = (answers * fac(only[nc])) % MOD;
	  used += only[nc];
	  while (pre[nc]>0) {
	    used += 1;
	    int c=pre_car[nc];
	    nc = cars[c][cars[c].length()-1];
	    answers = (answers * fac(only[nc])) % MOD;
	    used += only[nc];
	  };
	};
      answers = (answers * fac(blocks)) % MOD;
      if (used == N) 
	cout << "Case #" << t << ": " << answers << endl;
      else // cycle
	cout << "Case #" << t << ": 0" << endl;
    };
  };
  return 0;
};
