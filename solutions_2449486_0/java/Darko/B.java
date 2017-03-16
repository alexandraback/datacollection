import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class B {

	private void work() throws IOException {
		Scanner sc = new Scanner(new FileReader("B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("B-small-attempt0.out"));
		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			int m = sc.nextInt();
			int n = sc.nextInt();
			int[][] g = new int[m][n];
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					g[i][j] = sc.nextInt();
				}
			}
			boolean[] r = new boolean[m];
			boolean[] c = new boolean[n];
			boolean ok = true;
			Set<Integer> rset = new HashSet<Integer>();
			Set<Integer> cset = new HashSet<Integer>();
			for (int h = 1000; h > 0 && ok; h--) {
				rset.clear();
				cset.clear();
				for (int i = 0; i < m && ok; i++) {
					for (int j = 0; j < n; j++) {
						if (g[i][j] == h) {
							if (r[i] && c[j]) {
								ok = false;
								break;
							}
							rset.add(i);
							cset.add(j);
						}
					}
				}
				if (ok) {
					for (int x : rset)
						r[x] = true;
					for (int x : cset)
						c[x] = true;
				}
			}
			pw.printf("Case #%d: %s\n", tc, ok ? "YES" : "NO");
		}
		pw.close();
		sc.close();
	}

	public static void main(String[] args) throws IOException {
		B bbb = new B();
		bbb.work();
	}

}
