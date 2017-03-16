import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.out;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;

import java.util.Scanner;


public class B {
	public static void main(String [] args) throws Exception{
		Scanner scanner = new Scanner(new File("B-large (1).in"));
		PrintStream print = new PrintStream(new File("output-B-large"));
		
		int nTests = scanner.nextInt();
		
		for (int c = 0; c < nTests; c++){
			int E = scanner.nextInt();
			int R = scanner.nextInt();
			int N = scanner.nextInt();
			
			long [] V = new long[N];
			boolean[] done = new boolean[N];
			long [] B = new long[N];
			long [] Q = new long[N+1];
			B[0] = E;
			Q[N] = 0;
			int count = 0;
			
			for (int i = 0; i < N; i++)
			{
				V[i] = scanner.nextInt();
			}

			long sum = 0;
			while (count < N){
				int i = findNextMax(V, done);
				int s = findPrev(i, done);
				int t = findNext(i, done);
				
				long T  = E;
				if (s >= 0)
					T = min(B[s] + R *  (i - s), E);

				long M = min(T, T + (t-i) * R - Q[t]);
				
				sum += M * V[i]; 
				B[i] =(T - M);
				Q[i] = T;
				done[i] = true;
				count ++;
			}
			
			out.printf("Case #%d: %d\n", c+1, sum);
			print.printf("Case #%d: %d\n", c+1, sum);
			
		}
	}

	private static int findNext(int index, boolean[] done) {
		for (int i = index + 1; i < done.length; i++){
			if (done[i])
				return i;
		}
		return done.length;
	}

	private static int findPrev(int index, boolean[] done) {
		for (int i = index - 1; i >= 0; i--){
			if (done[i])
				return i;
		}
		return -1;
	}

	private static int findNextMax(long[] v, boolean[] done) {
		
		int index = 0;
		long max = Integer.MIN_VALUE;
		for (int i = 0; i < v.length; i++){
			if (done[i])
				continue;
			if (v[i] > max)
			{
				max = v[i];
				index = i;
			}
		}
		
		return index;
	}
}
