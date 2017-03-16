#include<cstdio>
#include<cstring>
const int W=40;
void tobinary(long long x,int * arr) {
	for (int i=0;i<W;i++) {
		arr[i]=x%2;
		x/=2;
	}
}
int main() {
	int T;
	scanf("%d",&T);
	for (int tc=1; tc<=T; tc++) {
		long long A,B,K;
		scanf("%lld%lld%lld",&A,&B,&K);
		static int binA[W];
		static int binB[W];
		static int binK[W];
		tobinary(A,binA);
		tobinary(B,binB);
		tobinary(K,binK);
		long long answer=0;
		for (int iA=0; iA<W; iA++) if (binA[iA] == 1)
		for (int iB=0; iB<W; iB++) if (binB[iB] == 1)
		for (int iK=0; iK<W; iK++) if (binK[iK] == 1)
		{
			static bool canA[W][2];
			static bool canB[W][2];
			memset(canA,0,sizeof canA);
			memset(canB,0,sizeof canB);
			for (int i=0;i<W;i++) {
				if (i<iA) canA[i][0]=canA[i][1]=true; else {
					canA[i][(i==iA)?0:binA[i]]=true;
				}
				if (i<iB) canB[i][0]=canB[i][1]=true; else {
					canB[i][(i==iB)?0:binB[i]]=true;
				}
			}
			long long term=1;
			for (int i=0; i<W; i++) {
				if (i<iK) {
					int v=0;
					if (canA[i][0]&&canB[i][0])v++;
					if (canA[i][0]&&canB[i][1])v++;
					if (canA[i][1]&&canB[i][0])v++;
					if (canA[i][1]&&canB[i][1])v++;
					term *= v;
				} else {
					if (binK[i] == 1 && i>iK) {
						if (!canA[i][1]||!canB[i][1])term=0;
						// A[i]=B[i]=1
					} else {
						// A[i]=0 of B[i]=0
						int v=0;
						if (canA[i][0]&&canB[i][0])v++;
						if (canA[i][0]&&canB[i][1])v++;
						if (canA[i][1]&&canB[i][0])v++;
						term *= v;
					}
				}
			}
			answer += term;
		}
		printf("Case #%d: %lld\n",tc,answer);
	}
}
