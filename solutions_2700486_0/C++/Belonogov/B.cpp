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

const int maxn = 2020;
const int inf = 1e9;
const long double eps = 1e-9;

long double a[maxn][maxn];
int cnt = 0;
int good = 0;

int solve(int n){
    return 2 * n * n + 3 * n + 1;
}

void rec(int k, int d, int x, int y, int r){
    if (k == 0){
	cnt++;
	good += (x >= r);
	return;
    }
    if (x + 1 <= d)
	rec(k - 1, d, x + 1, y, r);
    if (y + 1 <= d)
	rec(k - 1, d, x, y + 1, r);
}

long double stupid(int k, int d, int y){
    cnt = 0; 
    good = 0;
    rec(k, d, 0, 0, y);
    return 1.0 * good / cnt;
}

int main(){
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int n, t, x, y, d, k, q1, q2, mx;
    long double sum, q;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
	scanf("%d%d%d", &n, &x, &y);
	printf("Case #%d: ", tt + 1);
	
	d = (abs(x) + y) / 2;
	int cnt1 = solve(d);
	int cnt0 = solve(d - 1);
	
	if (n >= cnt1){
	    printf("1.0\n");
	    continue;
	}
	if (n <= cnt0){
	    printf("0.0\n");
	    continue;
	}
	if (x == 0){
	    if (cnt1 == n)
		printf("1.0\n");
	    else
		printf("0.0\n");
	    continue;
	}
	k = n - cnt0;
	memset(a, 0, sizeof(a));
	a[0][0] = 1;	
// 	epr("k %d\n", k);
	mx = d * 2;
	for(int i = 0; i < k; i++){
	    for(int j = 0; j <= i; j++){
		q1 = j;
		q2 = i - j;
		if (q1 + 1 <= mx)
		    a[i + 1][q1 + 1] += a[i][j];
		if (q2 + 1 <= mx)
		    a[i + 1][q1] += a[i][j];		
	    }
	}

	q = 0;
	sum = 0;
	for(int i = 0; i <= k; i++){
	    sum += a[k][i];
	    if (i >= y + 1)
		q += a[k][i];
	}
	cout.precision(15);
 	cout << fixed << q / sum << "\n";
	long double answer = stupid(k, mx, y + 1);
	assert(abs(q / sum - answer) < eps);
	
    }
 
    
    return 0;
}