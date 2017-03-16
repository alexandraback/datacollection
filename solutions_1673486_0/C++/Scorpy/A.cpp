#include <iostream>
#include <cstdio>
using namespace std;

double p [100010];

double solve(){
	int A,B;
	scanf("%d%d", &A, &B);
	bool qq = false;
	for( int i = 0; i < A; i++ ){
		cin>>p[i];
		if( p[i]!=1 ) qq = true;
	}
	if( !qq && false ){
		return B-A+1;
	}
	double res = B+2;
	double q = 1;
	double tmp = 0;
	p[A] = 0;
	for( int i = 0; i <= A; i++ ){
		tmp += q*(1-p[i]) * (B-A + (i==A ? 1 : B+2));
		q*=p[i];
	}
	res = min(res,tmp);
	for( int i = 1; i<=A; i++ ){
		tmp = 0;
		q = 1;
		for( int j = 0; j <= A; j++ ){
			if( j < A-i ){
				tmp += q*(1-p[j]) * (i+2+B+B-A+i);
			}
			else{
				tmp += q*(1-p[j]) * (i+1+B-A+i);
			}
			q*=p[j];
		}
		res = min(res,tmp);
	}
	return res;
}

int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for( int i = 0; i < T; i++ ){
		printf("Case #%d: %.6lf\n", i+1, solve() );
	}
}