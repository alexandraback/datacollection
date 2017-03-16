#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const string MAX_ZIP = "99999999999999999999999999999999999999999999999999";
int N, M;
int start, finish;
vector<string> zip;

string dfs(int city, int visited, int outbound, vector<vector<bool>>& edges, string mzip, string minimum){
  if(city == start && visited == finish){
	return mzip;
  }

  for(int to=0;to<N;++to){
	if(edges[city][to]){
	  //outbound
	  int out_flag = 0;
	  if(edges[to][city]){
		if(outbound & (1 << to)){
		  continue;
		}
		else{
		  out_flag = (1 << to);
		}
	  }

	  int mask = 1 << to;
	  edges[city][to] = false;
	  if(visited & mask){
	    minimum = min(dfs(to, visited, (outbound | out_flag), edges, mzip, minimum), minimum);
	  }
	  else{
		string s = mzip + zip[to];
		for(;s.length()!=N*5;){
		  s += "0";
		}
		if(s <= minimum){
		  minimum = min(dfs(to, (visited|mask), (outbound | out_flag), edges, mzip+zip[to], minimum), minimum);
		}
	  }
	  edges[city][to] = true;
	}
  }
  return minimum;
}

int main(){
  int TestCase;
  cin >> TestCase;

  for(int test=1;test<=TestCase;++test){
	cin >> N >> M;
	zip.resize(N);
	vector<vector<bool>> edge(N, vector<bool>(N, false));
	for(int i=0;i<N;++i){
	  cin >> zip[i];
	}
	for(int i=0;i<M;++i){
	  int x, y;
	  cin >> x >> y;
	  edge[x-1][y-1] = true;
	  edge[y-1][x-1] = true;
	}

	string res = MAX_ZIP;
	finish = (1<<N) - 1;
	string m = MAX_ZIP;
	int id = -1;
	vector<bool> searched(N, false);
	for(int i=0;i<N;++i){
	  for(int j=0;j<N;++j){
		if(!searched[j] && m > zip[j]){
		  m = zip[j];
		  id = j;
		}
	  }
	  searched[id] = true;
	  start = id;
	  res = min(res, dfs(id, (1<<id), 0, edge, zip[id], MAX_ZIP));
	  if(res != MAX_ZIP) break;
	}

	cout << "Case #" << test << ": " << res << endl;
  }

  return 0;
}
