import java.util.Scanner;

public class Main {
	static long[] a;
	static long[] A;
	static long[] b;
	static long[] B;
	static int N;
	static int M;
	static int[][] solve;
	static long max(long i, long j){
		if (i>j) return i;
		return j;
	}
	static long fill(int i, int j, long a1, long b1){

		if (i>=N || j>=M) return 0;	
		
		if (a1==0) return fill(i+1, j, a[i+1], b1);
		if (b1==0) return fill(i, j+1, a1, b[j+1]);
		
		if (A[i]==B[j]){
			//System.out.println("i="+i+"j= "+j);
				if (a1>=b1) return b1+fill(i,j+1,a1-b1,b[j+1]);
				if (a1<b1) return a1+fill(i+1,j,a[i+1],b1-a1);
				if (a1==b1) return a1+fill(i+1,j+1,a[i+1],b[i+1]);
		}
		
		if (A[i]!=B[j]){ return max(fill(i,j+1,a1,b[j+1]),fill(i+1,j,a[i+1],b1));
		}
		return 0;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		for (int cas = 1; cas<=T; cas++){
			N = in.nextInt();
			M = in.nextInt();
			a = new long[N+1];
			b = new long[M+1];
			A = new long[N+1];
			B = new long[M+1];
			solve = new int[N+1][M+1];
			
			for (int i=0; i<N; i++){
				a[i]=in.nextLong();
				A[i]=in.nextLong();
			}
			for (int i=0; i<M; i++){
				b[i]=in.nextLong();
				B[i]=in.nextLong();
			}
			/*for (int k = M+N; k>=0; k--){
				for (int i = 0; i<N; i++){
					int j = k-i;
					if (j>0 && j<M){
					solve[i][j]=fill(i,j,a[i],b[j]);
					}
				}
			}*/
			System.out.println("Case #"+cas+": "+fill(0,0,a[0],b[0]));
			//System.out.println("Case #"+cas+": "+fill(0,2,a[0],b[2]));
		}
	}

}
