#include <iostream>
#define NUM 31
using namespace std;

long long run() {
	long long a,b,k;
	cin >> a >> b >> k;
	long long result=0;
	for(long long n=NUM; n>=0; n--)
	for(long long p=NUM; p>=0; p--)
	for(long long q=NUM; q>=0; q--) {
		if(k&(1<<n))
		if(a&(1<<p))
		if(b&(1<<q)) {
			long long cur=1;
			for(long long i=0; i<=NUM && cur; i++) {
				//cout << i << ":" << endl;
				long long nPos=0;
				for(long long alpha=0; alpha<2; alpha++)
				for(long long beta=0; beta<2; beta++) {
					if(i > n && (alpha*beta != ((k&(1<<i))?1:0))) continue;
					if(i == n && alpha*beta == 1) continue;
					if(i > p && (alpha != ((a&(1<<i))?1:0))) continue;
					if(i == p && alpha == 1) continue;
					if(i > q && (beta != ((b&(1<<i))?1:0))) continue;
					if(i == q && beta == 1) continue;
					//cout << "    " << alpha << "," << beta << endl;
					nPos++;
				}
				cur*=nPos;
			}
			//cout << "(n,p,q)=(" << n <<"," << p << "," << q << ")="<<cur<<endl;
			result+=cur;
		}
	}
	return result;
}

int main() {
	long long n;
	cin >> n;
	for(long long i=0; i<n; i++)
		cout << "Case #" << (i+1) << ": " << run() << endl;
}