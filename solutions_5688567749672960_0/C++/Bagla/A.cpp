#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<bitset>
#include<list>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<cstring>
#include<sstream>
#include<climits>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define S(x) scanf("%d",&x)
#define SD(x) scanf("%lf",&x)
#define SL(x) scanf("%lld",&x)
#define pb(x) push_back(x)
#define mp make_pair
#define F(i, a, b) for (int i = int(a); i < int(b); i++)
#define forit(it, a) for (it = (a).begin(); it != (a).end(); it++)
#define M(x,i) memset(x,i,sizeof(x))

/* -------------------CODE GOES HERE---------------------- */

ll sz = 1e6 + 1;
ll arr[1000001];

ll rev(ll x){

	ll reverse = 0;

	while (x != 0){
      	reverse *= 10;
      	reverse += (x % 10);
      	x /= 10;
   	}

   	return reverse;
}

int main(){
	
	int T; S(T);
	int tst = 1;
	
	ll N;

	arr[0] = 0;
	arr[1] = 1;

	F(i,2,sz){

		arr[i] = arr[i-1] + 1;

		if( (i % 10) && (rev(i) < i)){
			arr[i] = min(arr[i], arr[rev(i)] + 1);
		}
	}

	while(T--){

		SL(N);
		printf("Case #%d: %lld\n", tst++, arr[N]);
	}
}