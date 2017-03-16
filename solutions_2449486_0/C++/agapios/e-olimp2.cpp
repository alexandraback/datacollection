#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <memory.h>
#include <string.h>
//#include <assert.h>
using namespace std;

#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define inf 1000000000
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define pi 2*acos(0.0)
#define mp(a,b) make_pair((a), (b))
#define X first
#define Y second

typedef vector<int> vint;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int n,m,k,t,x,cur;
bool ans;
int a[105][105];
int maxv[105], maxh[105];
int ogv[105], ogh[105];

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &t);
	FOR(tt,1,t){
		ans = 1;
		memset(ogv,63,sizeof(ogv));
		memset(ogh,63,sizeof(ogh));
		memset(maxv,0,sizeof(maxv));
		memset(maxh,0,sizeof(maxh));
		scanf("%d %d", &n, &m);
		FOR(i,1,n){
			FOR(j,1,m){
				scanf("%d", &a[i][j]);
				maxv[j] = max(maxv[j], a[i][j]);
				maxh[i] = max(maxh[i], a[i][j]);
			}
		}

		FOR(i,1,n){
			FOR(j,1,m){
				if(a[i][j] < maxh[i]){
					ogv[j] = min(ogv[j], a[i][j]);
					if(ogv[j] < maxv[j])
						ans = 0;					
				}
				if(a[i][j] < maxv[j]){
					ogh[i] = min(ogh[i], a[i][j]);
					if(ogh[i] < maxh[i])
						ans = 0;					
				}
			}
		}

		printf("Case #%d: %s\n", tt, (ans)?"YES":"NO");
	}


	return 0;
}