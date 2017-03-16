import java.io.*;
import java.util.*;

public class A {

	public static boolean vis[][] = new boolean[201][201];
	public static String ans[][] = new String[201][201];
	public static int q[][] = new int[200 * 300][3];
	public static int x1, y1, r, l;

	public static void push(int x, int y, int move, String s) {
		if ((x >= 0) && (y >= 0) && (x <= 200) && (y <= 200) && (!vis[x][y])) {
			r++;
			q[r][0] = x;
			q[r][1] = y;
			q[r][2] = move;
			ans[x][y] = s;
			vis[x][y] = true;
		}
	}
	
	public static int[] pop() {
		l++;
		return q[l - 1];
	}
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("B-small-attempt1.in"));
		PrintWriter out = new PrintWriter(new File("output.txt"));
		//Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		
		int[] u = new int[3];
		int t = in.nextInt();
		for (int _t = 1; _t <= t; _t++) {
			x1 = in.nextInt() + 100;
			y1 = in.nextInt() + 100;
			for (int i = 0; i < 201; i++)
				for (int j = 0; j < 201; j++) {
					vis[i][j] = false;
					ans[i][j] = "";
				}
			r = 0;
			l = 1;
			push(100, 100, 0, "");
			while (l <= r) {
				u = pop();
				push(u[0] + u[2] + 1, u[1], u[2] + 1, ans[u[0]][u[1]] + "E");
				push(u[0] - u[2] - 1, u[1], u[2] + 1, ans[u[0]][u[1]] + "W");
				push(u[0], u[1] + u[2] + 1, u[2] + 1, ans[u[0]][u[1]] + "N");
				push(u[0], u[1] - u[2] - 1, u[2] + 1, ans[u[0]][u[1]] + "S");
			}
			out.println("Case #" + _t + ": " + ans[x1][y1]);
		}
		
		in.close();
		out.close();
	}

}
