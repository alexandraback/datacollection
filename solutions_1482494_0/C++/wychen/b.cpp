#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOREACH(i,c) for(typeof(c.begin()) i=(c).begin();i!=(c).end();++i)
#define REP(i,n) FOR(i,0,n)

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

#define D 0

void solve(bool skip)
{
	int N;
	cin >> N;
	vector<int> a(N), b(N), star(N);
	REP(i,N){
		cin >> a[i] >> b[i];
	}
	if(skip) return;

	int steps = 0, stars = 0;
	while(1) {
		// get two stars, with lowest taken stars
		int best = 3, besti= -1;
		REP(i, N) {
			if(stars >= b[i] && star[i]!=2) {
				if(star[i] <= best) {
					best = star[i];
					besti = i;
				}
			}
		}
		if(besti != -1) {
			stars += (2-star[besti]);
			star[besti] = 2;
			steps++;
			if(D) cerr << "2* from " << besti << ", star=" << stars << endl;
			if(stars==N*2) break;
			continue;
		}
		// get one star, with largest b
		best = 0, besti= -1;
		REP(i, N) {
			if(stars >= a[i] && star[i]==0) {
				if(b[i] >= best) {
					best = b[i];
					besti = i;
				}
			}
		}
		if(besti != -1) {
			stars +=1;
			star[besti] = 1;
			steps++;
			if(D) cerr << "1* from " << besti << ", star=" << stars << endl;
			if(stars==N*2) break;
			continue;
		}
		break;
	}
	if(stars==N*2)
		cout << steps;
	else
		cout << "Too Bad";
}

int main(int argc, char **argv)
{
  int T;
  cin >> T;
  int pick = 0;
  if(argc==2) pick = atoi(argv[1]);
  for(int i=0;i<T;i++) {
    bool skip = pick && (pick!=i+1);
    if(!skip) {
      cout << "Case #" << (i+1) << ": ";
    }
    solve(skip);
    if(!skip) {
      cout << endl;
    }
  }
}
