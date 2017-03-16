import java.util.Scanner;

public class TaskC {
	
	static long lcs(int N, int M, long a[], int A[], long b[], int B[]) {
		long LCS[][][] = new long[N+1][M+1][100];
		long la[][][] = new long[N+1][M+1][100];
		long lb[][][] = new long[N+1][M+1][100];
		
		for(int n = 1; n<=N; ++n)
			for(int m = 1; m<=M; ++m) {
				long maxp = 0;
				for(int t=0;t<100;++t)
					if (maxp<LCS[n-1][m-1][t])
						maxp = LCS[n-1][m-1][t];
				for(int t=0;t<100;++t) {
					if (A[n-1]==t && B[m-1]==t) {
						long prod1 = Math.min(la[n-1][m-1][t]+a[n-1], lb[n-1][m-1][t]+b[m-1]);
						long prod2 = Math.min(a[n-1],b[m-1]);
						if (prod1+LCS[n-1][m-1][t] > prod2+maxp) {
							LCS[n][m][t] = LCS[n-1][m-1][t] + prod1;
							la[n][m][t] = la[n-1][m-1][t]+a[n-1] - prod1;
							lb[n][m][t] = lb[n-1][m-1][t]+b[m-1] - prod1;
						} else {
							LCS[n][m][t] = prod2 + maxp;
							la[n][m][t] = a[n-1] - prod2;
							lb[n][m][t] = b[m-1] - prod2;
						}
					} else if (A[n-1]==t) {
						long prod = Math.min(la[n-1][m][t]+a[n-1], lb[n-1][m][t]);
						LCS[n][m][t] = LCS[n-1][m][t] + prod;
						la[n][m][t] = la[n-1][m][t]+a[n-1] - prod;
						lb[n][m][t] = lb[n-1][m][t] - prod;
					} else if (B[m-1]==t) {
						long prod = Math.min(la[n][m-1][t], lb[n][m-1][t]+b[m-1]);
						LCS[n][m][t] = LCS[n][m-1][t] + prod;
						la[n][m][t] = la[n][m-1][t] - prod;
						lb[n][m][t] = lb[n][m-1][t]+b[m-1] - prod;
					}
					if (LCS[n][m-1][t] > LCS[n][m][t]) {
						LCS[n][m][t] = LCS[n][m-1][t];
						la[n][m][t] = la[n][m-1][t];
						lb[n][m][t] = lb[n][m-1][t];
					}
					if (LCS[n-1][m][t] > LCS[n][m][t]) {
						LCS[n][m][t] = LCS[n-1][m][t];
						la[n][m][t] = la[n-1][m][t];
						lb[n][m][t] = lb[n-1][m][t];
					}
				}
				
			}
		long ans = 0;
		for (int t=0;t<100;++t)
			if (LCS[N][M][t]>ans)
				ans = LCS[N][M][t];
		return ans;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 0; t<T; ++t) {
			int N, M;
			N = sc.nextInt();
			M = sc.nextInt();
			long a[] = new long[N];
			int A[] = new int[N];
			long b[] = new long[M];
			int B[] = new int[M];
			
			for (int n = 0; n<N; ++n) {
				a[n] = sc.nextLong();
				A[n] = sc.nextInt()-1;
			}
			
			for (int m = 0; m<M; ++m) {
				b[m] = sc.nextLong();
				B[m] = sc.nextInt()-1;
			}
			
			System.out.println("Case #" + (t+1) + ": " + lcs(N,M,a,A,b,B));
		}
	}

}
