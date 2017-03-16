#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> rev;
vector<int> dist,from;

int reverse(int n) {
  queue<int> d;
  while (n > 0) {
    d.push(n%10);
    n /= 10;
  }
  int res = 0;
  while (d.empty()==false) {
    res = res * 10 + d.front();
    d.pop();
  }
  return res;

}

void gen(int max_n) {
  rev.resize(max_n+1);
  dist = rev;
  for (int i = 1;i <= max_n;i++) {
    int tmp = reverse(i);
    //cout <<i << ": " << reverse(i) << endl;
    rev[i] = tmp;
  }
}


queue<int> q;

void bfs(int target) {
  while(q.empty() == false) {
    int curr = q.front(); q.pop();
    //just next
    int next = curr+1;
    if (next <= 1000000 && dist[next] == 0) {
      //printf(" at %d go to %d\n",curr,next);
      dist[next] = dist[curr]+1;
      //from[next] = curr;
      q.push(next);
    }
    next = rev[curr];
    if (next == 1) continue;
    if (next <= 1000000 && dist[next] == 0) {
      //printf(" at %d go to %d\n",curr,next);
      dist[next] = dist[curr]+1;
      //from[next] = curr;
      q.push(next);
    }
    if (curr == target) break;
    //reverse
  }
}


//void trace(int n) {
//  if (n == 1) {
//    printf("1 ");
//  } else {
//    trace(from[n]);
//    printf("%d ",n);
//  }
//
//}

int main() {
  int n;
  int k = 10000000;
  gen(k);

  int T;
  cin >> T;

  dist[1] = 1;
  q.push(1);
  for (int i = 1;i <= T;i++) {
    cin >> n;
    if (dist[n] == 0)
      bfs(n);
    //trace(n);
    printf("Case #%d: %d\n",i,dist[n]);
  }

}
