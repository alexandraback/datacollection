#include <iostream>

using namespace std;
long long p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int aa[100];

long long f(int n, int mod) {
	
	long long total = 0;
	for(int i=0;i<n;i++) {
		total = (total * 6 + aa[i]) % p[mod];
	}
	if(total== 0) {
		//cout << total << endl;
		return p[mod];
	}
	return 0;

}

long long check(int n) {
	long long z;
	for(int i=0;i<25;i++) {
		z = f(n, i);
		if(z != 0) return z;
	}
	return 0;
}

void ch(int z) {
	int pp[] = {3, 2, 3,2,z,2,3,2,3};
	for(long long i=2;i<=10;i++) {
		long long total = 0;
		for(long long j=0;j<32;j++) {
			total = (total * i + aa[j]) % pp[i-2];
		}
		if(total % pp[i-2] != 0) cout << "err " << total << " " << i << " " << pp[i-2]<< endl;
	}
	return;
}
int main() {
	freopen("A.in","r",stdin);
	freopen("B.txt","w",stdout);
	int t, n, m;
	int cnt = 0;
	cin >> t >> n >> m;
	cout << "Case #1:" << endl;
	if(n == 16) {
		aa[0] = 1; aa[n-1] =1;
		for(int i=2;i<n-1;i+=2)
			for(int j=i+2;j<n-1;j+=2)
				for(int k=1;k<n-1;k+=2)
					for(int l=k+2;l<n-1;l+=2)	 {
						for(int a = 1 ; a < n-1; a++) aa[a] = 0;
						aa[i] = 1;
						aa[j] = 1;
						aa[k] = 1;
						aa[l] = 1;
						int z = check(n);
						if(z != 0) {
							for(int a = 0;a<16;a++) cout << aa[a];
							cout << " 3 2 3 2 ";
							// 6
							cout << z << " ";
							cout << "2 3 2 3" << endl;
							//ch(z);
							cnt ++;
							if(cnt >= m) return 0;
						}
					}	
	}
	if(n == 32) {
		aa[0] = 1; aa[n-1] =1;
		for(int i=2;i<n-1;i+=2)
			for(int j=i+2;j<n-1;j+=2)	
				for(int k=1;k<n-1;k+=2)
					for(int l=k+2;l<n-1;l+=2) {
						for(int a = 1 ; a < n-1; a++) aa[a] = 0;
						aa[i] = 1;
						aa[j] = 1;
						aa[k] = 1;
						aa[l] = 1;
						int z = check(n);
						if(z != 0) {
							for(int a = 0;a < n;a++) cout << aa[a];
							cout << " 3 2 3 2 ";
							// 6
							cout << z << " ";
							cout << "2 3 2 3" << endl;
//							ch(z);
							cnt ++;
							if(cnt >= m) return 0;
						}
					}	
	}
}