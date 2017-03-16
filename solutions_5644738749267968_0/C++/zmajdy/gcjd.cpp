#include <bits/stdc++.h>

using namespace std;

double N[100111];
double K[100111];
bool bol[100111];
int T,n;

int main () {
	cin >> T;
	for (int tc=1; tc<=T; tc++) {
		scanf ("%d",&n);
		for (int i=1; i<=n; i++) 
			scanf ("%lf",&N[i]);
		for (int i=1; i<=n; i++)
			scanf ("%lf",&K[i]),
			bol[i] = false;
			
		sort (N+1,N+n+1);
		sort (K+1,K+n+1);
		
		int cur = 0,jur = 0;
		int ki = 1;
		int ka = n;
		for (int i=1; i<=n; i++) 
			if (N[i] < K[ki]) ka--;
			else ki++, cur++;
		
		ki = 1;
		ka = n;
		for (int i=1; i<=n; i++) {
			int imin = -1;
			int ians = -1;
			for (int j=n; j>=1; j--) if (!bol[j]) {
				// puts("tes tes");
				imin = j;
				if (K[j] > N[i]) ians = j;
			}
			int ans;
			if (ians == -1) ans = imin;
			else ans = ians;
			bol[ans] = true;
			if (N[i] > K[ans]) jur++;
			// cout << i << " " <<imin << " ";
			// cout << N[i] << " " <<K[ans] <<endl;
		}
		
		printf ("Case #%d: ",tc);
		cout << cur << " "<<jur <<endl;
	}
}
