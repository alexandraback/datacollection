import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Enumeration;
import java.util.Iterator;
import java.util.List;
import java.util.Properties;
import java.util.Stack;

/**
 * Works good for CF
 * 
 * @author cykeltillsalu
 */
public class Diamonds {

	// some local config
	static boolean test = true;
	static String testDataFile = "B-small-attempt2.in";
	static String feedFile = "feed.txt";
	CompetitionType type = CompetitionType.CF;
	private static String ENDL = "\n";

	// solution
	String[] dict = new String[521196];

	private void solve() throws Throwable {
		out = new BufferedWriter(new FileWriter(this.getClass().getCanonicalName() + "-res.txt"));

		int n = iread();
		for (int i = 0; i < n; i++) {
			solveIt(i + 1);
		}
		out.flush();
	}

	double binom(int n, int k) {
		int[] res = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			res[i] = 1;
			for (int j = i - 1; j > 0; j--) {
				res[j] += res[j - 1];
			}
		}
		return res[k];
	}
	
	class State {
		int l = 0, r = 0;

		private State(int left, int rigth) {
			super();
			this.l = left;
			this.r = rigth;
		}

		@Override
		public String toString() {
			return "State [left=" + l + ", rigth=" + r + "]";
		}

	}

	private void solveIt(int casenr) throws Throwable {
		double P = 0;

		int n = iread(), x = Math.abs(iread()), y = iread();
		int distance = (x + y) / 2;

		int base = 0;
		for (int i = 0; i < distance; i++) {
			base += i * 4 + 1;
		}

		if (base >= n) {
			P = 0;
		} else if (base + distance * 4 + 1 <= n) {
			P = 1;
		} else if (x != 0) {

			int full_row = distance * 2;

			Stack<State> stack = new Stack<Diamonds.State>();
			
			int white_needed = y + 1;
			int drawn_balls = n - base;
			 
			double total_ways = 0;
			double winning_ways = 0;
			stack.push(new State(0, 0));
			while(stack.size() > 0){
				State pop = stack.pop();
				if(pop.r + pop.l < drawn_balls){
					if(pop.l < full_row){
						stack.push(new State(pop.l + 1, pop.r));
					}
					if(pop.r < full_row){
						stack.push(new State(pop.l, pop.r + 1));
					}
				} else {
					total_ways ++;
					if(pop.r >= white_needed){
						winning_ways ++;
					}
				}
			}
			
			
			

//			for (int k = Math.max(0, drawn_balls - full_row); k <= Math.min(full_row, drawn_balls); k++) {
//				if(k < 0){
//					System.out.println("");
//				}
//				double c = binom(drawn_balls, k);
//				total_ways += c;
//				if (k >= white_needed) {
//					winning_ways += c;
//				}
//			}
			P = winning_ways / total_ways;
			System.out.println("Winning " + winning_ways + ", of " + total_ways);
			// System.out.println("got " + drawn_balls + " balls.");
		}

		String ans = "Case #" + casenr + ": " + P;
		System.out.println(ans);
		out.write(ans + "\n");
	}

	public int iread() throws Exception {
		return Integer.parseInt(wread());
	}

	public double dread() throws Exception {
		return Double.parseDouble(wread());
	}

	public long lread() throws Exception {
		return Long.parseLong(wread());
	}

	public String wread() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) throws Throwable {

		if (test) { // run all cases from testfile:
			long t0 = System.currentTimeMillis();
			new Diamonds().solve();
			System.out.println("Time in ms: " + (System.currentTimeMillis() - t0));
		}
		out.close();
	}

	public Diamonds() throws Throwable {
		if (test) {
			in = new BufferedReader(new FileReader(new File(testDataFile)));
		}
	}

	InputStreamReader inp = new InputStreamReader(System.in);
	BufferedReader in = new BufferedReader(inp);
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

	enum CompetitionType {
		CF, OTHER
	};
}