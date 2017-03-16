//In the Name of God
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <fstream>

using namespace std;
ifstream fin("B-small-attempt2.in");
ofstream fout("B-small-attempt2.out");
typedef long long LL;
typedef pair <LL , LL> pii;

map <pii , LL> best;
map <pii , bool> mark;
pii move[4] = {pii(-1 , 0) , pii(0 , -1) , pii(1 , 0) , pii(0 , 1)};

void bfs(pii st){
  best[st] = 1;
  mark[st] = true;
  queue <pii> q;
  q.push(st);
  while(q.size()){
    pii v = q.front();
    q.pop();
    if(best[v] > 100)
      continue;
    for(LL k = 0 ; k < 4 ; k++){
      pii u = v;
      u.first += move[k].first * best[v];
      u.second += move[k].second * best[v];
      if(!mark[u] || best[u] > best[v] + 1){
	best[u] = best[v] + 1;
	mark[u] = true;
	q.push(u);
      }
    }
  }
}

int main(){
  int t , T , x , y;
  bool sw , sw1;
  fin >> t;
  T = 1;
  while(t--){
    fin >> x >> y;
    sw = (x > 0);
    sw1 = (y > 0);
    fout << "Case #" << T << ": ";
    T++;
    for(int i = 0 ; i < abs(x) ; i++)
      if(sw)
	fout << "WE";
      else
	fout << "EW";
    for(int i = 0 ; i < abs(y) ; i++)
      if(sw1)
	fout << "SN";
      else
	fout << "NS";
    fout << endl;
  }
  return 0;
}
