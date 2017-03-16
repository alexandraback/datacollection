#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)

using namespace std;

typedef long long LL;

LL palindromize(LL a){
	vector<int> V;
	while(a){
		V.push_back(a%10);
		a /= 10;
	}
	LL r = 0;
	BCK(i,(int)V.size()-1,-1)
		r = r*10 + V[i];
	FWD(i,0,(int)V.size())
		r = r*10 + V[i];
	return r;
}

LL oddpalindromize(LL a){
	vector<int> V;
	while(a){
		V.push_back(a%10);
		a /= 10;
	}
	LL r = 0;
	BCK(i,(int)V.size()-1,-1)
		r = r*10 + V[i];
	FWD(i,1,(int)V.size())
		r = r*10 + V[i];
	return r;
}

bool palindrome(LL a){
	vector<int> V;
	while(a){
		V.push_back(a%10);
		a /= 10;
	}
	FWD(i,0,(int)V.size()/2)
		if(V[i] != V[(int)V.size()-1-i])
			return 0;
	return 1;
}

LL solve(LL lim){
	lim = sqrt(lim);
	LL r = 0;
	LL x = 1;
	LL y;
	while((y = palindromize(x)) <= lim){
		if(palindrome(y*y))
			++r;	
		++x;
	}
	x = 1;
	while((y = oddpalindromize(x)) <= lim){
		if(palindrome(y*y))
			++r;	
		++x;
	}
	return r;
}

int main(){
	int Z;
	scanf("%d", &Z);
	LL a, b;
	FWD(z,1,Z+1){
		scanf("%lld %lld", &a, &b);
		printf("Case #%d: %lld\n", z, solve(b)-solve(a-1));
	}
}

