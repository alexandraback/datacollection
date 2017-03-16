import java.util.Scanner;


public class C {

	static int mi(int i) {
		return i ^ 4;
	}
	
	static final int ONE = 0, I = 1, J = 2, K = 3, MI_ONE = 4, MI_I = 5, MI_J = 6, MI_K = 7;
	
	static int[][] table = {
		{ONE, I, J, K},
		{I, MI_ONE, K, MI_J},
		{J, MI_K, MI_ONE, I},
		{K, J, MI_I, MI_ONE}
	};

	static int[][] TAB = new int[8][8];
	
	static {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (i < 4 && j < 4)
					TAB[i][j] = table[i][j];
				else if (i >= 4 && j >= 4) {
					TAB[i][j] = table[i&3][j&3];
				} else {
					TAB[i][j] = mi(table[i&3][j&3]);
				}
			}
		}
	}
	
	static int calcIC(int a, char b) {
		int b1 = b == '1' ? 0 : b - 'h';
		return TAB[a][b1];
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			long L = sc.nextLong();
			long X = sc.nextLong();
			String s = sc.next();
			if (X >= 20) {
				X %= 4;
				X += 16;
			}
			String ss = "";
			for (int i = 0; i < X; i++)
				ss += s;
			
			boolean res = solve(ss);
			
			System.out.printf("Case #%d: %s\n", t, res ? "YES" : "NO");
		}
	}

	private static boolean solve(String ss) {
		int ipos = -1;
		int ri = ONE;
		for (int i = 0 ; i < ss.length(); i++) {
			ri = calcIC(ri, ss.charAt(i));
			if (ri == I) {
				ipos = i+1; break;
			}
		}
		if (ipos == -1) return false;

		int jpos = -1;
		int rj = ONE;
		for (int i = ipos ; i < ss.length(); i++) {
			rj = calcIC(rj, ss.charAt(i));
			if (rj == J) {
				jpos = i+1; break;
			}
		}
		if (jpos == -1) return false;
		
		int rk = ONE;
		for (int i = jpos; i < ss.length(); i++) {
			rk = calcIC(rk, ss.charAt(i));
		}
		
		return (rk == K);
	}
}
