#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<char, char> cp;

int getInt() {
  int v;
  scanf("%d", &v);
  return v;
}

ll getLong() {
  int v;
  cin >> v;
  return v;
}

int pmod(int i,int n) {
  return (n + (i % n)) % n;
}

vi getVector(int n) {
  vi vec;
  for(int i=0;i<n;i++) {
    int v = getInt();
    vec.push_back(v);
  }
  return vec;
}

char getChar() {
  char c;
  scanf("%c", &c);
  if(c != 'i' && c != 'j' && c != 'k')
    return getChar();
  return c;
}

// 1 = 1, 2 = i, 3 = j, 4 = k ;
int tr(int state, char input) {
  int sign = 1;
  if (state < 0) sign = -1;
  state = abs(state);
  if(state == 1) {
    if(input == 'i') { return sign * 2;}
    if(input == 'j') { return sign * 3;}
    if(input == 'k') { return sign * 4;}
  } else if(state == 2) {
    if(input == 'i') { return sign * -1;}
    if(input == 'j') { return sign * 4;}
    if(input == 'k') { return sign * -3;}
  } else if(state == 3) {
    if(input == 'i') { return sign * -4;}
    if(input == 'j') { return sign * -1;}
    if(input == 'k') { return sign * 2;}
  } else if(state == 4) {
    if(input == 'i') { return sign * 3;}
    if(input == 'j') { return sign * -2;}
    if(input == 'k') { return sign * -1;}
  }
  cout << "ERROR " << state << " : " << input << endl;
  exit(0);
  return state;
}

string solve() {
  int n = getInt();
  ll m = getLong();
  vi s(8), min_i(8, 123456789), max_j(8, -123456789);
  // starting states
  for(int i=0;i<4;i++) {
    s[i] = i + 1;
    s[i+4] = -(i + 1);
  }
  
  for(int i=0;i<n;i++) {
    char c = getChar();
    for(int j=0;j<8;j++) {
      //printf("transition %d %d %d -> %d\n", i, j, s[j], tr(s[j], c)); 
      s[j] = tr(s[j], c);
      if(s[j] == 2) min_i[j] = min(min_i[j], i);
      if(s[j] == 4) max_j[j] = max(max_j[j], i);
    }
  }

  int state = 1;
  int cycle = -1;
  int d = -1, max_max_j = -123456789, min_min_i = 123456789;
  for(int i=0;i<24;i++) {
    if(state == -1 && min_min_i < max_max_j) {
      d = i;
      if(cycle == -1) cycle = 2 * d;
      else(cycle = i - cycle);
      break;
    }
    if(state == -1) {
      cycle = i;
    }
    int q = state - 1;
    if(state < 0) q = 3 - state;
    min_min_i = min(min_min_i, min_i[q] + i * n);
    max_max_j = max(max_max_j, max_j[q] + i * n);

    //cout << "state : " << state << " " << q << " " << min_min_i << " " << max_max_j << " " << min_i[q] << " " << max_j[q] << endl;

    state = s[q];
  }

  //cout << "min i :"<< min_min_i << endl;
  //cout << "max j :"<< max_max_j << endl;
  //cout << "depth:" << d << " " << ((m / d) % 2) << endl;
  //cout << "cycle:" << cycle << endl;
  if(d < 0 || d > m || pmod(m - d, cycle) != 0) {
    return "NO";
  }
  
  return "YES";
}

string brutef() {
  int n = getInt();
  ll m = getLong();
  string s0, s1;
  cin >> s0;
  for(int i=0;i<m;i++) {
    s1 += s0;
  }
  //cout << s1 << endl;
  stringstream ss(s1);
  int s = 1, min_i = 123456789, max_j = -123456789;

  // find i
  for(int i=0;i<n*m;i++) {
    char c;
    ss >> c;
    //cout << "transition:" << s << " " << c << " " << tr(s,c) << endl;
    s = tr(s, c);
    if(s == 2) min_i = min(min_i, i);
    if(s == 4) max_j = max(max_j, i);
  }

  if(s == -1 && min_i < max_j) {
    return "YES";
  }
  
  return "NO";
}

int main() {
  int T = getInt();
  for(int tt=1;tt<=T;tt++) {
    string ans = brutef();
    printf("Case #%d: ", tt);
    cout << ans << endl;
  }
}
