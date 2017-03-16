#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>
#include <fstream>

using namespace std;

#define DEBUG(x) cout<< #x << ':' << x << endl
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,n-1)
#define FORIT(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(), (a).end()
#define ZERO(a) memset(a, 0, sizeof(a))
#define PB push_back
#define MP make_pair
#define LEN(a) (int)(sizeof(a) / sizeof(a[0]))
#define abs(x) (((x)^((x)>>31))-((x)>>31))
const int inf = ~0u>>1;

typedef long long ll;

int main()
{
	int T;
	cin>>T;
	int r,t;
	FOR(ii,1,T){
		cin>>r>>t;
		int cnt=0;
		double sum = 0;
		while(true){
			int n = 2*cnt+1;
			sum += 2.0*r+n*n-(n-1)*(n-1);
			if (sum > t) break;
			cnt++;
		}
		printf("Case #%d: %d\n",ii,cnt);
	}
	return 0;
}
