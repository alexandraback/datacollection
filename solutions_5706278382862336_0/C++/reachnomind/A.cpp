#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int T;
	long long P, Q;
	cin>>T;
	for(int t=1; t<=T; t++) {
		cout<<"Case #"<<t<<": ";
		scanf("%lld/%lld", &P, &Q);
		long long p = P, q = Q;
		int f=0;
		while(q%2==0) {
			q/=2;
			f++;
		}
		if(P%q!=0) {
			cout<<"impossible"<<endl;
		} else {
			p=P/q;
			while(p>1) {
				p/=2;
				f--;
			}
			cout<<f<<endl;
		}
	}
	return 0;
}
