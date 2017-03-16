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
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define pii pair<int, int>
using namespace std;
const int N = int(2222);
int T,n,a[N];
int ans = N;         

int main () {
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		ans = N;
		int res;
		for(int i=1;i<=200;i++){
			res = i;
			for(int j=1;j<=n;j++){
				res += (a[j] + i - 1) / i;
			}
			ans = min(ans,res - n);
		}
		printf("Case #%d: %d\n",t,ans);
	}
return 0;
}