#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

long long stoll(string s){
	long long res = 0;
	for(int i = 0; i < s.size(); i++){
		res *=10;
		res += (s[i]-'0');
	}
	return res;
}

long long gcd(long long a, long long b){
	if(b == 0)return a;
	else return gcd(b, a%b);
}

int main(){
	int Z;
	scanf("%d", &Z);
	for(int zz = 1; zz <= Z; ++zz){
		long long p, q;
		string s;
		cin >> s;
		int k= 0;
		for(;k<s.size(); ++k)if(s[k]=='/')break;
		p = stoll(s.substr(0, k));
		q = stoll(s.substr(k+1));
//		printf("p:%lld q:%lld\n", p, q);
		if(p > q){
			printf("Case #%d: impossible\n", zz);
			continue;
		}
		long long div = gcd(q, p);
		p/=div;
		q/=div;
		if(__builtin_popcountll(q) != 1){
			printf("Case #%d: impossible\n", zz);
			continue;
		}
		int d = 0;
		while(p*2<q && q%2==0){
			q/=2;
			d++;
		}
		if(p*2 >= q)
			printf("Case #%d: %d\n", zz, d+1);
		else printf("Case #%d: impossible\n", zz);
	}
	return 0;
}
