import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class R1CC {

	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(new DataInputStream(
				new FileInputStream("r:\\input.txt"))));
		pw = new PrintWriter(new BufferedWriter(
				new FileWriter("r:\\output.txt")));
		int MAX_NUM_CASE = readInt();

		for (int qq = 1; qq <= MAX_NUM_CASE; qq++) {
			pw.print("Case #" + qq + ": ");

			if (qq == 85) {
				int r = 0;
			}

			solve();
		}

		pw.close();
	}

	public static class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

	}

	public static class Triple {
		int x;
		int y;
		int z;

		public Triple(int x, int y, int z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}

	}

	private static void solve() throws IOException {

		int J = readInt();
		int P = readInt();
		int S = readInt();
		int K = readInt();

		Map<Pair, Integer> JP = new HashMap<Pair, Integer>();
		Map<Pair, Integer> JS = new HashMap<Pair, Integer>();
		Map<Pair, Integer> PS = new HashMap<Pair, Integer>();

		List<Triple> result = new ArrayList<Triple>();

		for (int j = 1; j <= J; j++) {
			for (int p = 1; p <= P; p++) {

				Pair jp = new Pair(j, p);

				for (int st = 1; st <= S; st++) {

					int s = (st + p + j - 1) % S + 1;

					Pair js = new Pair(j, s);
					Pair ps = new Pair(p, s);

					if (!JP.containsKey(jp))
						JP.put(jp, 0);
					if (!JS.containsKey(js))
						JS.put(js, 0);
					if (!PS.containsKey(ps))
						PS.put(ps, 0);

					if (JP.get(jp) < K && JS.get(js) < K && PS.get(ps) < K) {

						result.add(new Triple(j, p, s));
						JP.put(jp, JP.get(jp) + 1);
						JS.put(js, JS.get(js) + 1);
						PS.put(ps, PS.get(ps) + 1);
					}

				}
			}
		}

		pw.println(result.size());

		// System.out.println(J + " " + P + " " + S + " " + K);

		for (Triple t : result) {
			pw.println(t.x + " " + t.y + " " + t.z);
			// System.out.println(t.x + " " + t.y + " " + t.z);
		}

		// System.out.println();
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			if (!br.ready()) {
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}

}
