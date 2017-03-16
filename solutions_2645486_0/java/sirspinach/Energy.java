import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
public class Energy {
	private static PrintWriter out;
	private static final Scanner s = new Scanner(System.in);
	
	private static int E,R,N;
	private static int[] v;
	
	private static void output(int t, int result) {
		out.println("Case #"+t+": "+result);
	}
	
	public static void main(String[] args) throws IOException {
		out = new PrintWriter(new BufferedWriter(new FileWriter("C:\\Code Jam 2013\\output.txt")));
		
		int T = s.nextInt();
		for (int t = 1; t <= T; t++) {
			E = s.nextInt();
			R = s.nextInt();
			N = s.nextInt();
			v = new int[N];
			for (int i = 0; i < N; i++) {
				v[i] = s.nextInt();
			}
			output(t,doTrial());
		}
		
		out.flush();
		System.exit(0);
	}
	
	private static int findBest(int e, int p, int n) {
		//System.out.println(n);
		//if (n >= N) return p;
		if (e > E) e = E;
		if (n == N-1) return p + e * v[n];
		if (e <= 0) return findBest(e+R, p, n+1);
		return Math.max(findBest(e - 1, p + v[n], n), findBest(e+R, p, n+1));
	}
	
	private static int doTrial() {
		if (R > E) {
			int sum = 0;
			for (int i = 0; i < N; i++)
			{
				sum += v[i];
			}
			return sum;
		}
		else return findBest(E, 0, 0);
	}
}