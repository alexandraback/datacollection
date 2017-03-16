#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <memory.h>

using namespace std;

int A[50],B[50];
int a[200], f[200][200];

int main() {
	//freopen("input.txt", "r", stdin);
	freopen("d:\\Downloads\\B-small-attempt0.in", "r", stdin);
	freopen("d:\\Downloads\\B-small-attempt0.out", "w", stdout);
	for (int i=0; i<=30; i++)
		A[i] = B[i] = -1;

	for (int i=0; i<=10; i++)
		for (int j=i; j<=10 && j<=i+2; j++)
			for (int k=j; k<=10 && k<=i+2; k++) {
				int sum = i+j+k;
				if (k-i==2) {
					B[sum] = max(B[sum], k);
				} else {
					A[sum] = max(A[sum], k);
				}
			}

	int N; cin>>N; 
	for (int t=1; t<=N; t++) {
		int n,s,p; cin>>n>>s>>p;
		for (int i=1; i<=n; i++)
			cin>>a[i];
		memset(f, 0, sizeof f);
		for (int i=1; i<=n; i++)
			for (int j=0; j<=s; j++) {
				f[i][j] = f[i-1][j];
				if (A[a[i]]>=p) f[i][j]++;

				if (B[a[i]] != -1 && j>0) {
					int q = f[i-1][j-1];
					if (B[a[i]]>=p) q++;
					if (q>f[i][j]) f[i][j] = q;
				}
			}
		cout<<"Case #"<<t<<": "<<f[n][s]<<"\n";
	}
	return 0;
}