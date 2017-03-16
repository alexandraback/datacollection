import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class ProblemA {
	static double eps = 10e-10;
	
	public static double[] solve(int[] judge) {
		int n = judge.length;
		int X = 0;
		for (int j : judge) {
			X += j;
		}
		double[] ans = new double[n];
		for (int i = 0 ; i < n ; i++) {
			double min = 0.0d;
			double max = 1.0d;
			for (int cc = 0 ; cc < 100 ; cc++) {
				double med = (min + max) / 2.0d;
				double myscore = judge[i] + med * X;
				
				double left = 1.0d - med;
				double mrate = 0.0d;
				for (int j = 0 ; j < n ; j++) {
					if (i == j || judge[j] >= myscore) {
						continue;
					}
					mrate += (myscore - judge[j]) * 1.0d / X;
				}
				if (mrate > left) {
					max = med;
				} else {
					min = med;
				}
			}
			ans[i] = min * 100;
			if (ans[i] < eps) {
				ans[i] = 0.0d;
			}
		}
		return ans;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader s = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter w = new BufferedWriter(new FileWriter("./src/output.txt"));
		int T = Integer.valueOf(s.readLine());
		for (int t = 1 ; t <= T ; t++) {
			String[] data = s.readLine().split(" ");
			int n = Integer.valueOf(data[0]);
			int[] j = new int[n];
			for (int i = 0 ; i < n ; i++) {
				j[i] = Integer.valueOf(data[i+1]);
			}
			
			double[] d = solve(j);
			w.write("Case #" + t + ": ");
			w.write(d[0] + "");
			for (int i = 1 ; i < n ; i++) {
				w.write(" " + d[i]);
			}
			w.newLine();
		}
		w.flush();
		w.close();
	}
}