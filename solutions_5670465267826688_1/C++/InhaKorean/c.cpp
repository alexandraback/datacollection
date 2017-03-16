#include <stdio.h>
#include <iostream>
using namespace std;
int T,C=1;
long long L, X;
int S[10010];
char buf[10010];
int multiple(int a, int b){
	if(a == 1 || a == -1 || b == 1 || b == -1) return a*b;
	int na = 1 , nb = 1;
	if(a < 0) {
		na = -1;
		a = -a;
	}
	if(b < 0) {
		nb = -1;
		b = -b;
	}
	if(a == b) return na * nb * (-1);
	if(a == 2){
		if(b == 3) return na*nb*4;
		if(b == 4) return na*nb*(-3);
	}
	if(a == 3){
		if(b == 2) return na*nb*(-4);
		if(b == 4) return na*nb*2;
	}
	if(a == 4){
		if(b == 2) return na*nb*3;
		if(b == 3) return na*nb*(-2);
	}
	return 12345;
}

int zegob(int a, int b){
	if(a == 1) return 1;
	if(a == -1) return (b%2 == 0)?1:-1;
	int na = 1;
	if(a < 0) {
		na = (b%2 == 0)?1:-1;
		a = -a;
	}
	if(b % 4 == 0) return na*1;
	if(b % 4 == 1) return na*a;
	if(b % 4 == 2) return na*(-1);
	if(b % 4 == 3) return na*(-a);
	return 12345;
}

bool solve(){
	cin >> L >> X;
	scanf("%s", buf);
	for(int i=0; i<L; ++i){
		if(buf[i] == '1') S[i] = 1;
		else if(buf[i] == 'i') S[i] = 2;
		else if(buf[i] == 'j') S[i] = 3;
		else if(buf[i] == 'k') S[i] = 4;
	}

	int r = 1;
	long long pi = -1, pk = L*X;
	while(r != 2){
		if(pi == L*X-1) return false;
		pi++;
		r = multiple(r, S[pi%L]);
		if(pi > 50000) return false;
	}
	r = 1;
	while(r != 4){
		if(pk == 0) return false;
		pk--;
		r = multiple(S[pk%L], r);
		if(L*X-1-pk > 50000) return false;
	}
	if(pi >= pk) return false;
	r = 1;
	for(long long i=pi+1; i<pk; ++i){
		if(i == pi+1+L && pk - i > 2*L){
			r = zegob(r, (pk-i)/L+1);
			i += (pk-i) - (pk-i)%L;
			if(i == pk) break;
		}
		r = multiple(r, S[i%L]);
	}
	return (r == 3);
}
int main(){
	scanf("%d", &T);
	while(T--){
		bool ans;
		ans = solve();
		if(ans) printf("Case #%d: YES\n", C++);
		else printf("Case #%d: NO\n", C++);
	}
	return 0;
}
