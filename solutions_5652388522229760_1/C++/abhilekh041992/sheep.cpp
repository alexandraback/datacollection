#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<iomanip> 
#include<utility> 
#include<climits>
#include<climits>
#include<cmath>
#include<algorithm>


using namespace std;


#define LL long long int
#define sc1(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define sc3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define pr1(x) printf("%d\n", x)
#define FOR(i, a, n) for(int i=a;i<n;i++)
#define pp pair<int, int>

#define MAX 1000001
#define MOD 1000000007LL

bool cnt[10];
int done;


void check(LL n) {
	while(n) {
		if(!cnt[n%10]) { cnt[n%10] = true; done++; }
		n /= 10;
	}
}

LL func(LL n) {
	LL x = n;

	done = 0;
	FOR(i, 0, 10) cnt[i] = false;

	while(true) {
		check(x);

		if(done == 10) return x;
		x += n;
	}
}


// void offline() {
// 	FOR(i, 1, MAX) {
// 		cout<<i<<": "<<func(i)<<endl;
// 	}
// }


int main() {

	//offline();

	int t, n;

	sc1(t);
	FOR(i, 1, t+1) {
		sc1(n);

		if(n) printf("Case #%d: %lld\n", i, func(n));
		else printf("Case #%d: INSOMNIA\n", i);
	}
	return 0;
}













