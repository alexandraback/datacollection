import java.io.*;
import java.util.*;

public class Csmall {

	Scanner in;

	PrintWriter out;

	private static final String path = "/home/alex/Downloads/";

	private static final String task = "C-small-attempt0";

	List<Pair> links = new ArrayList<>();

	static class Pair {

		int j, p, s;

		Pair(int j, int p, int s) {
			this.j = j;
			this.p = p;
			this.s = s;
		}
		
		public String toString() {
			return j + " " + p + " " + s;
		}
	}
	
	List<Pair> var;
	
	ArrayDeque<Pair> take;
	
	Collection<Pair> result;
	int jp[][];
	int js[][];
	int ps[][];
	
	int limit2;
	
	void gen(int idx) {
		if (idx == var.size()) {
			if (result.size() < take.size()) {
				result = new ArrayList<>(take);
			}
			return;
		}
		int remain = var.size() - idx;
		if (result.size() >= take.size() + remain) {
			return;
		}
		
		// take
		Pair curr = var.get(idx);
		final int j = curr.j;
		final int s = curr.s;
		final int p = curr.p;
		if (jp[j][p] < limit2 && js[j][s] < limit2 && ps[p][s] < limit2) {
			jp[j][p]++;
			js[j][s]++;
			ps[p][s]++;
			
			take.push(curr);
			
			gen(idx + 1);
			
			take.pop();
			
			jp[j][p]--;
			js[j][s]--;
			ps[p][s]--;
		}
		
		gen(idx + 1);
	}

	void solveOne() {
		final int j = in.nextInt();
		final int p = in.nextInt();
		final int s = in.nextInt();
		limit2 = in.nextInt();
		
		var = new ArrayList<>();
		jp = new int[j+1][p+1];
		js = new int[j+1][s+1];
		ps = new int[p+1][s+1];
		
		result = new ArrayList<>();
		
		for (int jj = 1; jj <= j; jj++) {
			for (int pp = 1; pp <= p; pp++) {
				for (int ss = 1; ss <= s; ss++) {
					var.add(new Pair(jj, pp, ss));
				}
			}
		}
		take = new ArrayDeque<>();
		gen(0);
		
		out.println(result.size());
		for (Pair pp : result) {
			out.println(pp);
		}
	}

	static void asserT(boolean e) {
		if (!e) {
			throw new Error();
		}
	}

	void solve() {
		int nTests = in.nextInt();
		for (int i = 1; i <= nTests; i++) {
			out.print("Case #" + i + ": ");
			solveOne();
		}
	}

	void run() {
		try {
			in = new Scanner(new FileReader(path + task + ".in"));
			out = new PrintWriter(new FileWriter(path + task + ".out_"));
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
			out.println(">");
			out.flush();
		}

		try {
			solve();
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) {
		new Csmall().run();
	}
}
