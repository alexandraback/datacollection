#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#include <ctime>
#define sz(a) ((int)(a).size())
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define Rep(i,j,k) for (int i=(j); i<=(k); i++)
#define Repd(i,j,k) for (int i=(j); i>=(k); i--)
#define ALL(c) (c).begin(),(c).end()
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SUM(a) accumulate(all(a),string())
#define online1
#define RAND ((rand()<<15)+rand())
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;

int a[200][200], n, m;

void doit(){
	cin>>n>>m;
	Rep(i,1,n)
		Rep(j,1,m)
			scanf("%d",a[i]+j);

	Rep(i,1,n)
		Rep(j,1,m){
			bool ok=1;
			Rep(i0,1,n)
				if (a[i0][j]>a[i][j])
					ok=0;
			if (ok)
				continue;

			ok=1;
			Rep(j0,1,m)
				if (a[i][j0]>a[i][j])
					ok=0;
			if (ok)
				continue;

			puts("NO");
			return;
		}
	puts("YES");
}

int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	int TT;
	cin>>TT;
	Rep(tt,1,TT){
		printf("Case #%d: ",tt);
		doit();
	}

    return 0;
}
