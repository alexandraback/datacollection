#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;

lld fastexp(lld b, lld e){
  lld res = 1;
  while(e){
    if(e & 1)
      res *= b;
    e >>= 1;
    b *= b;
  }
  return res;
}

int main() {
  int T, k, c, s;
  scanf("%d", &T);
  for (int ct = 1; ct <= T; ct ++) {
    scanf("%d %d %d", &k, &c, &s);
    vector <lld> ps;
    lld st = fastexp(k, c - 1);
    lld kc = st * k;
    lld l = 1, r = kc, f = 1;
    while (l <= r && (int)ps.size() <= s) {
      ps.push_back(l + st - f);
      l += st;
      if (c > 1) r -= st, f ++;
    }
    if ((int)ps.size() > s) printf("Case #%d: IMPOSSIBLE\n", ct);
    else {
      /*
      if (k <= 10 && kc <= 1000000) {
	for (int i = 1; i < (1 << k); i ++) {
	  string bb = "", gg = "";
	  for (int j = 0; j < k; j ++) {
	    gg += "G";
	    if (i & (1 << j)) bb += "G";
	    else bb += "L";
	  }
	  string cur = bb;
	  for (int j = 2; j <= c; j ++) {
	    string tmp = "";
	    for (int m = 0; m < (int)cur.length(); m ++)
	      if (cur[m] == 'L') tmp += bb;
	      else tmp += gg;
	    cur = tmp;
	  }
	  bool ck = false;
	  for (auto& p : ps)
	    if (cur[p - 1] == 'G')
	      ck = true;
	  if (!ck) {
	    printf("FAILED! %s %s\n", bb.c_str(), cur.c_str());
	    exit(1);
	  }
	}
      }
      */
      printf("Case #%d: ", ct);
      for (auto& p : ps) 
	printf(" %lld", p);
      printf("\n");
    }
  }
  return 0;
}
