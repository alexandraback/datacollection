#include <iostream>

using namespace std;

struct quat {
  char c;
  bool pos;
  quat() {
    c = '1';
    pos = true;
  }
  quat(char init_c, bool init_pos) 
  {
    c = init_c;
    pos = init_pos;
  }
};

void print_quat(struct quat &a) {
  if (!a.pos) cout << "-";
  cout << a.c << endl;
}

struct quat mult(struct quat &a, struct quat &b) {
  struct quat ret;
  if (a.c == '1') ret.c = b.c;
  else if (b.c == '1') ret.c = a.c;
  else if (a.c == b.c) {ret.c = '1'; ret.pos = false;}
  else if (a.c == 'i' && b.c == 'j') ret.c = 'k';
  else if (a.c == 'j' && b.c == 'i') {ret.c = 'k'; ret.pos = false;}
  else if (a.c == 'k' && b.c == 'j') {ret.c = 'i'; ret.pos = false;}
  else if (a.c == 'j' && b.c == 'k') ret.c = 'i';
  else if (a.c == 'k' && b.c == 'i') ret.c = 'j';
  else if (a.c == 'i' && b.c == 'k') {ret.c = 'j'; ret.pos = false;}
  
  if (!a.pos) ret.pos = !ret.pos;
  if (!b.pos) ret.pos = !ret.pos;

  return ret;
}

int main() {

  long long ncases;
  cin >> ncases;
/*
  struct quat a('k', true);
  struct quat b('k', true);
  struct quat c('i', true);
  struct quat d('i', true);
  struct quat e('i', true);
  struct quat f('i', true);
  struct quat q;
  for (long long g = 0; g < 4; g++) {
    q = mult(q,a);
    q = mult(q,b);
    q = mult(q,c);
    q = mult(q,d);
    q = mult(q,e);
    q = mult(q,f);
  }
  prlong long_quat(q);
*/
  
  for (long long i = 0; i < ncases; i++) {
    long long inlen, inrep;
    string instr;
    cin >> inlen >> inrep >> instr;
    bool poss = false;

    string str = "";
    long long rep = (long long)min(inrep, inrep%12 + 12);
    for (long long r = 0; r < rep; r++) {
      str += instr;
    }
    long long len = str.size();

    //Check if whole string is '-1'
    struct quat q;
    for (long long s = 0; s < len; s++){ 
      struct quat temp(str[s], true);
      q = mult(q,temp);
//      prlong long_quat(q);
    }
//    prlong long_quat(q);

    if (q.c == '1' && !q.pos) {
      long long endi, startk;
      struct quat qi;
      bool possi = false;
      for (long long s = 0; s < len; s++) {
        struct quat temp(str[s], true);
        qi = mult(qi, temp);
        if (qi.c == 'i' && qi.pos) {
          possi = true; 
          endi = s;
//          cout << "endi: " << endi << endl;
          break;
        }
      }

      struct quat qk;
      bool possk = false;
      for (long long s = len-1; s > endi; s--) {
        struct quat temp(str[s], true);
        qk = mult(temp, qk);
        if (qk.c == 'k' && qk.pos) {
          possk = true; 
          startk = s;
//          cout << "startk: " << s << endl;
          break;
        }
      }
      if (possi && possk) {
        struct quat qj;
        for (long long s = endi+1; s < startk; s++) {
          struct quat temp(str[s], true);
          qj = mult(qj, temp);
        }
        if (qj.c == 'j' && qj.pos) poss = true;
      }
      
    }
    cout << "Case #" << i+1 << ": ";
    if (poss) cout << "YES" << endl;
    else cout << "NO" << endl;
  
  }
  
  return 0;
}

