#define _CRT_SECURE_NO_DEPRECATE
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;
struct chest {
  int key;
  vector<int> ks;
};


int cur[256];
short mem[1 << 21];
int solve(const vector<int>& initial, const vector<chest>& b, int opened) {
  int n = (int)b.size();
  memset(cur, 0, sizeof(cur));
  for (int i = 0;i<initial.size();++i) {
    cur[initial[i]]++;
  }

  for (int i=0;i<n;++i){
    if (opened & (1<< i)) {
      cur[b[i].key]--;
      for (int j=0;j<b[i].ks.size();++j) {
        cur[b[i].ks[j]]++;
      }
    } 
  }

  vector<int> lft;
  for (int i=0;i<n;++i){
    if (cur[b[i].key] > 0 && !(opened & (1<< i))) {
      lft.push_back(i);
    }
  }

  for (int i = 0;i<lft.size();++i) {
    int idx = lft[i];

    int nk = (opened| (1 << idx));
    if (nk == ((1<< n) - 1)) {
      return mem[opened] = idx;
    }
    int t = ((mem[nk]==-1)?solve(initial, b, nk):mem[nk]);
    if (t != -2) {
      return mem[opened] = idx;
    }
  }

  return mem[opened] = -2;
}

//vector<int> solve(vector<int>& cur, const vector<chest>& b, vector<int>& opened) {
//  vector<int> pos;
//  int m = (int)b.size();
//  for (int i = 0; i < m ;++i) {
//    if (opened[i] == 0) {
//      pos.push_back(i);
//    }
//  }
//  for (int i = 0; i < (int)pos.size(); ++i) {
//    int idx = pos[i];
//    if (cur[b[idx].key] > 0) {
//      if (pos.size() == 1) {
//        return vector<int>(1, idx);
//      }
//
//      opened[idx] = 1;
//      cur[b[idx].key]--;
//      for (int j =0;j<(int)b[idx].ks.size();++j) {
//        cur[b[idx].ks[j]]++;
//      }
//
//      vector<int> temp = solve(cur, b, opened);
//      if (temp.size() != 0) {
//        temp.push_back(idx);
//        return temp;
//      }
//
//      cur[b[idx].key]++;
//      opened[idx] = 0;
//      for (int j =0;j<(int)b[idx].ks.size();++j) {
//        cur[b[idx].ks[j]]--;
//      }
//    }
//  }
//
//
//  return vector<int>();
//}

int main()
{
  freopen("google.in","r",stdin);
  freopen("google.out","w",stdout);
  int nt;
  cin>>nt;
  for(int it=1;it<=nt;it++)
  {
    vector<int> cur;
    vector<chest> b;
    int n,k;
    cin >> n  >> k;
    for (int i = 0; i < n;++i) {
      int tmp;
      scanf("%d", &tmp);
      cur.push_back(tmp);
    }

    for (int i=0;i<k;++i) {
      chest temp;
      int m;
      cin >> temp.key;
      cin >> m;
      temp.ks.resize(m);
      for (int j=0;j<m;++j) {
        scanf("%d", &temp.ks[j]);
      }
      b.push_back(temp);
    }
    
    memset(mem, -1, sizeof(mem));
    int res = solve(cur, b, 0);

    cout<<"Case #"<<it<<":";
    if (res == -2) {
      cout << " IMPOSSIBLE"<<endl;
    } else {
      int c = res;
      int mask = (1 << res);
      int br = 0;
      while (br < k) {
        cout << " " << res + 1;
        mask |= (1 << res);
        res = mem[mask];
        br++;
      }
      cout << endl;
    }
    /*if (res.size() > 0) {
      reverse(all(res));
    }
    
    
    if (res.size() == 0) {
      cout << " IMPOSSIBLE"<<endl;
    } else {
      for (int i=0;i<res.size();++i) {
        cout << " " << res[i] + 1;
      }
      cout<< endl;
    }*/
  }
  return 0;
}
