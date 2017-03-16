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

#define eps (1e-6)
double INF = 1e100;

#define D 1

void solve(bool skip)
{
	int N;
	cin >> N;
	vector<char> C(N);
	vector<int> S(N);
	vector<double> P(N);
	REP(i, N) {
		cin >> C[i] >> S[i] >> P[i];
		if(D) cerr << C[i] << " " << S[i] << " " << P[i] << endl;
		C[i] = (C[i]=='R');
	}
	if(skip) return;

	double alltime = 0;
	while(1) {
		double mintime = INF;
		int a = -1, b = -1; // a is faster
		REP(i, N) {
			FOR(j, i, N) {
				if( C[i]!=C[j] ) continue;
				if( S[i]==S[j] ) continue;
				if( (S[i]-S[j]) * (P[i]-P[j]) > 0) continue;
				assert(fabs(P[i]-P[j]) >= 5-eps);
				double dt = (fabs(P[i]-P[j])-5)/fabs(S[i]-S[j]);
				assert(dt>-eps);
				if(dt < mintime) {
					mintime = dt;
					if(S[i] > S[j]) {
						a = i;
						b = j;
					} else {
						a = j;
						b = i;
					}
				}
			}
		}
		if(mintime == INF) {
			cout << "Possible";
			break;
		}
		if (D) {
			cerr << "mintime = " << mintime << ", (a,b) = " << a << ", " << b << endl;
		}
		REP(i, N) {
			P[i] += S[i] * mintime;
		}
		alltime += mintime;
		// try switching a
		bool canswitcha = true;
		REP(i, N) {
			if(a==i) continue;
			if(C[a]==C[i]) continue;
			if( fabs(P[a]-P[i]) < 5-eps ) {
				canswitcha = false;
			}
			if( (P[i]-P[a]) < 5+eps && (P[i]-P[a]) > 5-eps) {
				if(S[i] < S[a])
					canswitcha = false;
				if(D) cerr << "deadlock a with " << i << endl;
			}
		}
		// try switching b
		bool canswitchb = true;
		REP(i, N) {
			if(b==i) continue;
			if(C[b]==C[i]) continue;
			if( fabs(P[b]-P[i]) < 5-eps ) {
				canswitchb = false;
			}
			if( (P[b]-P[i]) < 5+eps && (P[b]-P[i]) > 5-eps) {
				if(S[i] > S[b])
					canswitchb = false;
				if(D) cerr << "deadlock b with " << i << endl;
			}
		}
		if(canswitcha) {
			C[a] = !C[a];
			if(D) cerr << "switch a" << endl;
		} else if(canswitchb) {
			C[b] = !C[b];
			if(D) cerr << "switch b" << endl;
		} else {
			cout << alltime;
			break;
		}
	}
}

int main(int argc, char **argv)
{
  int T;
  cin >> T;
  int pick = 0;
  if(argc==2) pick = atoi(argv[1]);
  cout.precision(10);
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
