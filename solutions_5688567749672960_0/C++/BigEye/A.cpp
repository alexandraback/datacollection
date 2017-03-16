#include <iostream>
#include <queue>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define f(i,a,b) for(int i=(a);i<(b);++i)
#define fe(i,a,b) for(int i=(a);i<=(b);++i)
#define r(i,n) f(i,0,n)
#define re(i,n) fe(i,0,n)
#define fsz(i,a,v) f(i,a,sz(v))
#define rsz(i,v) r(i,sz(v))
#define all(v) v.begin(),v.end()
#define set(x,with) memset(x,with,sizeof(x))
#define same(a,b) (fabs((a)-(b))<0.0000001)
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define MAXN (1000010)
int tn;
int n;
int a[MAXN];
queue<int> q;

int rev(int x) {
  int y = 0;
  while (x != 0) {
    y = y * 10 + (x % 10);
    x /= 10;
  }
  return y;
}

int main(int argc, char *argv[]) {
  cin >> tn;
  a[1] = 1;
  q.push(1);
  while(!q.empty()) {
    int now = q.front(); q.pop();

    if (now <= MAXN && a[now+1] == 0) {
      a[now+1] = a[now] + 1;
      q.push(now + 1);
    }

    int next = rev(now);
    if (next <= MAXN && a[next] == 0) {
      a[next] = a[now] + 1;
      q.push(next);
    }
  }

  fe(ti,1,tn) {
    cin >> n;
    cout << "Case #" << ti << ": " << a[n] << endl;
  }    
  
  return 0;
}
