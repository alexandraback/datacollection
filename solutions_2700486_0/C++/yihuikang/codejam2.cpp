#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

#define pb push_back
#define mp make_pair
#define repeat(t) for (int asdfg=0; asdfg < (t); asdfg++)
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

using namespace std;

typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

const int N=1000000;

int a[10000];
double dp[1000][1000];
double get(int s,int lim,int k,int l,int r) {
	// printf("get: %d %d %d %d %d\n",s,lim,k,l,r);
	memset(dp,0,sizeof(dp));
	dp[0][0]=1.0;
	for (int c=0; c<s; c++) {
		for (int i=0; i<=lim && i<=c; i++) {
			int j=c-i;
			// printf("dp %d %d : %.4f\n", i,j,dp[i][j]);
			if (j+1>lim) { dp[i+1][j]+=dp[i][j]; }
			else if (i+1>lim) dp[i][j+1]+=dp[i][j];
			else {
				dp[i+1][j]+=dp[i][j]*0.5;
				dp[i][j+1]+=dp[i][j]*0.5;
			}
		}
	}
	// for (int i=0; i<=lim; i++)
		// for (int j=0; j<=lim; j++) printf("dp %d %d : %.4f\n", i,j,dp[i][j]);
	double ret=0;
	for (int i=k; i<=lim; i++) {
		int j=s-i;
		if (j>=0) ret+=dp[i][j];
	}
	return ret;
}

int main()
{
	freopen("B-small-attempt4.in","r",stdin);
	freopen("b4.out","w",stdout);

	a[0]=0;
	for (int s=0,i=1; s<=N; i++) {
		s+=(i-1)*4+1;
		a[i]=s;
	}

	int cas,x,y,n;
	cin >> cas;
	for (int T=1; T<=cas; T++) {
		cin >> n >> x >> y;
		printf("Case #%d: ",T);
		int c=abs(x)+abs(y);
		if ((x&1) != (y&1)) { puts("0.0"); continue; }
		int k=1;
		while (n>a[k]) k++; // cur levelb
		// printf("k=%d n=%d a[k]=%d\n", k,n,a[k]);
		if (k > c) { puts("1.0"); continue; }
		if (k < c) { puts("0.0"); continue; }
		// int w=a[k]-a[k-1]; // level need
		int g=n-a[k-1]; // level have
		int h=2*k-1; // level hight
		// if (g>=h+y) { puts("1.0"); continue; }
		// if (g<y+1) { puts("0.0"); continue; }
		if (y+1==h && n!=a[k]) { puts("0.0"); continue; }
		if (n==a[k]) { puts("1.0"); continue; }
		int r=max(h-1,g);
		int l=g-r;
		printf("%.8f\n", get(g,h-1,y+1,l,r));
	}
	return 0;
}
