#include <bits/stdc++.h>

using namespace std;

int jp[15][15];
int ps[15][15];
int js[15][15];

vector<pair<int,pair<int,int> > > vv;

#define x first
#define y second.first
#define z second.second

int aa,bb,cc;

vector<int> Solve(int i,vector<int> &v) {
  vector<int> best = v;
  for(int j = i + 1;j < vv.size();j++) {
    if(best.size() == aa * bb * cc) return best;
    int a = vv[j].x;
    int b = vv[j].y;
    int c = vv[j].z;
    if(jp[a][b] && ps[b][c] && js[a][c]) {
      v.push_back(j);
      jp[a][b]--;
      ps[b][c]--;
      js[a][c]--;
      vector<int> tmp = Solve(j,v);
      if(tmp.size() > best.size()) best = tmp;
      if(best.size() == aa * bb * cc) return best;
      v.pop_back();
      jp[a][b]++;
      ps[b][c]++;
      js[a][c]++;
    }
  }
  return best;
}

void solve() {
  int a,b,c,k; cin>>a>>b>>c>>k;
  aa = a;
  bb = b;
  cc = c;
  vv.clear();
  for(int i = 1;i <= a;i++) {
    for(int j = 1;j <= b;j++) {
      for(int x = 1;x <= c;x++) {
        jp[i][j] = k;
        ps[j][x] = k;
        js[i][x] = k;
        vv.push_back({i,{j,x}});
      }
    }
  }
  vector<int> v;
  vector<int> ans;
  for(int i = 0;i < vv.size();i++) {
    if(jp[vv[i].x][vv[i].y] && ps[vv[i].y][vv[i].z] && js[vv[i].x][vv[i].z]) {
      jp[vv[i].x][vv[i].y]--;
      ps[vv[i].y][vv[i].z]--;
      js[vv[i].x][vv[i].z]--;
      v.push_back(i);
      vector<int> tmp = Solve(i,v);
      if(tmp.size() > ans.size())ans = tmp;
      v.pop_back();
      jp[vv[i].x][vv[i].y]++;
      ps[vv[i].y][vv[i].z]++;
      js[vv[i].x][vv[i].z]++;

    }
  }
  cout<<ans.size()<<endl;
  for(int i = 0;i < ans.size();i++) {
    cout<<vv[ans[i]].x<<' '<<vv[ans[i]].y<<' '<<vv[ans[i]].z<<endl;
  }
}

int main() {
  assert(freopen("input.txt","r",stdin));
  assert(freopen("output.txt","w",stdout));
  int t; cin>>t;
  for(int i = 1;i <= t;i++) {
    cerr<<"Executing Case #"<<i<<endl;
    cout<<"Case #"<<i<<": ";
    solve();
  }

}
