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

const int MAXN = 100000;
long double p[MAXN], prod[MAXN], dprod[MAXN];
int main(){
	#ifdef JUAMPI
		freopen("test.in","r",stdin);
		freopen("test.out","w",stdout);
	#endif
	
	int testcases=0; scanf("%d",&testcases);
	forsn(testcase,1,testcases+1){
		int a,b;
		
		scanf("%d%d",&a,&b);
		forn(i,a) scanf("%Lf",&p[i]);
		
		prod[0] = 1.0;
		forsn(i,1,a+1)
			prod[i] = prod[i-1]*p[i-1];
		
		b = b-a;
		
		long double kb = 1000000;
		long double ke = a+b+2;
		
		forn(k,a+1){
			kb = min(kb,prod[a-k]*(2*k+b+1) + (1.0-prod[a-k])*(2*k+a+2*b+2));
		}
		
		kb = min(ke,kb);
		fprintf(stderr,"Case #%d: %Lf\n",testcase,kb);
		printf("Case #%d: %Lf\n",testcase,kb);
	}
	return 0;
}
