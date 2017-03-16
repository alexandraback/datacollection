import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;


public class D {
	
	static final int[] dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

	static class Omino {
		Pair[] coords;

		public Omino(Pair[] coords) {
			super();
			this.coords = coords;
			Arrays.sort(this.coords);
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + Arrays.hashCode(coords);
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			Omino other = (Omino) obj;
			return Arrays.equals(coords, other.coords);
		}
		
		@Override
		public String toString() {
			return Arrays.toString(coords);
		}
	}
	
	public static class Pair implements Comparable<Pair> {
		int i, j;

		public Pair(int i, int j) {
			super();
			this.i = i;
			this.j = j;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + i;
			result = prime * result + j;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			Pair other = (Pair) obj;
			if (i != other.i)
				return false;
			if (j != other.j)
				return false;
			return true;
		}

		@Override
		public int compareTo(Pair o) {
			if (i != o.i) return Integer.compare(i, o.i);
			return Integer.compare(j, o.j);
		}
		
		@Override
		public String toString() {
			return "(" + i + ":" + j + ")";
		}
	}

	static List<Collection<Omino>> ominons = new ArrayList<Collection<Omino>>();
	
	static {
		for (int i = 0; i < 7; i++) {
			ominons.add(new HashSet());
			if (i == 0) continue;
			
			Pair[] p = new Pair[i];
			p[0] = new Pair(0,0);
			fill(1, p);
			
//			System.out.println(ominons.get(i).size());
		}
	}
	
	
	static void fill(int i, Pair[] p) {
		if (i == p.length) {
			ominons.get(p.length).add(new Omino(p.clone()));
		} else {
			loop:
			for (int d = 0; d < dx.length; d++) {
				Pair prev = p[i-1];
				p[i] = new Pair(prev.i + dx[d], prev.j + dy[d]);
				for (int j = 0; j < i; j++) {
					if (p[i].equals(p[j]))
						continue loop; 
				}
				fill(i+1, p);
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			int X = sc.nextInt();
			int R = sc.nextInt();
			int C = sc.nextInt();
			
			Object res = solve(X, R, C);
			
			System.out.printf("Case #%d: %s\n", t, res);
		}
	}

	private static Object solve(int X, int R, int C) {
		if (X >= 7 || (R*C)%X != 0 || (X > R && X > C))
			return "RICHARD";

		if (X <= Math.min(R, C))
			return "GABRIEL";
		
		int[][] m1 = new int[R][C];
		int[][] m2 = new int[C][R];
		
		for (Omino om : ominons.get(X)) {
			if (poss(om, m1, R, C, X) || (R != C && poss(om, m2, C, R, X))) {
				//GABRIEL can do it
			} else {
				return "RICHARD";
			}
		}
		
		return "GABRIEL";
	}

	private static boolean poss(Omino om, int[][] m, int r, int c, int x) {
		for (int i = 0; i < r; i++) {
			l2:
			for (int j = 0; j < c; j++) {
				for (int[] is : m) Arrays.fill(is, 0);
				
				for (Pair p : om.coords) {
					int ii = p.i+i;
					int jj = p.j+j;
					if (ii >= 0 && ii < r && jj >= 0 && jj < c)
						m[ii][jj] = -1;
					else
						continue l2;
				}
				
//				System.out.println(Arrays.deepToString(m));
				
				for (int is = 0; is < r; is++) {
					for (int js = 0; js < c; js++) {
						if (m[is][js] == 0) {
							int cnt = dfs(m, is, js, r, c);
							if (cnt%x != 0)
								continue l2;
						}
					}
				}
				
				return true;
			}
		}
		return false;
	}

	private static int dfs(int[][] m, int i, int j, int r, int c) {
		if (i < 0 || j < 0 || i >= r || j >= c)
			return 0;
		if (m[i][j] != 0)
			return 0;
		
		m[i][j] = 1;
		int cnt = 1;
		
		for (int d = 0; d < dx.length; d++)
			cnt += dfs(m, i+dx[d], j+dy[d], r, c);
		
		return cnt;
	}

}
