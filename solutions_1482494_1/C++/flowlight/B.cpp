#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cctype>
#include <set>
#include <fstream>
#include <cmath>
using namespace std;

#define rep(i, n) for(int i = 0; i< n; i++)
#define rep2(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;
const double EPS = 1e-10;

int c[1010];
int a[1010];
int b[1010];

int main(){
  int T, N;
  cin >> T;
  rep(t, T){
    cin >> N;
    rep(i, N)  cin >> a[i] >> b[i];
    int res = 0;
    int star = 0;
    memset(c, 0, sizeof(c));
    while(star < 2 * N){
      int one = -1;
      int best = -1;
      int two = -1;
      rep(i, N){
	if(c[i] <= 1 && b[i] <= star){
	  two = i;
	}
	if(c[i] == 0 && a[i] <= star && b[i] > best){
	  one = i;
	  best = b[i];
	}
      }
      res++;
      if(two != -1){
	star += 2 - c[two];
	c[two] = 2;
      }else if(one != -1){
	star++;
	c[one] = 1;
      }else{
	break;
      }
    }
    cout << "Case #" << t + 1 << ": ";
    if(star < 2 * N) cout << "Too Bad" << endl;
    else cout << res << endl;
  }
  return 0;
}
