import java.util.*;

public class P3 {
	public static final int[][] m = {{0, 0, 0, 0, 0},
									 {0, 1, 2, 3, 4}, 
									 {0, 2, -1, 4, -3}, 
									 {0, 3, -4, -1, 2}, 
									 {0, 4, 3, -2, -1}};
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int num = Integer.parseInt(in.nextLine());
		for (int i = 1; i <= num; i++) {
			String line = in.nextLine();
			int n = Integer.parseInt(line.substring(line.indexOf(" ") + 1));
			line = in.nextLine();
			String s = "";
			for (int j = 0; j < n; j++)
				s += line;
			
			boolean res = solve(s);
			System.out.println("Case #" + i + ": " + (res ? "YES" : "NO"));
		}
		in.close();
	}
	
	public static boolean solve(String s) {
		if (s.length() < 3)
			return false;
		
		int cur = 1;
		boolean negative = false;
	    for (int n = 0; n < s.length(); n++) {
	    	cur = m[cur][eval(s.charAt(n))];
			if (cur < 0) {
				negative = !negative;
				cur = -1 * cur;
			}
	    }
	    if (!negative || cur != 1)
	    	return false;
		
		int cur1 = 1;
		boolean negative1 = false;
		for (int i = 0; i < s.length() - 2; i++) {
			cur1 = m[cur1][eval(s.charAt(i))];
			if (cur1 < 0) {
				negative1 = !negative1;
				cur1 = -1 * cur1;
			}
			
			if (cur1 == 2) {
				int cur2 = 1;
				boolean negative2 = false;
				for (int j = i + 1; j < s.length() - 1; j++) {
					cur2 = m[cur2][eval(s.charAt(j))];
					if (cur2 < 0) {
						negative2 = !negative2;
						cur2 = -1 * cur2;
					}
					
					if (cur2 == 3) {
						int cur3 = 1;
						boolean negative3 = false;
						for (int k = j + 1; k < s.length(); k++) {
							cur3 = m[cur3][eval(s.charAt(k))];
							if (cur3 < 0) {
								negative3 = !negative3;
								cur3 = -1 * cur3;
							}
						}

						if (cur3 == 4) {
							if (!negative1 ^ negative2 ^ negative3)
								return true;
						}
					}
				}
			}
		}
		return false;
	}
	
	public static int eval(char c) {
		switch (c) {
		case '1':
			return 1;
		case 'i':
			return 2;
		case 'j':
			return 3;
		case 'k':
			return 4;
		default:
			return 0;
		}
	}
}
