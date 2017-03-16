#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <math.h>
using namespace std;

//trocar para 0 para desabilitar output
#if 1
#define DEBUG(x) cout << x << endl
#define PAUSE() cin.get(); cin.get()
#else
#define DEBUG(x)
#define PAUSE()
#endif

#define TRACE(x) DEBUG(#x << " = " << x)
#define DEBUGS() DEBUG("***************************")
#define MAX 101

typedef long long llong;

typedef struct point{
  int x, y, step;
  string s;
}point;

bool operator<(const point &a, const point &b){
  if (a.x == b.x){
    //if (a.y == b.y) return a.s[a.s.length()-1] < b.s[b.s.length()-1];
    return a.y < b.y;
  }
  return a.x < b.x;
}

point nxtPos(point &a, int i){
  point res;
  res = a;
  if (i == 0){
    res.s += 'S';
    res.y -= res.step;
  }
  else if (i == 1){
    res.s += 'E';
    res.x += res.step;
  }
  else if (i == 2){
    res.s += 'N';
    res.y += res.step;
  }
  else{
    res.s += 'W';
    res.x -= res.step;
  }
  ++res.step;
  return res;
}

set<point> mark;

string bfs(int x, int y){
  queue<point> q;
  point a;
  a.x = a.y = 0;
  a.step = 1;
  a.s = "X";
  q.push(a);
  while (!q.empty()){
    point actual = q.front();
    q.pop();
    if (mark.find(actual) != mark.end()) continue;
    if (actual.x == x && actual.y == y) return actual.s.substr(1);
    mark.insert(actual);
    for (int i = 0; i < 4; ++i){
      point aux = nxtPos(actual, i);
      if (aux.x < -MAX || aux.x > MAX || aux.y < -MAX || aux.y > MAX) continue;
      if (mark.find(aux) == mark.end())
	q.push(aux);
    }
  }
  return "NONE";
}

int main(){
  int t, cases = 0;
  cin >> t;
  while (t--){
    int x, y;
    cin >> x >> y;
    mark.clear();
    cout << "Case #" << ++cases << ": " << bfs(x, y) << endl;
  }
  return 0;
}
