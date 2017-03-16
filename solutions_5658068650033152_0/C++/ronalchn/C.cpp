#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {

		int N, M, K;
		cin >> N >> M >> K;

		printf("Case #%d: ", t);
		int S = N*M, P = 2*(N+M)-4;

		if (N>M) swap(N,M);

		int cn = N/2, cm = M/2;
		int best = N*M;
		for (int p = 0; p <= cn+cm; p++) {
			int area, ans;

			if (p==0) {
				area=ans=1;
			}
			else {
				ans = 4*p;
				area = p*p + (p+1)*(p+1);

				area -= max(0,p-cn)*max(0,p-cn);
				area -= max(0,p-cm)*max(0,p-cm);
				area -= max(0,p-(N-1-cn))*max(0,p-(N-1-cn));
				area -= max(0,p-(M-1-cm))*max(0,p-(M-1-cm));
			}
			best = min(best,ans+max(K-area,0));

			if (p>0) {
				ans = 4*p+2;

				area = p*p + (p+1)*(p+1) + (2*p+1);
				//if (p==1) {
				//	printf("area=%d\n", area);
				//	printf("-%d\n", p-cn-1);
				//	printf("-%d\n",  (p-cm+1)*(p-cm));
				//	printf("-%d\n", (p-(N-1-cn))*(p-(N-1-cn)));
				//	printf("-%d\n", (p-(M-1-cm)+1)*(p-(M-1-cm)));
				//}
				area -= max(0,p-cn-1)*max(0,p-cn-1);
				area -= max(0,p-cm+1)*max(0,p-cm);
				area -= max(0,p-(N-1-cn))*max(0,p-(N-1-cn));
				area -= max(0,p-(M-1-cm)+1)*max(0,p-(M-1-cm));

				//if (p==1) {
				//	printf("ans=%d\n", ans);
				//	printf("area=%d\n", area);
				//}
				best = min(best,ans+max(K-area,0));
				
				area = p*p + (p+1)*(p+1) + (2*p+1);
				area -= max(0,p-cn+1)*max(0,p-cn);
				area -= max(0,p-cm-1)*max(0,p-cm-1);
				area -= max(0,p-(N-1-cn)+1)*max(0,p-(N-1-cn));
				area -= max(0,p-(M-1-cm))*max(0,p-(M-1-cm));

				best = min(best,ans+max(K-area,0));
			}
		}

		cout << best;
		cout << endl;

//		for (int n=1;n<=N;n++) {
//			for (int m=1;m<=M;m++) {
//				int area = n*m-4;
//				int ans = 2*(n-2+m-2);
//				if (n==1) {
//					if (m==1) area = ans = 1;
//					else {
//						ans = m-2;
//						area = m-2;
//					}
//				}
//				else if (m==1) area=ans=n-2;
//
//				ans = ans + max(K-area,0);
//				best = min(best,ans);
//			}
//		}

//		printf("Case #%d: ", t);
//		if (N==1) {
//			cout << K;
//		}
//		else if (N==2) {
//			cout << K;
//		}
//		else if (K>=S-3) {
//			cout << 2*(N+M)-8 + (K-(S-4));
//		}
//		else {
//			// best rectangle...
//			int n = 2;
//			while (n<N && (K+3)/n>n) {
//				n++;
//			}
//
//			int m = min((K+3+(n-1))/n,M);
//
//			//printf("(%d,%d)",n,m);
//			int ans = 2*(n+m)-8;
//			//printf("(%d)",ans);
//			ans += max(K-(n*m-4),0);
//			cout << ans;
//		}
//		
//		cout << endl;
	}
  return 0;
}
