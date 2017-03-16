import java.io.*;
import java.util.*;

public class Consonants {

	FastScanner in;
	PrintWriter out;

	String vowels = "aeiou";

	boolean isCons(char c) {
		return vowels.indexOf(c) == -1;
	}

	class Pair {
		int start, end;

		public Pair(int start, int end) {
			super();
			this.start = start;
			this.end = end;
		}
	}

	void solve() {
		String s = in.next();
		int n = in.nextInt();
		List<Pair> runs = new ArrayList<>();
		for (int i = 0; i < s.length(); ) {
			if (!isCons(s.charAt(i))) {
				i++;
				continue;
			}
			int j = i;
			while (j < s.length() && isCons(s.charAt(j))) {
				j++;
			}
			
			if (j - i >= n) {
				runs.add(new Pair(i, j - 1));
			}
			i = j;
		}
		if (runs.size() == 0){ 
			out.println(0);
			return;
		}
		
		long ans = 0;
		
		int curRun = 0;
		for (int i = 0; i < s.length(); i++) {
			while (curRun < runs.size()) {
				Pair run = runs.get(curRun);
				if (!isGood(run, i, n)) {
					curRun++;
				} else {
					break;
				}
			}
			
			if (curRun == runs.size()) {
				break;
			}
			
			int add = Math.max(i + n, runs.get(curRun).start + n);
			ans += (s.length() - add + 1);
		}
		
		out.println(ans);
	}

	private boolean isGood(Pair run, int i, int n) {
		if (i > run.end) {
			return false;
		}
		if (i < run.start) {
			return true;
		}
		return (run.end - i + 1) >= n;
	}

	void run() {
		try {
			in = new FastScanner(new File("ALarge.in"));
			out = new PrintWriter("ALarge.out");

			int tests = in.nextInt();
			for (int i = 0; i < tests; i++) {
				out.printf("Case #%d: ", (i + 1));
				solve();
			}

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File file) {
			try {
				br = new BufferedReader(new FileReader(file));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new Consonants().run();
	}
}
