import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

public class Pogo {
	public static class Pair {
		int x;
		int y;

		public int hashCode() {
			return x + y;
		}

		public boolean equals(Object obj) {
			if (obj instanceof Pair) {
				Pair other = (Pair) obj;
				return this.x == other.x && this.y == other.y;
			}
			return false;
		}

		public String toString() {
			return "[x=" + x + ", y=" + y + "]";
		}
		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static String fun0(Pair xy, int n, Map<Pair, String> visited) {
//		System.out.println(visited);
		Map<Pair, String> visited1 = new HashMap();
		for (Entry<Pair, String> e : visited.entrySet()) {
			Pair old = e.getKey();
			String s = e.getValue();
			{
				Pair pairE = new Pair(old.x + n, old.y);
				String sE = s + "E";
				if (visited.containsKey(pairE) == false) {
					if (xy.equals(pairE)) {
						return sE;
					} else {
						visited1.put(pairE, sE);
					}
				}
			}
			{
				Pair pairW = new Pair(old.x - n, old.y);
				String sW = s + "W";
				if (visited.containsKey(pairW) == false) {
					if (xy.equals(pairW)) {
						return sW;
					} else {
						visited1.put(pairW, sW);
					}
				}
			}
			{
				Pair pairN = new Pair(old.x, old.y + n);
				String sN = s + "N";
				if (visited.containsKey(pairN) == false) {
					if (xy.equals(pairN)) {
						return sN;
					} else {
						visited1.put(pairN, sN);
					}
				}
			}
			{
				Pair pairS = new Pair(old.x, old.y - n);
				String sS = s + "S";
				if (visited.containsKey(pairS) == false) {
					if (xy.equals(pairS)) {
						return sS;
					} else {
						visited1.put(pairS, sS);
					}
				}
			}
		}

		return fun0(xy, n + 1, visited1);
	}

	public static String fun(int x, int y) {
		Map<Pair, String> initial = new HashMap();
		initial.put(new Pair(0, 0), new String());
		return fun0(new Pair(x, y), 1, initial);
	}

	public static void main(String[] args) throws IOException {
		String filename = args[0];
		BufferedReader in = new BufferedReader(new FileReader(filename));
		PrintStream out = new PrintStream(filename + ".out");
		int stages = Integer.parseInt(in.readLine());
		for (int stage = 1; stage <= stages; ++stage) {
//			System.out.println("stage: " + stage);
			String[] tokens = in.readLine().split("\\s+");
			int x = Integer.parseInt(tokens[0]);
			int y = Integer.parseInt(tokens[1]);
			out.printf("Case #%d: %s\n", stage, fun(x, y));
		}
	}
}
