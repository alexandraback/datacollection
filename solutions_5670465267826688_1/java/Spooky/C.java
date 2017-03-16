package qual2015;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class C
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("C.out"));
	
		L : for (int t = Integer.valueOf(in.nextLine()), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			
			int l = in.nextInt();
			long x = in.nextLong();
			char[] ss = in.next().toCharArray();
			
			int[] a = new int[l+1];
			a[0] = 1;
			for (int i = 1; i <= l; i++) {
				int cur = a[i-1];
				a[i] = cur/Math.abs(cur)*map[Math.abs(cur)][get(ss[i-1])];
			}
			
			int[] b = new int[l+1];
			b[l] = 1;
			for (int i = l-1; i >= 0; i--) {
				int cur = b[i+1];
				b[i] = cur/Math.abs(cur)*map[get(ss[i])][Math.abs(cur)];
			}

			int r = a[l];
			for (int i = 1; i <= l; i++) {
				for (int j = 0; j < l; j++) {
					int aa = canMake(1, a[i], get('i'), r);
					if (aa == -1) continue;
					int cc = canMake(b[j], 1, get('k'), r);
					if (cc == -1) continue;
					
					int add;
					int bb;
					if (i < j) {
						if (calc(a, i+1, j) == get('j')) {
							bb = 0;
							add = 1;
						} else {
							bb = canMake(b[i], a[j], get('j'), r);
							add = 2;
						}
					} else {
						bb = canMake(b[i], a[j], get('j'), r);
						add = 2;
					}
					if (bb == -1) continue;
					
					if (aa + bb + cc + add > x || (aa + bb + cc + add - x)%4 != 0) {
						continue;
					}
					
					out.println("YES");
					continue L;
				}
			}
			
			out.println("NO");
		}
		
		out.flush();
	}
	
	static int canMake(int u, int v, int x, int y) {
		int m = 1;
		for (int i = 0; i < 4; i++) {
			if (calc(calc(u, m), v) == x) return i;
			m = calc(m, y);
		}
		return -1;
	}
	
	static int calc(int x, int y) {
		return (x/Math.abs(x))*(y/Math.abs(y))*map[Math.abs(x)][Math.abs(y)];
	}
	
	static int calc2(int x, int y) {
		return (x/Math.abs(x))*(y/Math.abs(y))*map2[Math.abs(x)][Math.abs(y)];
	}
	
	static int calc(int[] a, int f, int t) {
		int x = a[f-1];
		int y = a[t];
		return calc2(x, y);
	}
	
	static int get(char c) {
		if (c == 'i') return 2;
		else if (c == 'j') return 3;
		else if (c == 'k') return 4;
		return -1;
	}
	
	static int[][] map = {
		{0, 0, 0, 0, 0},
		{0, 1, 2, 3, 4},
		{0, 2, -1, 4, -3},
		{0, 3, -4, -1, 2},
		{0, 4, 3, -2, -1}
	};
	
	static int[][] map2 = {
		{0, 0, 0, 0, 0},
		{0, 1, 2, 3, 4},
		{0, -2, 1, -4, 3},
		{0, -3, 4, 1, -2},
		{0, -4, -3, 2, 1}
	};
}
