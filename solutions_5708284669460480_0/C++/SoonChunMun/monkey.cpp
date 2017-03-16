#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int t,k,s,l;
int spins;
double maxbanana;

double freq[27];
double freql[27];
char target[110], keyboard[110];

vector<string> poss;
vector<int> exbanana;

bool isSame(char *w1, char *w2) {
  for (int i=0; i<k; i++) {
    if (w1[i] != w2[i]) return false;
  }
  return true;
}

int checkit(string s1) {
  int tot = 0;

  for (int i=0; i<s-l+1; i++) {
    if (s1[i] == target[0]) {
      int j=0;
      for (j=0; j<l && s1[j+i] == target[j]; j++)
        continue;

      if (j == l) {
        tot++;
      }
    }
  }
  if (tot>maxbanana) maxbanana = tot;
  return tot;
}

void brute(int pos) {
  if (pos == s-1) {
    for (int i=0; i<k; i++) {
      stringstream s2;
      s2 << keyboard[i];
      poss.push_back(s2.str());
    }
    return;
  }

  brute(pos+1);
  vector<string> a;
  for (string s: poss) {
    for (int i=0; i<k; i++) {
      stringstream s2;
      s2 << keyboard[i];
      s2 << s;
      a.push_back(s2.str());
    }
  }
  poss = a;
}

int main() {
  scanf("%d", &t);
  for (int ca=1;ca<=t;ca++) {
    maxbanana = spins = 0;
    exbanana.clear();
    poss.clear();
    scanf("%d %d %d", &k, &l, &s);
    memset(target,0,sizeof(target));
    memset(keyboard,0,sizeof(keyboard));

    memset(freq, 0, sizeof(freq));
    memset(freql, 0, sizeof(freql));

    for (int i=0; i<k; i++) {
      scanf(" %c", &keyboard[i]);
      freq[(int)(keyboard[i]-'A')]+=1;
    }

    for (int i=0; i<l; i++) {
      scanf(" %c", &target[i]);
      freql[(int)(target[i]-'A')]+=1;
    }

    double ans = 0.0;
    bool good = true;
    for (int i=0; i<26; i++) {
      if (freql[i]>0 && freq[i] == 0) {
        printf("Case #%d: %lf\n", ca, ans);
        good = false; break;
      }
      freq[i] /= k;
    }

    if (!good) continue;
    brute(0);
    for (string s1: poss) {
      exbanana.push_back(checkit(s1));
    }

    spins = poss.size();
    double exp = 0;
    for (int j : exbanana) {
      exp += j / (double)exbanana.size();
    }

    // cout << maxbanana << " and " << exbanana << endl;
    ans = maxbanana - exp;

    printf("Case #%d: %lf\n", ca, ans);
  }
  return 0;
}
