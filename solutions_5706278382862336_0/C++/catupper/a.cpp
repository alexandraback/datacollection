#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long Int;

Int gcd(Int a, Int b){
	if(a == 0)return b;
	return gcd(b % a, a);
}


int main(){
	Int p, q, T;
	cin >> T;
	for(int i = 1;i <= T;i++){
		scanf("%lld/%lld", &p, &q);
		Int g = gcd(p, q);
		p /= g;
		q /= g;
		if(((q & -q) != q) || (q & -q) > (1LL << 40)){
			cout << "Case #" << i << ": impossible" << endl;
			continue;
		}		
		int res = 0;
		int resp = 0;
		while(1LL << res <= p)res++;
		while(1LL << resp != q){
			resp++;		
		}
		cout << "Case #" << i << ": " << resp - res + 1 << endl;
	}
	return 0;
}