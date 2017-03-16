import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class B {
	private static TreeSet<String> set;
	private static int x;
	private static int y;
	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, -1, 0, 1 };
	static String[] dirc = { "W", "S", "E", "N" };

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		set = new TreeSet<String>();
		 BufferedReader buf = new BufferedReader(new FileReader(
		 "B-small-attempt1.in"));
		PrintWriter writer = new PrintWriter(new File("Bsmall.out"));
//		BufferedReader buf = new BufferedReader(
//				new InputStreamReader(System.in));
		int tcases = Integer.parseInt(buf.readLine());
		for (int t = 1; t <= tcases; t++) {
			StringTokenizer str = new StringTokenizer(buf.readLine());
			x = Integer.parseInt(str.nextToken());
			y = Integer.parseInt(str.nextToken());
			System.out.println(t);
			String s = bfs();
			writer.println("Case #" + t + ": " + s.substring(1));
		}
		writer.close();
	}

	private static String bfs() {
		Queue<state> q = new LinkedList<B.state>();
		set.clear();
		q.add(new state(0, 0, "z"));
		while (!q.isEmpty()) {
			state s = q.poll();
			if (s.i == x && s.j == y) {
				return s.s;
			}
			if (s.s.length() > 500
					|| set.contains(s.i + " " + s.j + " " + s.s.length() + " "
							+ s.s.charAt(s.s.length() - 1)))
				continue;
			set.add(s.i + " " + s.j + " " + s.s.length() + " "
					+ s.s.charAt(s.s.length() - 1));

			int jump = s.s.length();
			for (int k = dx.length - 1; k >= 0; k--) {
				state newState = new state(s.i + jump * dx[k], s.j + jump
						* dy[k], s.s + dirc[k]);
				q.add(newState);
			}

		}
		return null;
	}

	static class state {
		int i;
		int j;
		String s;

		public state(int ii, int jj, String s) {
			i = ii;
			j = jj;
			this.s = s;
		}

	}
}
