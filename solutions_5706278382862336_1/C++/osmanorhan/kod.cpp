// Task-ID: 1534
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdlib>

#define fi first
#define se second
#define ort (b+s)/2
#define pb push_back
#define all(x) x.begin() , x.end()

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef long long Lint;
typedef double db;

const int maxn = 120;
Lint a,b,n;

int main()
{
	freopen("qwe.in","r",stdin);
	freopen("qwe.out","w",stdout);
	scanf("%d",&n);
	
	
	for(int i=1;i<=n;i++) {
		char ch;
		scanf("%lld %c %lld",&a,&ch,&b);
		
		Lint t = __gcd( a , b );
		a /= t;
		b /= t;
		Lint k = -1 , l = -1, m = 0;
		for(Lint j=1;j<=a;j*=2,k++);
		for(Lint j=1;j<=b;j*=2,l++) {
			if( j == b ) {
				m = 1;
			}
		}
		
		printf("Case #%d: ",i);
		
		if( !m ) {
			printf("impossible\n");
			continue;
		}
		printf("%lld\n",l-k);
	}

	return 0;
}
