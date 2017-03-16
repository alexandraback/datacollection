#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <cmath>

#define FOR(i,n) for(long long i = 0, _n = (n); i < _n; i++)

using namespace std;

//template <typename T> void updatemax(T &a, T b) { if(b>a) a = b;}
//template <typename T> void updatemin(T &a, T b) { if(b<a) a = b;}

long long gcd(long long a, long long b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	long long T;
	cin >> T;
	
	FOR(caseno, T){
		long long P, Q, d;
		char c;
		cin>>P>>c>>Q;
		d = gcd(P,Q);
		P /= d;
		Q /= d;
		
		long long q = Q, count = 0;
		while(q % 2 == 0){
			q /= 2;
			count++;
		}
		if(q != 1) cout<<"Case #"<<caseno+1<<": "<<"impossible"<<endl;
		else{
			count = 0;
			while(P < Q){
				count++;
				P*=2;
			}
			cout<<"Case #"<<caseno+1<<": "<<count<<endl;
		}		
	}
	return 0;
}