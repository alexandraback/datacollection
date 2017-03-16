#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int get_depth(vector<vector<int> >& rev, vector<int>& depth, int i, int ignore) {
  if(depth[i]) return depth[i];
  int ret = 1;
  for(int j: rev[i]) if(j!=ignore) ret = max(ret, 1+get_depth(rev,depth,j,ignore));
  //cout << i << " -> " << ret << endl;
  return depth[i]=ret;
}

int main(void) {
  int T; cin >> T;
  for(int ts=1; ts<=T; ts++) {
    int N; cin >> N;
    vector<int> seen(N), bff(N);
    vector<int> depth(N);

    vector<vector<int> > rev(N);
    for(int i=0; i<N; i++) {
      int x; cin >> x;
      bff[i] = x-1;
      rev[x-1].push_back(i);
    }

    int ret=0;
    for(int i=0; i<N; i++) if(bff[bff[i]]==i && !seen[i]) {
      ret += get_depth(rev, depth, i, bff[i]) + get_depth(rev, depth, bff[i], i);
      seen[i]=seen[bff[i]]=1;
    }
    int cycle=0;
    for(int i=0; i<N; i++) if(true || !seen[i]) {
      int j=bff[i];
      seen[i]=2+i;
      while(seen[j]!=2+i) {
        seen[j]=2+i;
        j=bff[j];
      }
      //if(seen[j]!=2+i) continue;
      int cnt=1;
      int j1=j;
      j=bff[j1];
      while(j!=j1) {
        //cout << i << " " << j << " " << j1 << endl;
        j=bff[j];
        cnt++;
      }
      cycle=max(cycle, cnt);
    }
    cout << "Case #" << ts << ": " << max(ret, cycle) << endl;
  }
}
