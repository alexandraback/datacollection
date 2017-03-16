#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<utility>

using namespace std;

struct Quaternion {
  int sgn;
  char value;
  Quaternion(int s, char v) : sgn(s), value(v) {}
};

bool operator==(const Quaternion &q1, const Quaternion &q2) {
  return q1.sgn == q2.sgn && q1.value == q2.value;
}

Quaternion operator*(Quaternion q1, Quaternion q2) {
  if(q1.value == '1') {
    return Quaternion(q1.sgn*q2.sgn, q2.value);
  } else if(q2.value == '1') {
    return Quaternion(q1.sgn*q2.sgn, q1.value);
  } else if((q1.value == 'i' && q2.value == 'i') ||
      (q1.value == 'j' && q2.value == 'j') ||
      (q1.value == 'k' && q2.value == 'k')) {
    return Quaternion(-q1.sgn*q2.sgn, '1');
  } else if(q1.value == 'i' && q2.value == 'j') {
    return Quaternion(q1.sgn*q2.sgn, 'k');
  } else if(q1.value == 'j' && q2.value == 'i') {
    return Quaternion(-q1.sgn*q2.sgn, 'k');
  } else if(q1.value == 'i' && q2.value == 'k') {
    return Quaternion(-q1.sgn*q2.sgn, 'j');
  } else if(q1.value == 'k' && q2.value == 'i') {
    return Quaternion(q1.sgn*q2.sgn, 'j');
  } else if(q1.value == 'j' && q2.value == 'k') {
    return Quaternion(q1.sgn*q2.sgn, 'i');
  } else if(q1.value == 'k' && q2.value == 'j') {
    return Quaternion(-q1.sgn*q2.sgn, 'i');
  }
}


