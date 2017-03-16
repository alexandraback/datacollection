import java.util.*;
import java.io.*;

public class FallingDiamonds {
	private static final Pair[] L = {
		new Pair(0, 0), new Pair(-2, 0), new Pair(-1, 1), new Pair(2, 0), new Pair(1, 1),
		new Pair(0, 2), new Pair(-4, 0), new Pair(-3, 1), new Pair(-2, 2), new Pair(-1, 3),
		new Pair(4, 0), new Pair(3, 1), new Pair(2, 2), new Pair(1, 3), new Pair(0, 4),
		new Pair(-6, 0), new Pair(-5, 1), new Pair(-4, 2), new Pair(-3, 3), new Pair(-2, 4),
		new Pair(-1, 5), new Pair(6, 0), new Pair(5, 1), new Pair(4, 2), new Pair(3, 3)
	};
	
	private static final Pair[] R = {
		new Pair(0, 0), new Pair(2, 0), new Pair(1, 1), new Pair(-2, 0), new Pair(-1, 1),
		new Pair(0, 2), new Pair(4, 0), new Pair(3, 1), new Pair(2, 2), new Pair(1, 3),
		new Pair(-4, 0), new Pair(-3, 1), new Pair(-2, 2), new Pair(-1, 3), new Pair(0, 4),
		new Pair(6, 0), new Pair(5, 1), new Pair(4, 2), new Pair(3, 3), new Pair(2, 4),
		new Pair(1, 5), new Pair(-6, 0), new Pair(-5, 1), new Pair(-4, 2), new Pair(-3, 3)
	};
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("B-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-small-attempt0.out")));
		
		int numTests = sc.nextInt();
		for (int numCases = 1; numCases <= numTests; numCases++) {
			int n = sc.nextInt();
			int x = sc.nextInt();
			int y = sc.nextInt();
			
			int count = 0;
			for (int state = 0; state < (1 << n); state++) {
				TreeSet <Pair> set = new TreeSet <Pair> ();
				for (int i = 0; i < n; i++) {
					if (((state >> i) & 1) == 1) {
						Pair curr = goLeft(set);
						if (curr.x == x && curr.y == y) {
							count++;
							break;
						}
						set.add(curr);
					} else {
						Pair curr = goRight(set);
						if (curr.x == x && curr.y == y) {
							count++;
							break;
						}
						set.add(curr);
					}
				}
			}
			
			out.println("Case #" + numCases + ": " + ((double)count / (1 << n)));
		}
		
		out.flush();
		out.close();
	}
	
	private static Pair goLeft(TreeSet <Pair> set) {
		for (int i = 0; i < L.length; i++) {
			if (!set.contains(L[i])) {
				return L[i];
			}
		}
		return null;
	}
	
	private static Pair goRight(TreeSet <Pair> set) {
		for (int i = 0; i < R.length; i++) {
			if (!set.contains(R[i])) {
				return R[i];
			}
		}
		return null;
	}
	
	private static class Pair implements Comparable <Pair> {
		public int x, y;
		
		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
		public int compareTo(Pair other) {
			if (x != other.x) {
				return x - other.x;
			}
			return y - other.y;
		}
	}
}
