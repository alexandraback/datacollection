#include<iostream>
#include<cmath>
using namespace std;

typedef long long int ll;

#define MAXN 10000001ll

int nPal[MAXN];

bool is_palindrome(ll N){
	ll D(N), R(0);
	while (N){
		R = R*10 + N%10;
		N /=10;
	}
	return R==D;
}

void precompute(){
	nPal[0]=1;
	for (ll i=1; i<MAXN; i++)
		nPal[i] = nPal[i-1] + (is_palindrome(i) && is_palindrome(i*i));
}

int main(){
	int T;
	double A, B;
	cin>>T;
	precompute();
	for (int t=0; t<T; t++){
		cin>>A>>B;
		cout<<"Case #"<<t+1<<": "<<nPal[int(floor(sqrt(B)))] - nPal[int(ceil(sqrt(A)))-1]<<endl;
	}
	return 0;
}
