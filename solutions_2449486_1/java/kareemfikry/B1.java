import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Set;


public class B1 {

	static class Pair {
		int x, y;

		Pair(int xx, int yy) {
			x = xx;
			y = yy;
		}
	}

	public static void main(String[] args) throws FileNotFoundException {

		Scanner r = new Scanner(new FileReader("B-large (2).in"));
		PrintWriter pw = new PrintWriter("B_.out");
		
		int cases = 0;
		int t = r.nextInt();

		end: while (t-- > 0) {
			int n = r.nextInt();
			int m = r.nextInt();

			int[][] a = new int[n][m];

			Set<Integer> set = new HashSet<Integer>();
			
			LinkedList<Pair>[] list = new LinkedList[101];
			for (int i = 0; i < list.length; i++) {
				list[i] = new LinkedList<Pair>();
			}

			int max = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					a[i][j] = r.nextInt();
					list[a[i][j]].add(new Pair(i, j));
					max = Math.max(max, a[i][j]);
					set.add(a[i][j]);
				}

			ArrayList<Integer> distincts = new ArrayList<Integer>();
			for (int e : set) distincts.add(e);
			
			Collections.sort(distincts, Collections.reverseOrder());
			boolean[][] vis = new boolean[n][m];

			for (int e : distincts) {
				for (Pair pair : list[e]) {
					int i = pair.x;
					int j = pair.y;
					if (a[i][j] == e) {
						boolean can1 = true, can2 = true;
						for (int jj = 0; jj < m; jj++)
							if (vis[i][jj]) {
								can1 = false;
								break;
							}
						for (int ii = 0; ii < n; ii++)
							if (vis[ii][j]) {
								can2 = false;
								break;
							}
						if (!can1 && !can2) {
							pw.printf("Case #%d: ", ++cases);
							pw.println("NO");
							continue end;
						}
					}
				}

				for (Pair pair : list[e]) {
					int i = pair.x;
					int j = pair.y;
					if (a[i][j] == e) {
						vis[i][j] = true;
					}
				}
			}

			pw.printf("Case #%d: ", ++cases);
			pw.println("YES");
		}
	
		pw.flush();
		pw.close();
	}
}
