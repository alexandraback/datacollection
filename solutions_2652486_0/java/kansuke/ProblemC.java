import java.io.*;
import java.math.*;
import java.util.*;

public class ProblemC {
	static Scanner scan = new Scanner (System.in);
	static PrintStream out = System.out;

	static int R, N, M, K;
	static int[] prod;
	
	static int power (int N, int M_1) {
		int ans = 1;
		for (int i = 0; i < M_1; ++i)
			ans *= N;
		return ans;
	}
	
	static void check () {
		for (int i = 0; i < K; ++i)
			prod[i] = scan.nextInt();
		double pp = power(N+1,M-1);
		for (int t = 0; t < pp; ++t){
			int[] cnt = new int[M-1];
			int sum = 0;
			int tmp = t;
			for (int i = 0; i < M-1; ++i) {
				cnt[i] = tmp%(N+1);
				tmp/=(N+1);
				sum += cnt[i];
				if (sum > N)
					break;
			}
			if (sum != N)
				continue;
			int mul = 1;
			for (int i = 2; i <= M; ++i)
				mul *= power (i, cnt[i-2]);
			boolean check = true;
			for (int i = 0; i < K; ++i) {
				if (mul%prod[i] != 0) {
					check = false;
					break;
				}
			}
			if (check) {
				for (int i = 2; i <= M; ++i) {
					for (int j = 0; j < cnt[i-2]; ++j)
						out.print(i);
				}
				out.println ();
				return;
			}
		}
		out.println();
	}
	
	static void test () {
		R = scan.nextInt();
		N = scan.nextInt();
		M = scan.nextInt();
		K = scan.nextInt();
		prod = new int[K];
		for (int r = 0; r < R; ++r)
			check ();
	}

	
	public static void main (String[] args) {
		int T = scan.nextInt();
		for (int i = 1; i <= T; ++i) {
			out.println ("Case #" + i + ": ");
			test ();
		}
	}
}
