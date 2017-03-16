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
const int N = 105;

int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int tt, a, b, k, i, j, tot;
	scanf("%d",&tt);
	for(int cas = 1; cas <= tt; ++cas){
		printf("Case #%d: ", cas);
		scanf("%d%d%d",&a,&b,&k);
		tot=0;
		for(i=0;i<a;++i)
		for(j=0;j<b;++j) if((i&j)<k) tot++;
		printf("%d\n", tot);
	}
	return 0;
}
