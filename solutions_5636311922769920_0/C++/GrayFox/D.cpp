#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#else
#define DB(x)
#define DBL(x)
#endif

#define ANS(n, r) cout<<"Case #"<<n<<": "<<r<<endl

long long nodes[110];

int main(){
  int t;
  cin >> t;
  nodes[0]=1;
  for(int i=1;i<=t;i++){
    int k, c, s;
    cin >> k >> c >> s;
    for(int j=1;j<102;j++){
      nodes[j] = k*nodes[j-1];
    }

    if(k>c*s){
      ANS(i,"IMPOSSIBLE");
      continue;
    }
    int next=0;

    bool done = false;
    vector<long long> blocks;
    for(int j=0;(j<s) && !done;j++){
      long long b=0;
      for(int d=c-1; d>=0; d--){
        if(done){
          next = 0;
        }
        DB(b) DB(d) DB(nodes[d]) DBL(next)
        b+=nodes[d]*next;
        DBL(b)
        next++;
        if(next >= k){
          next=0;
          done = true;
        }
      }
      b++;
      blocks.push_back(b);
    }
    cout<<"Case #"<<i<<":";
    for(int i=0;i<blocks.size();i++){
      cout<<" "<<blocks[i];
    }
    cout<<endl;
  }
}
