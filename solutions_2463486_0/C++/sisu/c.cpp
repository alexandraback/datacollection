#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
bool test(const char* buf, ll a, ll b) {
	ll x;
	sscanf(buf, "%lld", &x);
	ll x2 = x*x;
	if (x2<a || x2>b) return 0;
	char buf2[128];
	sprintf(buf2, "%lld", x2);
	int n =strlen(buf2);
	for(int i=0; i<n/2; ++i)
		if (buf2[i]!=buf2[n-1-i]) return 0;
	return 1;
}
int main() {
	int t;cin>>t;
	for(int q=1; q<=t; ++q) {
		ll a,b;cin>>a>>b;
		int res = 0;
		char buf[128];
		for(int i=1; i<10; ++i) {
			sprintf(buf, "%d", i);
			res += test(buf, a, b);
		}
		for(int i=1; ll(i)*i*i*i < 10*b; ++i) {
			sprintf(buf,"%d",i);
			int n = strlen(buf);
			for(int j=0; j<n; ++j) buf[n+j] = buf[n-1-j];
			buf[2*n] = 0;
			res += test(buf, a, b);

			memmove(buf+n+1, buf+n, n+1);
			for(int j=0; j<10; ++j) {
				buf[n] = '0'+j;
				res += test(buf, a, b);
			}
		}
		cout<<"Case #"<<q<<": "<<res<<'\n';
	}
}
