#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = 3000, mod = int(1e9)  + 7;
int T;
int n,c[N+10];
int a[N],x;

int main () {
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for(int i=1;i<=2*n-1;i++){
			for(int i=1;i<=n;i++){
				scanf("%d",&x);
				c[x]++;
			}
		}
		int m = 0;
		for(int i=1;i<=N;i++){
			if(c[i] & 1) {
				printf("%d ",i);
				m++;
			}
			c[i] = 0;
		}
		if(m != n) cerr << "BAD\n";
		puts("");
	}

return 0;
}