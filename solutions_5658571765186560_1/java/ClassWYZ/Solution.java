import java.util.Scanner;


public class Solution {
	public static boolean judge(int x, int r, int c) {
		boolean res = true;
		
		if (x >= 7) res = false;
		else if (x > r && x > c) res = false;
		else if (r * c % x != 0) res = false;
		else if ((x + 1) / 2 > Math.min(r, c)) res = false;
		else if (x == 1 || x == 2 || x == 3) res = true;
		else if (x == 4) res = (Math.min(r,  c) > 2) ? true : false;
		else if (x == 5) res = ((Math.min(r,  c) == 3) && (Math.max(r,  c) == 5)) ? false : true;
		else if (x == 6) res = (Math.min(r,  c) > 3) ? true : false;
		
		return res;
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		in.nextLine();
		for (int i = 0; i < num; ++i) {
			int x = in.nextInt();
			int r = in.nextInt();
			int c = in.nextInt();
			in.nextLine();
			String winner = judge(x, r, c) ? "GABRIEL" : "RICHARD";
			System.out.println("Case #" + (i + 1) + ": " + winner);
		}
		in.close();
	}

}
