#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1e5;
const int inf = 1e9;


int a[maxn];

int main(){
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int n, t, k, d, ans, ans1;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
	scanf("%d%d", &k, &n);

	printf("Case #%d: ", tt + 1);
	
	for(int i = 0; i < n; i++)
	    scanf("%d", &a[i]);
	if (k == 1){ 
	    printf("%d\n", n); continue;
	}
	sort(a, a + n);
	ans = n;
	for(int i = 0; i <= n; i++){
	    ans1 = n - i;
	    d = k;
	    for(int j = 0; j < i; j++){
		for(; d <= a[j]; d += d - 1, ans1++);
		d += a[j];
	    }
	    ans = min(ans, ans1);
	}
	printf("%d\n", ans);
    }
    
    return 0;
}