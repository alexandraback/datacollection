import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.PriorityQueue;
import java.util.Scanner;
public class B {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		int tc = sc.nextInt();
		PriorityQueue<Node> pq = new PriorityQueue<Node>();
		for (int it = 1; it <= tc; it++) {
			int n = sc.nextInt(), m = sc.nextInt();
			pq.clear();
			int[][] a = new int[n][m];
			boolean[][] v = new boolean[n][m];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					a[i][j] = sc.nextInt();
					pq.add(new Node(i, j, a[i][j]));
				}
			boolean can = true;
			while (!pq.isEmpty()) {
				Node node = pq.poll();
				int r = node.x, c = node.y, d = node.d;
				if (v[r][c])	continue;
				boolean check = true;
				for (int j = 0; j < m; j++)
					if (v[r][j] || a[r][j] <= d) {} else {
						check = false;
					}
				if (check) {
					for (int j = 0; j < m; j++)
						v[r][j] = true;
					continue;
				}
				check = true;
				for (int j = 0; j < n; j++) 
					if (v[j][c] || a[j][c] <= d) {} else {
						check = false;
					}
				if (check) {
					for (int j = 0; j < n; j++)
						v[j][c] = true;
					continue;
				}
				can = false;
				break;
			}
			if (can)
				System.out.printf("Case #%d: YES\n", it);
			else
				System.out.printf("Case #%d: NO\n", it);
		}
	}
}
class Node implements Comparable<Node> {
	int x, y, d;
	public Node(int xx, int yy, int dd) {
		x = xx;
		y = yy;
		d = dd;
	}
	@Override
	public int compareTo(Node o) {
		return d - o.d;
	}
}
