#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <string>
#define INF 2000000000
#define ii pair<int, int>
#define LL long long

using namespace std;

int n,m;
LL box[105],tipebox[105],toy[105],tipetoy[105],memo[105][105];

LL f(int posBox, int posToy) {
	if (posBox==n || posToy==m) return 0;
	//if (memo[posBox][posToy]!=-1) return memo[posBox][posToy];
	LL res;
	if (tipebox[posBox]==tipetoy[posToy]) {
		LL tambah=min(box[posBox],toy[posToy]);
		box[posBox]-=tambah;
		toy[posToy]-=tambah;
		res=max(f(posBox+1,posToy),f(posBox,posToy+1))+tambah;
		box[posBox]+=tambah;
		toy[posToy]+=tambah;
	} else {
		res=max(f(posBox+1,posToy),f(posBox,posToy+1));
	}
	return memo[posBox][posToy]=res;
}

int main() {
	int ntc;
	scanf("%d",&ntc);
	for (int tc=1;tc<=ntc;tc++) {
		scanf("%d %d",&n,&m);
		for (int i=0;i<n;i++) {
			scanf("%lld %lld",&box[i],&tipebox[i]);	
		}
		for (int i=0;i<m;i++) {
			scanf("%lld %lld",&toy[i],&tipetoy[i]);	
		}
		for (int i=0;i<=n;i++) {
			for (int j=0;j<=m;j++) {
				memo[i][j]=-1LL;	
			}	
		}
		printf("Case #%d: %lld\n",tc,f(0,0));
	}
    return 0;
}
