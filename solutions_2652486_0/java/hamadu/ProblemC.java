import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class ProblemC {
	
	
	/**
	 * @param args
	 */
	
	static Map<Integer,Map<Integer,Integer>> stat;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		
		stat = new HashMap<Integer,Map<Integer,Integer>>();
		for (int i = 0 ; i < 125 ; i++) {
			int[] p = new int[3];
			p[0] = i % 5 + 1;
			p[1] = (i / 5) % 5 + 1;
			p[2] = i / 25 + 1;
			if (p[0] == 1 || p[1] == 1 || p[2] == 1) {
				continue;
			}
			for (int pt = 0 ; pt < 8 ; pt++) {
				int mu = 1;
				for (int m = 0 ; m < 3 ; m++) {
					if ((pt & (1<<m)) >= 1) {
						mu *= p[m];
					}
				}
				if (!stat.containsKey(mu)) {
					stat.put(mu, new HashMap<Integer,Integer>());
				}
				if (!stat.get(mu).containsKey(i)) {
					stat.get(mu).put(i, 0);
				}
				stat.get(mu).put(i, stat.get(mu).get(i) + 1);
			}
		}
		
		int T = in.nextInt();
		for (int cn = 1 ; cn <= T ; cn++) {
			int r = in.nextInt();
			int m = in.nextInt();
			int n = in.nextInt();
			int k = in.nextInt();
			out.println("Case #" + cn + ":");
			for (int i = 0 ; i < r ; i++) {
				int[] x = new int[k];
				for (int j = 0 ; j < k ; j++) {
					x[j] = in.nextInt();
				}
				out.println(solve(x));
			}
 		}
		out.flush();
	}
	

	private static String solve(int[] x) {
		double[] rate = new double[125];
		for (int t : x) {
			for (int i = 0 ; i < 125 ; i++) {
				if (!stat.get(t).containsKey(i)) {
					rate[i] = -1;
				}
			}
		}
		
		for (int t : x) {
			int total = 0;
			for (int k : stat.get(t).keySet()) {
				if (rate[k] >= 0) {
					total += stat.get(t).get(k);
				}
			}
			for (int k : stat.get(t).keySet()) {
				if (rate[k] >= 0) {
					rate[k] += 1.0d * stat.get(t).get(k) / total;
				}
			}
		}
		
		
		double max = 0;
		int mptn = 0;
		for (int i = 0 ; i < 125 ; i++) {
			if (max < rate[i]) {
				max = rate[i];
				mptn = i;
			}
		}

		int a = mptn % 5 + 1;
		int b = (mptn / 5 % 5) + 1;
		int c = mptn / 25 + 1;
		return a + "" + b + "" + c;
	}


	public static void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}
}
