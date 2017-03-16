#include<bits/stdc++.h>
using namespace std;
#define all(x)      (x).begin(), (x).end()
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define fr(i,n)     re(i,0,n)
#define tr(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define NUM_BITS_INT (8*sizeof(long long))
long long int gcd(long long a,long long b) {
	if(b==0) return a;
	return gcd(b,a%b);
}

bool IsPowerOfTwo(long long int x){
    return (x & (x - 1)) == 0;
}

int main() {
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("A-small-attempt0.out","w",stdout);
	int t;
	cin >> t;
	for(int test=1; test <= t; test++) {
		long long int p,q;
		cin>>p;
		getchar();
		cin>>q;
		getchar();
		long long g = gcd(p,q);
		p/= g;
		q/= g;
		if(!IsPowerOfTwo(q)) {
			cout << "Case #" << test << ": " << "impossible" << endl;
		} else {
			long int ret=0;
			while((p/q)<1) {
				ret++;
				p*=2;
			}
			cout << "Case #" << test << ": " << ret << endl;
		}
	}
	return 0;
}

