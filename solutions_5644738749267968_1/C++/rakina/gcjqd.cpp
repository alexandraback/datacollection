#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MAXN 1005
#define INF 1000000
#define S 0
#define T m+n+1
using namespace std;
int t,n,x,y, a[MAXN], b[MAXN];
int war(int posa, int posb){
	if (posb >= n)
		return 0;
	if (a[posa] > b[posb])
		return 1 + war(posa,posb+1);
	else return war(posa+1,posb+1);
}

int deceit(int posa, int posb){
	if (posa >= n)
		return 0;
	int ret;
	if (a[posa] > b[posb]){
		ret = 1 + deceit(posa+1,posb+1);
	}
	else ret= deceit(posa+1,posb);
	//cout << posa << " "<< posb << " -> " << a[posa] << " " << b[posb] << " RET = " << ret << endl;
	return ret;
}

int main(){
	scanf("%d",&t);
	for (int tc = 1; tc <= t; ++tc){
		scanf("%d",&n);
		for (int i =0; i < n; ++i){
			double tmp;
			scanf("%lf",&tmp);
			x = (int) (tmp*100000);
			a[i] = x;
		}
		for (int i =0; i < n; ++i){
			double tmp;
			scanf("%lf",&tmp);
			x = (int) (tmp*100000);
			b[i] = x;
		}
		sort(a,a+n); sort(b,b+n);
		//for (int i =0; i < n; ++i)
		//	cout << i <<" -> " << a[i] <<" " << b[i] << endl;
		printf("Case #%d: %d %d\n",tc,((b[n-1]==100000)?deceit(1,0):deceit(0,0)),war(0,0));
	}
}