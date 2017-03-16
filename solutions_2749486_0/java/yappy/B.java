import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class B {

	static class Node {
		int x, y;
		String path;

		public Node(int x, int y, String path) {
			this.x = x;
			this.y = y;
			this.path = path;
		}

		@Override
		public int hashCode() {
			return (x << 16) | y;
		}

		@Override
		public boolean equals(Object obj) {
			Node on = (Node) obj;
			return x == on.x && y == on.y;
		}

		@Override
		public String toString() {
			return String.format("[%d, %d]", x, y);
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();

		final int[] DX = new int[] { 0, 0, 1, -1 };
		final int[] DY = new int[] { 1, -1, 0, 0 };
		final char[] P = new char[] { 'N', 'S', 'E', 'W' };

		for (int no = 1; no <= T; no++) {
			int X = in.nextInt();
			int Y = in.nextInt();

			Set<Node> ns = new HashSet<>();
			ns.add(new Node(0, 0, ""));
			LOOP: for (int i = 1;; i++) {
				// System.err.println(ns);
				Set<Node> next = new HashSet<>(ns.size() * 4);
				for (Node n : ns) {
					for (int k = 0; k < 4; k++) {
						int nx = n.x + DX[k] * i;
						int ny = n.y + DY[k] * i;
						String np = n.path + P[k];
						Node nn = new Node(nx, ny, np);
						next.add(nn);
						if (nx == X && ny == Y) {
							System.out.printf("Case #%d: %s%n", no, np);
							break LOOP;
						}
					}
				}
				ns.clear();
				ns.addAll(next);
			}
		}
	}

}
