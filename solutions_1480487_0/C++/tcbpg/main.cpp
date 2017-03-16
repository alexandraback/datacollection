//A
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <bitset>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define forall(i,c) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dforn(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define dforsn(i,s,n) for(int i=((int)(n)-1);i>=(int)(n);i--)
#define esta(i,c) ((c).find(i) != (c).end())
#define estal(i,c) (find((c).begin(),(c).end(),(i))!=(c).end())
#define all(c) (c).begin(),(c).end()

#define dbg(x) cerr << #x << " = " << x << endl;
#define raya cerr << string('=',80) << endl;

typedef long long tint;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;

const long double eps = 1e-10;
int main(){
	#ifdef JUAMPI
		freopen("test.in","r",stdin);
	#endif
	
	int testcases=0; scanf("%d",&testcases);
	forsn(testcase,1,testcases+1){
		int n;
		vector<long double> s;
		
		scanf("%d",&n);
		forn(i,n){
			int a; scanf("%d",&a);
			s.push_back(a);
		}
		long double sum = 0;
		forn(i,n) sum += s[i];
		vector<long double> res;

		vector<long double> g(n);
		forn(i,n){
			long double l = 0.0, r = 1.0;
			while(r-l > eps){
				long double m = (l+r)/2;
				
				fill(all(g),0.0);
				forn(j,n){
					if(i == j) continue;
					g[j] = max(0.0L,m-(s[j]-s[i])/sum);
				}
				long double gs = 0;
				forn(j,n) gs += g[j];
				
				if(gs > 1.0-m+eps) r = m; else l = m;
			}
			res.push_back(r);
		}
		
		printf("Case #%d: ",testcase);
		forn(i,n){
			printf("%Lf",100.0*res[i]);
			if(i < n-1) putchar(' '); else putchar('\n');
		}
	}
	return 0;
}
