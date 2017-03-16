import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class B {

	static int x, y;
	static int[] dx = { 0, 0, 1, -1 };
	static int[] dy = { 1, -1, 0, 0 };
	static char[] ch = { 'N', 'S', 'E', 'W' };

	static class node {
		int x, y, p;
		char c;
		node pr;
	}

	static Stack<Character> bfs() {
		HashSet<String> v = new HashSet<String>();
		Queue<node> q = new LinkedList<node>();
		node s = new node();
		s.x = 0;
		s.y = 0;
		s.p = 0;
		s.c = '0';
		s.pr = null;
		q.add(s);
		v.add("0 0 0");
		while (!q.isEmpty()) {
			node t = q.poll();
			if (t.x == x && t.y == y) {
				Stack<Character> st = new Stack<Character>();
				while (t.pr != null) {
					st.push(t.c);
					t = t.pr;
				}
				return st;
			}
			for (int i = 0; i < 4; i++) {
				int nx = t.x + (t.p + 1) * dx[i];
				int ny = t.y + (t.p + 1) * dy[i];
				String st = nx + " " + ny + " " + (t.p + 1);
				if (!v.contains(st)) {
					v.add(st);
					s = new node();
					s.x = nx;
					s.y = ny;
					s.p = t.p + 1;
					s.pr = t;
					s.c = ch[i];
					q.add(s);
				}
			}
		}
		return null;
	}

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("B.in"));
		PrintWriter out = new PrintWriter("B.out");
		sc = new StringTokenizer(br.readLine());
		int tc = nxtInt();
		for (int t = 1; t <= tc; t++) {
			x = nxtInt();
			y = nxtInt();
			Stack<Character> st = bfs();
			out.print("Case #" + t + ": ");
			while (!st.isEmpty())
				out.print(st.pop());
			out.println();
		}
		br.close();
		out.close();
	}

	static BufferedReader br;

	static StringTokenizer sc;

	static String nxtTok() throws IOException {
		while (!sc.hasMoreTokens()) {
			String s = br.readLine();
			if (s == null)
				return null;
			sc = new StringTokenizer(s.trim());
		}
		return sc.nextToken();
	}

	static int nxtInt() throws IOException {
		return Integer.parseInt(nxtTok());
	}

	static long nxtLng() throws IOException {
		return Long.parseLong(nxtTok());
	}
}