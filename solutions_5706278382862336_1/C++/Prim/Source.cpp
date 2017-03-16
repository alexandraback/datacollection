#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>

#define pb push_back
#define mp make_pair
#define vi vector <int>
#define vii vector <pair<int,int> >
#define ll long long
#define f first
#define s second

using namespace std;

ll gcd(ll x, ll y){
	return y ? gcd(y, x%y) : x;
}

ll  t1,t,n,a,b;
ll p,q, m, cnt;

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("D.out", "w", stdout);
	scanf ("%d", &t);
	for(t1 = 1; t1 <= t; ++t1){

		scanf("%lld/%lld",&p,&q);
		m = gcd(p,q);
		p /= m; q /= m;
		cnt = 0;
		while(true){
			if(p / q >= 1)break;
			++cnt;

			if(q & 1){
				printf("Case #%lld: impossible",t1);
				goto hell ;
			}
			q /= 2;
		}
		while(q > 1){
			if(q & 1){
				printf("Case #%lld: impossible",t1);
				goto hell;
			}
			q /= 2;
		}
		printf("Case #%lld: %lld", t1, cnt);
		hell: printf("\n");
	}

	return 0;
}