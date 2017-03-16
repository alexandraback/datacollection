#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>

#define PB push_back

#define PP pair<int, int>
#define MP make_pair
#define F first
#define S second

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
	while(b){
		ll temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}


int main(){
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++){
		printf("Case #%d: ", i);	
		ll P, Q;
		scanf("%lld/%lld", &P, &Q);

		ll g = gcd(P, Q);
		P /= g;
		Q /= g;
		if ((Q&(Q-1)) != 0) printf("impossible\n");
		else{
			int count = 0;
			while(P < Q) P *= 2, count++;
			printf("%d\n", count);	
		}
	}
	return 0;
}
