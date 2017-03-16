import java.util.*;

public class P4 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int num = Integer.parseInt(in.nextLine());
		for (int i = 1; i <= num; i++) {
			String[] ss = in.nextLine().split(" ");
			int x = Integer.parseInt(ss[0]);
			int r = Integer.parseInt(ss[1]);
			int c = Integer.parseInt(ss[2]);
			
			String res = solve(x, r, c);
			System.out.println("Case #" + i + ": " + res);
		}
		in.close();
	}
	
	public static String solve(int x, int r, int c) {
		int s = Math.min(r,  c);
		int l = Math.max(r,  c);
		
		if ((s * l) % x != 0)
			return "RICHARD";
		if (l < x)
			return "RICHARD";
		if (x >= 8)
			return "RICHARD";
		if (s < (x + 1) / 2)
			return "RICHARD";
		if (x >= 4 && s <= (x + 1) / 2)
			return "RICHARD";
		
		return "GABRIEL";
	}
}
