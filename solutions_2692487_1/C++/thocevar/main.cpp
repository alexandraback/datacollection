#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

#define all(c) (c).begin(),(c).end()
#define present(c,x) (find(c.begin(),c.end(),x) != (c).end())
#define pb push_back
#define mp make_pair
#define INIT(v,x) memset(v,x,sizeof(v))
#define REP(i,n) for (int i=0;i<(int)(n);i++)
#define traverse(v,it) for (typeof(v.begin()) it=v.begin();it!=v.end();it++)

typedef pair<int,int> PII;
typedef long long int64;

int tests;
int n;
int64 a;
int64 x[100];

int main() {
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
    cin >> tests;
	REP (test,tests) {
		//cerr << test << endl;
		cin >> a >> n;
		REP (i,n) cin >> x[i];
		sort(x,x+n);
		int best=n;
		int k=0;
		REP (i,n) {
			while (a<=x[i] && k<best) {
				a+=(a-1);
				k++;
			}
			a+=x[i];
			if (k==best) break;
			best=min(best,k+n-1-i);
		}
		printf("Case #%d: %d\n", test+1,best);
	}
    return 0;
}
