#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define li        long long int
#define rep(i,to) for(li i=0;i<((li)(to));++i)
#define pb        push_back
#define sz(v)     ((li)(v).size())
#define bit(n)    (1ll<<(li)(n))
#define all(vec)  (vec).begin(),(vec).end()
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MP        make_pair
#define F         first
#define S         second

#define MAX  100500
double a[MAX];

int main(){
	li T;
	cin >> T;
	rep(turn, T){
		li n, m;
		cin >> m >> n;
		rep(i, m) cin >> a[i];
		double best = 1 + n + 1;
		double pro = 1.0;
		rep(i, m){
			pro *= a[i];
			double sum = m - (i + 1);
			sum += n - (i + 1);
			sum++;
			sum += (n + 1) * (1.0 - pro);
			best = min(best, sum);
		}
		printf("Case #%lld: %0.20lf\n", turn + 1, best);
	}
}