int main(void) {
  int64_t T;
  cin >> T;
  for(int64_t t=1;t<=T;t++) {
    int64_t L,X;
    cin >> L >> X;
    string s;
    cin >> s;

    Quaternion q(1,'1');
    int64_t foundi=-1,foundj=-1,foundk=-1,foundminusi=-1,foundminusj=-1,foundminusk=-1,foundminusone=-1;
    for(int64_t i=0;i<L;i++) {
      q=q*Quaternion(1,s[i]);
      if(q.sgn == 1 && q.value == 'i') {
        if(foundi == -1) foundi=i;
      } else if(q.sgn == 1 && q.value == 'j') {
        if(foundj == -1) foundj=i;
      } else if(q.sgn == 1 && q.value == 'k') {
        if(foundk == -1) foundk=i;
      } else if(q.sgn == -1 && q.value == 'i') {
        if(foundminusi == -1) foundminusi=i;
      } else if(q.sgn == -1 && q.value == 'j') {
        if(foundminusj == -1) foundminusj=i;
      } else if(q.sgn == -1 && q.value == 'k') {
        if(foundminusk == -1) foundminusk=i;
      } else if(q.sgn == -1 && q.value == '1') {
        if(foundminusone == -1) foundminusone=i;
      }
    }
    if(foundi == -1) {
      if(X == 1) {
        cout << "Case #" << t << ": NO\n";
        continue;
      }
      if(foundj != -1) {
        if(q*Quaternion(1,'j') == Quaternion(1,'i')) foundi=L+foundj;
      }
      if(foundk != -1) {
        if(q*Quaternion(1,'k') == Quaternion(1,'i')) foundi=L+foundk;
      }
      if(foundminusi != -1) {
        if(q*Quaternion(-1,'i') == Quaternion(1,'i')) foundi=L+foundminusi;
      }
      if(foundminusj != -1) {
        if(q*Quaternion(-1,'j') == Quaternion(1,'i')) foundi=L+foundminusj;
      }
      if(foundminusk != -1) {
        if(q*Quaternion(-1,'k') == Quaternion(1,'i')) foundi=L+foundminusk;
      }
      if(foundminusone != -1) {
        if(q*Quaternion(-1,'1') == Quaternion(1,'i')) foundi=L+foundminusone;
      }
      if(foundi == -1) {
        if(X == 2) {
          cout << "Case #" << t << ": NO\n";
          continue;
        }
        if(foundminusi != -1 && q*q == Quaternion(-1,'1')) {
          foundi=2*L+foundminusi;
        }
        if(foundi == -1) {
          if(X == 3) {
            cout << "Case #" << t << ": NO\n";
            continue;
          }
          if(foundj != -1) {
            if(q*q*q*Quaternion(1,'j') == Quaternion(1,'i')) foundi=3*L+foundj;
          }
          if(foundk != -1) {
            if(q*q*q*Quaternion(1,'k') == Quaternion(1,'i')) foundi=3*L+foundk;
          }
          if(foundminusi != -1) {
            if(q*q*q*Quaternion(-1,'i') == Quaternion(1,'i')) foundi=3*L+foundminusi;
          }
          if(foundminusj != -1) {
            if(q*q*q*Quaternion(-1,'j') == Quaternion(1,'i')) foundi=3*L+foundminusj;
          }
          if(foundminusk != -1) {
            if(q*q*q*Quaternion(-1,'k') == Quaternion(1,'i')) foundi=3*L+foundminusk;
          }
          if(foundminusone != -1) {
            if(q*q*q*Quaternion(-1,'1') == Quaternion(1,'i')) foundi=3*L+foundminusone;
          }
          if(foundi == -1) {
            cout << "Case #" << t << ": NO\n";
            continue;
          }
        }
      }
    }
    int64_t myi=foundi;
    // We found i, look for k
    q=Quaternion(1,'1');
    foundi=-1,foundj=-1,foundk=-1,foundminusi=-1,foundminusj=-1,foundminusk=-1,foundminusone=-1;
    for(int64_t i=L-1;i>=0;i--) {
      q=Quaternion(1,s[i])*q;
      if(q.sgn == 1 && q.value == 'i') {
        if(foundi == -1) foundi=L-1-i;
      } else if(q.sgn == 1 && q.value == 'j') {
        if(foundj == -1) foundj=L-1-i;
      } else if(q.sgn == 1 && q.value == 'k') {
        if(foundk == -1) foundk=L-1-i;
      } else if(q.sgn == -1 && q.value == 'i') {
        if(foundminusi == -1) foundminusi=L-1-i;
      } else if(q.sgn == -1 && q.value == 'j') {
        if(foundminusj == -1) foundminusj=L-1-i;
      } else if(q.sgn == -1 && q.value == 'k') {
        if(foundminusk == -1) foundminusk=L-1-i;
      } else if(q.sgn == -1 && q.value == '1') {
        if(foundminusone == -1) foundminusone=L-1-i;
      }
    }
    if(foundk == -1) {
      if(X == 1) {
        cout << "Case #" << t << ": NO\n";
        continue;
      }
      if(foundi != -1) {
        if(Quaternion(1,'i')*q == Quaternion(1,'k')) foundk=L+foundi;
      }
      if(foundj != -1) {
        if(Quaternion(1,'j')*q == Quaternion(1,'k')) foundk=L+foundj;
      }
      if(foundminusi != -1) {
        if(Quaternion(-1,'i')*q == Quaternion(1,'k')) foundk=L+foundminusi;
      }
      if(foundminusj != -1) {
        if(Quaternion(-1,'j')*q == Quaternion(1,'k')) foundk=L+foundminusj;
      }
      if(foundminusk != -1) {
        if(Quaternion(-1,'k')*q == Quaternion(1,'k')) foundk=L+foundminusk;
      }
      if(foundminusone != -1) {
        if(Quaternion(-1,'1')*q == Quaternion(1,'k')) foundk=L+foundminusone;
      }
      if(foundk == -1) {
        if(X == 2) {
          cout << "Case #" << t << ": NO\n";
          continue;
        }
        if(foundminusk != -1 && q*q == Quaternion(-1,'1')) {
          foundk=2*L+foundminusk;
        }
        if(foundk == -1) {
          if(X == 3) {
            cout << "Case #" << t << ": NO\n";
            continue;
          }
          if(foundi != -1) {
            if(Quaternion(1,'i')*q*q*q == Quaternion(1,'k')) foundk=3*L+foundi;
          }
          if(foundj != -1) {
            if(Quaternion(1,'j')*q*q*q == Quaternion(1,'k')) foundk=3*L+foundj;
          }
          if(foundminusi != -1) {
            if(Quaternion(-1,'i')*q*q*q == Quaternion(1,'k')) foundk=3*L+foundminusi;
          }
          if(foundminusj != -1) {
            if(Quaternion(-1,'j')*q*q*q == Quaternion(1,'k')) foundk=3*L+foundminusj;
          }
          if(foundminusk != -1) {
            if(Quaternion(-1,'k')*q*q*q == Quaternion(1,'k')) foundk=3*L+foundminusk;
          }
          if(foundminusone != -1) {
            if(Quaternion(-1,'1')*q*q*q == Quaternion(1,'k')) foundk=3*L+foundminusone;
          }
          if(foundk == -1) {
            cout << "Case #" << t << ": NO\n";
            continue;
          }
        }
      }
    }
    int64_t myk=X*L-1-foundk;
    bool flag=false;
    if(q.sgn == -1 && q.value == '1' && X%2 == 1) flag=true;
    if(q.value != '1' && X%2 == 0 && (X/2)%2 == 1) flag=true;
    if(myi < myk && flag) {
      cout << "Case #" << t << ": YES\n";
    } else {
      cout << "Case #" << t << ": NO\n";
    }
  }

  return 0;
}

