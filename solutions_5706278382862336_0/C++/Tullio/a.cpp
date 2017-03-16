#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

#define pii pair<int,int>
#define pci pair<char,int>
#define f first
#define s second
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rep(a,b) fr(a,0,b)
#define db if(1)
#define pb push_back

typedef long long ll;

int n;
ll a, b;

ll gcd(ll x, ll y) {
	while(x) y %= x, swap(x,y);
	return y;
}

bool read(){
    if(scanf("%lld/%lld", &a, &b) == EOF) return false;
	
    return true;
}

int cn = 1;

void process(){
	ll k = gcd(a, b);
	a /= k;
	b /= k;
	if (a == 1 && b == 1) {
		printf("Case #%d: 1\n", cn++);
		return;
	}
	if (a > b) {
		printf("Case #%d: impossible\n", cn++);
		return;
	}

	int lb = 0, la = 0;
	while(b != 1) {
		if (b&1) {
			printf("Case #%d: impossible\n", cn++);
			return;
		}
		lb++;
		b >>= 1;
	}
	
	while(a != 1) {
		la++;
		a >>= 1;
	}
	b = (1LL<<lb);
	
	
	printf("Case #%d: %d\n", cn++, lb-la);
}

int main(){  
	int t = -1;
	
	scanf("%d", &t);

    while(t-- && read()){
        process();
    }
    
    return 0;
}
