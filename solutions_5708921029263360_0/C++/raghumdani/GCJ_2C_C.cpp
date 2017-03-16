#include <bits/stdc++.h>

using namespace std;
const int INF = 10001000;

typedef long long L;
int used1[10][10], used2[10][10], used3[10][10];
int used[10][10][10];
vector <int> gl;
int j, p, s, k, tot;

int hamming(vector <int> aa, vector <int> bb) {
  int na = aa.size(), nb = bb.size();
  int sz = min(na, nb);
  
  int res = 0;
  
  for(int i = 0; i < sz; ++i) {
    res += aa[i] != bb[i];
  }
  return res;
}

bool isValid(vector <int> v) {
  if(v.size() != 3) return false;
  if(v[0] >= j || v[1] >= p || v[2] >= s) return false;
  if(used[v[0]][v[1]][v[2]]) return false;
  return true;
}

int get() {
  gl.clear();
  int curMax = 0;
  for(int i = 0; i < tot; ++i) {
    vector <int> vv;
    int cur = i;
    for(int jj = 0; jj < 3; ++jj) {
      vv.push_back(cur % s);
      cur /= s;
    }
    reverse(vv.begin(), vv.end());
    if(!isValid(vv)) continue;
    
    if(hamming(gl, vv) >= curMax) {
      curMax = hamming(gl, vv);
      gl = vv;
    }
  }
  
  if(gl.empty()) return 0;
  int one = gl[0], two = gl[1], three = gl[2];
  used1[one][two]++;
  used2[two][three]++;
  used3[one][three]++;
  used[one][two][three] = 1;
  
  if(used1[one][two] > k) return 0;
  if(used2[two][three] > k) return 0;
  if(used3[one][three] > k) return 0;
  return 10;
}

int main()
{
  freopen("IN.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  
  int t;
  scanf("%d", &t);
  
  for(int tt = 1; tt <= t; ++tt) {
    scanf("%d %d %d %d", &j, &p, &s, &k);
    
    memset(used, 0, sizeof(used));
    memset(used1, 0, sizeof(used1));
    memset(used2, 0, sizeof(used2));
    memset(used3, 0, sizeof(used3));
    
    tot = 1;
    for(int i = 0; i < 3; ++i) {
      tot *= s;
    }
    
    vector < vector <int> > ans;
    while(get() != 0) {
      ans.push_back(gl);
    }
    
    printf("Case #%d: %d\n", tt, ans.size());
    int nn = ans.size();
    
    for(int i = 0; i < nn; ++i) {
      for(int j = 0; j < 3; ++j) {
        printf("%d%c", ans[i][j] + 1, (j == 2)?'\n':' ');
      }
    }
  }
  return(0);
}
