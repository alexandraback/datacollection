import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class ProblemC {
	
	static final String IMP = "Impossible";
	
	static class Subset implements Comparable<Subset> {
		long sum = 0;
		int code;
		@Override
		public int compareTo(Subset arg0) {
			return Long.signum(sum - arg0.sum);
		}
	}
	
	public static int[][] solve(int[] num) {
		int len = num.length;
		Arrays.sort(num);
		
		Subset[] sets = new Subset[1<<20];
		for (int i = 0 ; i < (1<<20) ; i++) {
			sets[i] = new Subset();
			sets[i].code = i;
			for (int j = 0 ; j < 20 ; j++) {
				if ((i & (1<<j)) >= 1) {
					sets[i].sum += num[j];
				}
			}
		}
		
		Arrays.sort(sets);
		
		int codei = -1;
		int codej = -1;
		search: for (int i = 0 ; i < (1<<20) ; i++) {
			int j = i + 1;
			while (j < (1<<20) && sets[j].sum == sets[i].sum) {
				if ((sets[j].code & sets[i].code) == 0) {
					codei = sets[j].code;
					codej = sets[i].code;
					break search;
				}
			}
		}
		if (codei == -1) {
			return new int[0][0];
		}

		int[][] ret = new int[2][];
		
		ret[0] = new int[Integer.bitCount(codei)];
		int idxi = 0;
		for (int i = 0 ; i < 20 ; i++) {
			if ((codei & (1<<i)) >= 1) {
				ret[0][idxi++] = num[i];
			}
		}
		
		ret[1] = new int[Integer.bitCount(codej)];
		int idxj = 0;
		for (int i = 0 ; i < 20 ; i++) {
			if ((codej & (1<<i)) >= 1) {
				ret[1][idxj++] = num[i];
			}
		}
		return ret;
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
			
			int[][] d = solve(j);
			w.write("Case #" + t + ":");
			w.newLine();
			if (d.length == 0) {
				w.write(IMP);
				w.newLine();
			} else {
				for (int l = 0 ; l <= 1 ; l++) {
					w.write("" + d[l][0]);
					for (int i = 1 ; i < d[l].length ; i++) {
						w.write(" " + d[l][i]);
					}
					w.newLine();
				}
			}
		}
		w.flush();
		w.close();
	}
}