#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<utility>
#include<iomanip>

using namespace std;

struct triple {
  int64_t x,y,z;
};

bool operator<(const triple &t1, const triple &t2) {
  if(t1.x < t2.x) return true;
  if(t1.x == t2.x && t1.y < t2.y) return true;
  if(t1.x == t2.x && t1.y == t2.y && t1.z < t2.z) return true;
  return false;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);

  int64_t T;
  cin >> T;
  
  for(int64_t t=1;t<=T;t++) {
    int64_t A,B,C,K;
    cin >> A >> B >> C >> K;

    cout << "Case #" << t << ": ";

    vector<triple> stuff;

    int64_t Ablocks=(A+K-1)/K;
    int64_t Bblocks=(B+K-1)/K;

    set<triple> blocks;

    for(int64_t layer=0;layer<min(C,max(K,B));layer++) {
      for(int64_t i=0;i<Ablocks;i++) {
        int64_t ac=i%Ablocks;
        int64_t bc=i%Bblocks;
        for(int64_t x=0;x<min(K,A-ac*K);x++) {
          for(int64_t y=0;y<min(K,B-bc*K);y++) {
            int64_t xx=ac*K+x, yy=(bc*K+layer+y)%B;
            stuff.push_back({xx+1,yy+1,layer+1});
          }
        }
      }
    }

    /*for(int64_t k=0;k<C;k++) {
      for(int64_t i=0;i<A;i++) {
        for(int64_t j=0;j<B;j++) {
          int64_t ii=i/K, jj=j/K, kk=k/K;
          if(blocks.find(triple{ii,jj,kk}) != blocks.end()) {
            stuff.push_back(triple{i+1,j+1,k+1});
          }
        }
      }
    }*/

    cout << stuff.size() << "\n";
    for(int64_t i=0;i<stuff.size();i++) {
      cout << stuff[i].x << " " << stuff[i].y << " " << stuff[i].z << "\n";
    }


  }
  return 0;
}
