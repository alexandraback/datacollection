#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORR(i,a,b) for (int i=a; i>=b; i--)
#define pi M_PI

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;

int main(void) {
	ifstream ifs("input.txt");
	FILE *fp;
	fp = fopen("out.txt","w");
	int t;
	ifs >> t;
	REP(cas,t){		
		fprintf(fp,"Case #%d: ",cas+1);
		int b;
		ll m;
		ifs >> b >> m;

		ll x = 1;
		REP(i,b-2) x*=2;

		if (m>x){
			fprintf(fp,"IMPOSSIBLE\n");
			continue;
		}

		fprintf(fp,"POSSIBLE\n");

		int a[50][50] = {};
		REP(i,b){
			FOR(j,i+1,b-2){
				a[i][j] = 1;
			}
		}
		a[0][b-1] = 1;

		m--;
		FOR(j,1,b-2){
			a[j][b-1] = (m & 1);
			m = m>>1;
		}

		REP(i,b){
			REP(j,b){
				fprintf(fp,"%d",a[i][j]);
			}
			fprintf(fp,"\n");
		}
	}

	return 0;
}