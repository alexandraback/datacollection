#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

typedef long long LL;
#define REP(i,e) for (int (i) = 0; (i) < (e); ++(i))
#define foreach(__my_iterator,__my_object) for (typeof((__my_object).begin()) __my_iterator = (__my_object).begin(); __my_iterator!= (__my_object).end(); __my_iterator++)

int N, M, H;
int ce[101][101];
int fl[101][101];
double dist[101][101];
double EPS = 0.00000001;
int dx[] = {1, -1, 0, 0};
int dy[] = {0,  0, -1, 1};

const double INF = (double)(1 << 30);

void solve(){
  //  cout << "debug" << endl;
  priority_queue <pair <double, pair <int, int > > > q;


  q.push(make_pair(0.0, make_pair(0, 0)));

  while(! q.empty() ){
    double time = -q.top().first;
    int x = q.top().second.first; int y = q.top().second.second;
    q.pop();
    if(dist[y][x] < time + EPS) continue;
    dist[y][x] = time;

    int ceil = ce[y][x];
    int flor = fl[y][x];
    double curH = max(0.0, H - time * 10);

    

    REP(i, 4){
      int xx = x + dx[i]; int yy = y + dy[i];
      if(xx < 0 || xx >= M) continue;
      if(yy < 0 || yy >= N) continue;
      int ceil2 = ce[yy][xx]; int flor2 = fl[yy][xx];

      if(flor  > ceil2 - 50) continue;
      if(flor2 > ceil2 - 50) continue;
      if(ceil -50 < flor2) continue;


      double tt = time;
      if(curH > ceil2-50) tt += (curH - (ceil2 - 50)) / 10.0;

      //      printf("tt=%lf height=%lf,flr=%d \n", tt, H - tt*10.0, flor);
      if(tt < EPS){
	q.push(make_pair ( -0.0, make_pair(xx, yy)));
      }
      else if(H - tt*10 < flor + 20){
	q.push(make_pair ( - (tt+10), make_pair(xx, yy))) ;
      }
      else{
	q.push(make_pair (-(tt+1), make_pair(xx, yy)));
	//	tt += (H - tt*10 - (flor2 + 20)) / 10.0;
	//	q.push(make_pair (-(tt+1), make_pair(xx, yy)));	
      }
    }
  }

  printf("%lf\n", dist[N-1][M-1]);
}

int main(){
  int T;
  cin >> T; 

  REP(i, T){
    cin >> H >> N >> M;
    //    cout << N << " " << M << endl;
    REP(y, N) REP(x, M) cin >>ce[y][x];
    REP(y, N) REP(x, M) cin >>fl[y][x];
    REP(y, N) REP(x, M) dist[y][x] = INF;
    printf("Case #%d: ", i+1);
    solve();
  }
  return 0;
}
/*
"4
200 1 2
250 233
180 100
100 3 3
500 500 500
500 500 600
500 140 1000
10 10 10
10 10 490
10 10 10
100 3 3
500 100 500
100 100 500
500 500 500
10 10 10
10 10 10
10 10 10
100 2 2
1000 1000
1000 1000
100 900
900 100" | ./a.out 
*/
