#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define in(a,b) ( (b).find(a) != (b).end())

int l,x;

char value[]="1ijk";

int transl(char c) {
  for(int i=0; value[i]; i++) {
    if (value[i] == c) return i;
  }
  return -1;
}


struct Quart;
Quart mult(Quart a, Quart b);


struct Quart {
  int sign;
  char type;


  Quart operator*(Quart b) {
    return mult(*this, b);
  }

  bool operator<(const Quart &b) const {
    return sign < b.sign || (sign == b.sign && type < b.type);
  }
  bool operator==(const Quart &b) const {
    return sign == b.sign && type == b.type;
  }
};
Quart table[4][4] = { { {1, '1'}, {1, 'i'}, {1, 'j'}, {1,'k'} },
      { {1, 'i'},{-1, '1'}, {1, 'k'},{-1,'j'} },
      { {1, 'j'},{-1, 'k'},{-1, '1'},{ 1,'i'} },
      { {1, 'k'},{ 1, 'j'},{-1, 'i'},{-1,'1'} } };

Quart mult(Quart a, Quart b) {
  Quart r = table[transl(a.type)][transl(b.type)];
  r.sign *= b.sign * a.sign;
  return r;
}



#define MAXN 20000
char s[MAXN];

int main() {
  ios :: sync_with_stdio(0);
  int t; cin >> t;
  for(int cn=1; cn<=t; cn++) {
    bool ans;
    cin >> l >> x >> s;

    vector<Quart> v;

    /* must form i, then i*j = k and finally (i*j)*k = -1  */
    bool f1 = false;
    bool f2 = false;
    bool f3 = false;

    set<Quart> beg;

    Quart cur = {1, '1'};

    for(int i=0; i<l; i++) {
      cur = cur * Quart({1, s[i]});
    }
    Quart bloc = cur;


    cur = {1, '1'};
    for(int j=0; j<x; j++) {
      if (in(cur, beg)) break;
      beg.insert(cur);

      for(int i=0; i<l; i++) {
        cur = cur * Quart({1, s[i]});
        if (cur == Quart({1, 'i'})) {
          f1 = true;
          beg.clear();
        }
        if (cur == Quart({1, 'k'}) && f1) {
          f2 = true;
        }
      }
    }


    Quart fin = {1, '1'};
    while (x > 0) {
      if (x&1) {
        fin = fin * bloc;
      }

      bloc = bloc * bloc;
      x >>= 1;
    }

    if (f2 && fin == Quart({-1, '1'})) {
      f3 = true;
    }

    ans = f1 && f2 && f3;
    printf("Case #%d: %s\n", cn, ans?"YES":"NO");
  }
  return 0;
}
