#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
long long a, b;
char c;
long long mx = 1;
long long gcd (long long a, long long b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

void solve(int test){
	printf("Case #%d: ", test+1);
	cin>>a >> c>>b;
	cerr << a << " " << b << endl;
	long long d = gcd(a,b);
	a/=d;
	b/=d;
	
	if(mx%b){
		cout << "impossible" << endl;
	}
	else{
		int n=0;
		while(a<b){
			a*=2;
			n++;
		}
		cout << n << endl;
	}
	
}

int ntest;
int main(){
	for(int i=0; i<40; i++){
		mx*=2;
	}
	freopen("A-large.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&ntest);		
	for(int t=0; t<ntest; t++){
		solve(t);
	}
	return 0;
}
