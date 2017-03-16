import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class ProblemA {
	
	public static double solve(int A, int B, double[] p) {
		double minexp = 2.0d + B;
		double probcorrect = 1.0d;
		int idx = 0;
		for (int x = A ; x >= 0 ; x--) {
			int current = A - x;
			double exp = x;
			exp += (B - current);
			exp += 1.0d;
			
			exp += (1.0d - probcorrect) * (B + 1.0d);
			minexp = Math.min(minexp, exp);
			
			if (x != 0) {
				probcorrect *= p[idx];
				idx++;
			}
		}
		return minexp;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader s = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.valueOf(s.readLine());
		for (int t = 1 ; t <= T ; t++) {
			String[] data = s.readLine().split(" ");
			int A = Integer.valueOf(data[0]);
			int B = Integer.valueOf(data[1]);
			double[] p = new double[A];
			
			
			String[] line = s.readLine().split(" ");
			for (int i = 0 ; i < A ; i++) {
				p[i] = Double.valueOf(line[i]);
			}
			System.out.println("Case #" + t + ": " + solve(A, B, p));
		}
	}
}