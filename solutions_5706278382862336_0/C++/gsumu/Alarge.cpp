#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int p, long long int q){
	if(q == 0) return p;
	return gcd(q, p % q);
}

int main(){
	int T;
	long long int p, q, g;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		scanf("%lld/%lld", &p, &q);
		printf("Case #%d: ", t);
		//printf("%lld/%lld ", p, q);
		if(p > q){
			cout << "impossible\n";
			continue;
		}
		g = gcd(p, q);
		//cout << g << " ";
		p /= g;
		q /= g;
		if(p == q){
			cout << "0\n";
			continue;
		}
		g = q;
		while(!(g & 1)){
			g >>= 1;
		}
		if(g > 1){
			cout <<"impossible\n";
			continue;
		}
		int gen = 1;
		while(p < (q >> 1)){
			++gen;
			q >>= 1;
		}
		cout << gen << endl;
	}
	return 0;
}
