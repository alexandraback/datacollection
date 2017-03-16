import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class TheGreatWall {
	public static class Attack implements Comparable<Attack>{
		long d;
		long n;
		int w;
		int e;
		int s;
		long ddi;
		int dpi;
		int dsi;
		
		public Attack(long d, long n, int w, int e, int s, long ddi, int dpi, int dsi) {
			this.d = d;
			this.n = n;
			this.w = w;
			this.e = e;
			this.s = s;
			this.ddi = ddi;
			this.dpi = dpi;
			this.dsi = dsi;
		}
		
		public Attack next() {
			if (n <= 1) {
				return null;
			}
			return new Attack(d + ddi, n - 1, w + dpi, e + dpi, s + dsi, ddi, dpi, dsi);
		}

		@Override
		public int compareTo(Attack that) {
			
			if (this.d < that.d) {
				return -1;
			} else if (this.d > that.d) {
				return 1;				
			} else {
				return 0;
			}
		}
	}
	
	
	public static long fun(List<Attack> attacks) {
		long success = 0;
		int[] heights = new int[2000001];
		while (attacks.isEmpty() == false) {
			long today = attacks.get(0).d;
			
			int tribes = 0;
			for (int i = 0; i < attacks.size(); ++i) {
				Attack attack = attacks.get(i);
				if (attack.d > today) {
					break;
				} else {
					++tribes;
				}
				
				for (int j = attack.w; j < attack.e; ++j) {
					if (heights[j] < attack.s) {
						++success;
						break;
					}
				}
			}
			
			for (int i = 0; i  < tribes; ++i) {
				Attack attack = attacks.remove(0);
				for (int j = attack.w; j < attack.e; ++j) {
					if (heights[j] < attack.s) {
						heights[j] = attack.s;
					}
				}
				Attack newAttack = attack.next();
				if (newAttack != null) {
					attacks.add(newAttack);
				}
			}
			
			Collections.sort(attacks);
		}
		
		return success;
	}
	
	public static void main(String[] args) throws IOException {
		String filename = args[0];
		BufferedReader in = new BufferedReader(new FileReader(filename));
		PrintStream out = new PrintStream(filename + ".out");
		int stages = Integer.parseInt(in.readLine());
		for (int stage = 1; stage <= stages; ++stage) {
			int N = Integer.parseInt(in.readLine());
			
			List<Attack> attacks = new ArrayList(N);
			for (int i = 0; i < N; ++i) {
				String[] tokens = in.readLine().split("\\s+");
				int di = Integer.parseInt(tokens[0]);
				int ni = Integer.parseInt(tokens[1]);
				int wi = Integer.parseInt(tokens[2]);
				int ei = Integer.parseInt(tokens[3]);
				int si = Integer.parseInt(tokens[4]);
				int ddi = Integer.parseInt(tokens[5]);
				int dpi = Integer.parseInt(tokens[6]);
				int dsi = Integer.parseInt(tokens[7]);
				attacks.add(new Attack(di, ni, 1000000 + wi, 1000000 + ei, si, ddi, dpi, dsi));
			}
			Collections.sort(attacks);
			out.printf("Case #%d: %s\n", stage, fun(attacks));
		}
	}
}
