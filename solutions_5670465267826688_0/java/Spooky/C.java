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
			
			int l = in.nextInt(), x = in.nextInt(), k = l*x;
			String s = in.next();
			char[] ss = new char[k];
			for (int i = 0; i < k; i++) ss[i] = s.charAt(i % l);
			
			int cur = 1;
			int[] a = new int[k];
			for (int i = 0; i < k; i++) {
				a[i] = cur/Math.abs(cur)*map[Math.abs(cur)][get(ss[i])];
				cur = a[i];
			}
			
			cur = 1;
			int[] b = new int[k];
			for (int i = k-1; i >= 0; i--) {
				b[i] = cur/Math.abs(cur)*map[get(ss[i])][Math.abs(cur)];
				cur = b[i];
			}
			
			for (int i = 0; i < k; i++) {
				for (int j = i+2; j < k; j++) {
					if (a[i] == 2 && b[j] == 4) {
						if (calc(a, i+1, j-1) == 3) {
							out.println("YES");
							continue L;
						}
					}
				}
			}
			
			out.println("NO");
		}
		
		out.flush();
	}
	
	static int calc(int[] a, int f, int t) {
		int x = a[f-1];
		int y = a[t];
		return -(x/Math.abs(x))*(y/Math.abs(y))*map[Math.abs(x)][Math.abs(y)];
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
}
