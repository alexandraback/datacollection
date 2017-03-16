#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>
#include <queue>

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define gp(ans) {cout << "Case #" << ((test)+1) << ": " << (ans) << endl;}

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;

int main () {
  int test, T;
	
  cin >> T;
  REP (test, T) {
		int i,j,m,n;
		cin >> n;
		vector< vi > v;
		REP(i,n){
			cin >> m;
			vi w;
			REP(j,m){
				int t;
				cin >> t;
				--t;
				w.push_back(t);
			}
			v.push_back(w);
		}
		
		bool find = false;
		REP(i,n){
			//start from n
			int memo[1001] = {0};
			queue<int> q;
			q.push(i);
			while(!q.empty() && !find){
				int t = q.front();
				q.pop();
				for(int j=0; j<v[t].size(); j++){
					int next = v[t][j];
					//printf("find next %d to %d\n", t, next);
					if(memo[next] == 1){
						find = true;
						break;
					}
					memo[next] = 1;
					q.push(next);
				}
			}
			if(find){
				break;
			}
		}
		if(find) {gp("Yes"); }
		else { gp("No"); }
  }
  return 0;
}

