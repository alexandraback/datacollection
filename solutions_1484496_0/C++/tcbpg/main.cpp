//C
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

tint sums[1 << 20];
int main(){
	#ifdef JUAMPI
		freopen("test.in","r",stdin);
	#endif
	
	int testcases=0; scanf("%d",&testcases);
	forsn(testcase,1,testcases+1){
		static int s[32];
		int n;
		scanf("%d",&n);
		forn(i,n) scanf("%d",&s[i]);
	
		tint sum = -1; int conj1 = -1, conj2 = -1;
		forn(i, 1 << n){
			sums[i] = 0;
			forn(k,n) 
				if(i & (1 << k)) sums[i] += s[k];
		}

		forn(i, 1 << n){
			for(int  mask = i; mask != 0; mask = (mask-1) & i){
				int rev = (~mask) & i;
				if(sums[mask] == sums[rev]){
					conj1 = mask, conj2 = rev;
					sum = sums[i];
					goto fin;
				}
			}
		}
		
fin:	conj1 = conj1 & (~(conj1 & conj2));
		conj2 = conj2 & (~(conj1 & conj2));
		printf("Case #%d:\n",testcase);
		if(sum > -1){
			forn(i,n) if(conj1 & (1 << i)) printf("%d ",s[i]);
			putchar('\n');
			forn(i,n) if((conj2) & (1 << i)) printf("%d ",s[i]);
			putchar('\n');
		}else{
			printf("Impossible\n");
		}
	}
	return 0;
}
