#include <map>
#include <set>
#include <queue>
#include <ctime>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define bit(k) (1<<(k))
using namespace std;

#define all(a) a.begin(),a.end()
#define clr(a) memset(a,0,sizeof(a))
#define fill(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VII;

const double eps = 1e-8;
const double pi = acos(-1.0);

int A, B, C;
long long f[32][2][2][2];
long long calc(int u, int limitA, int limitB, int limitC){
	if(u==-1) return 1;
	if(f[u][limitA][limitB][limitC]!=-1) return f[u][limitA][limitB][limitC];
	long long res = 0;
	int ra, rb, ta, tb, tc;
	if(!limitA) ra=1, ta=0;
	else if(bit(u)&A) ra=1, ta=1;
	else ra = 0, ta=0;
	if(!limitB) rb=1, tb=0;
	else if (bit(u)&B) rb=1, tb=1;
	else rb=0, tb=0;
	if(limitC && (bit(u)&C)) tc = 1;
	else tc=0;

	res += calc(u-1, limitA^ta, limitB^tb, limitC^tc);

	if(rb==1)
	res += calc(u-1, limitA^ta, limitB, limitC^tc);

	if(ra==1)
	res += calc(u-1, limitA, limitB^tb, limitC^tc);

	if(ra==1 && rb==1)
	if(!limitC || (bit(u)&C)){
		res += calc(u-1, limitA, limitB, limitC);
	}
	return f[u][limitA][limitB][limitC]=res;
}

int main(){
	freopen("B.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tt;
	scanf("%d",&tt);
	for(int cas = 1; cas <= tt; ++cas){
		printf("Case #%d: ", cas);
		scanf("%d%d%d",&A,&B,&C);
		--A, --B, --C;
		memset(f,-1,sizeof(f));
		cout << calc(31, 1, 1, 1) << endl;
	}

    return 0;
}

