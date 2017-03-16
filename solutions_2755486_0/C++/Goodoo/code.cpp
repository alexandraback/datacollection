#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <cmath>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <memory.h>

using namespace std;

#define PI 3.14159265359
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define OPENFILE
#define FILENAME "C-small-attempt1"

typedef long long ll;
int wall[1200]; //-300~300
int wall2[1200]; //-300~300

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout); //redirects standard output
#endif
	int T;
	cin >> T;
	REP(t,T)
	{
		int N;
		cin >> N;
		int d[12], n[12], w[12], e[12], s[12], dd[12], dp[12], ds[12];
		REP(i,N)
		{
			cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i]
					>> ds[i];
		}
		memset(wall, 0, sizeof(wall));
		memset(wall2, 0, sizeof(wall2));
		priority_queue<pair<int, vector<int> > > attack;
		REP(i,N)
		{
			int w2 = w[i], e2 = e[i], s2 = s[i], d2 = d[i];
			REP(j,n[i])
			{
				vector<int> v;
				v.push_back(w2);
				v.push_back(e2);
				v.push_back(s2);
				attack.push(make_pair(-d2, v));
				d2 += dd[i];
				s2 += ds[i];
				w2 += dp[i];
				e2 += dp[i];
			}
		}
		int res = 0;
		while (!attack.empty()) {
			pair<int, vector<int> > att = attack.top();
			attack.pop();
			int d3 = att.first;
			vector<int> v2 = att.second;
			bool flag=0;
			for (int i = v2[0]*2-1; i <= v2[1]*2-1; i++) {

				if (v2[2] > wall[i + 600]) {
					if(flag==0)res++;
					flag=1;
					wall2[i + 600] = v2[2];
				}
			}

			if(attack.empty())break;
			att = attack.top();
			while (att.first == d3) {
				vector<int> v2 = att.second;
				bool flag=0;
				for (int i = v2[0]*2-1; i <= v2[1]*2-1; i++) {

					if (v2[2] > wall[i + 600]) {
						if(flag==0)res++;
						flag=1;
						wall2[i + 600] = v2[2]>wall2[i + 600]? v2[2]:wall2[i + 600];
					}
				}
				attack.pop();
				if(attack.empty())break;
				att=attack.top();
			}
			REP(i,1200){
				wall[i]=wall2[i];
			}
		}
		printf("Case #%d: %d\n", t + 1,res);
		cerr << t + 1 << endl;
		fflush(stdout);
	}
}
