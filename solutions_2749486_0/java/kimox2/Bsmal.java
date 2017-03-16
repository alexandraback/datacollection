import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class Bsmal {

	public static int dx[] = { 0, 1, 0, -1 };
	public static int dy[] = { 1, 0, -1, 0 };
	public static int parent[] = new int[500];
	// public static ans=
	public static int x;
	public static int y;
	boolean found = false;

	// public static void dfs(int cx,int cy,int d,int count)
	// {
	// if(cx==x && cy==y &&count<500)
	// {
	//
	// }
	//
	// }
	public static char[] chars = { 'N', 'E', 'S', 'W' };

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader reader = new BufferedReader(new FileReader(new File(
				"tt.in")));

		int l = Integer.parseInt(reader.readLine());
		String st[];

		for (int cas = 1; cas <= l; cas++) {
			st = reader.readLine().split(" ");
			x = Integer.parseInt(st[0]);
			y = Integer.parseInt(st[1]);
			// HashSet<String>hs=new HashSet<String>()
			boolean v[][][] = new boolean[505][505][505];
			Queue<Integer> q = new LinkedList<Integer>();
			Queue<StringBuilder> q2 = new LinkedList<StringBuilder>();
			q.add(0);
			q.add(0);
			q.add(1);
			int curx = 0;
			int cury = 0;
			int d = 1;
			boolean found = false;
			StringBuilder ans = new StringBuilder();
			q2.add(new StringBuilder());
			while (!q.isEmpty()) {
				// System.out.println(q.toString());
				curx = q.poll();
				cury = q.poll();
				d = q.poll();
				ans = q2.poll();

				if (curx == x && cury == y) {

					break;
				}
				int nx = 0;
				int ny = 0;
				for (int i = 0; i < 4; i++) {
					nx = curx + dx[i] * d;
					ny = cury + dy[i] * d;
					//System.out.println(nx+" "+ny);
					if (!v[250+nx][250+ny][d + 1]) {
						q.add(nx);
						q.add(ny);
						q.add(d + 1);
						v[250+nx][250+ny][d + 1] = true;
						StringBuilder b = new StringBuilder(ans.toString());
						b.append(chars[i]);
						q2.add(b);
					}
				}

			}
			System.out.println("Case #" + cas + ": " + ans);
		}

	}
}
