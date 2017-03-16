#include <algorithm>
#include <cmath>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
using namespace std;


typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define REP(i,n) for(int i=0;i<(int)n;i++) 
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++) 
#define ALL(c) (c).begin(),(c).end() 

int solve() {
    int A;
    int N;
    cin>>A>>N;
    vector<int> input;
    for(int i=0; i<N; i++) {
        int p;
        cin>>p;
        input.push_back(p);
    }
    sort(ALL(input));
    
    if(A==1) return N;
    
    int ans = N;
    int cur = A;
    int iter = 0;
    int cnt = 0;
    int sz = input.size();
    while(iter<sz) {
        int next = input[iter];
        ans = min(ans, sz-iter+cnt );
        while(next>=cur) cur += cur-1, cnt++;
        cur += next;
        
        iter++;
    }
    ans = min(ans, cnt);
    
    return ans;
}


int main() {
  int t;
  cin>>t;
  for(int i=1; i<=t; i++) {
    cout<<"Case #"<<i<<": "<<solve()<<endl;
  }
  return 0;
}


