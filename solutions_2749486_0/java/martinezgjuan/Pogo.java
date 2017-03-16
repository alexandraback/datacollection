import java.util.Scanner;

public class Pogo {

	public static String reach(int jump, int pos, int goal, String dir) {
		if (pos + jump == goal)
			return dir.charAt(1) + "";
		else if (pos + jump > goal)
			return dir.charAt(0) + reach(jump + 1, pos - jump, goal, dir);
		else
			return dir.charAt(1) + reach(jump + 1, pos + jump, goal, dir);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int caze = 1; caze <= T; caze++) {
			int X = sc.nextInt();
			int Y = sc.nextInt();

			String jumps = "";
			if (X != 0)
				jumps += reach(1, 0, Math.abs(X), X > 0 ? "WE" : "EW");
			if (Y != 0)
				jumps += reach(jumps.length() + 1, 0, Math.abs(Y), Y > 0 ? "SN" : "NS");
			System.out.printf("Case #%d: %s\n", caze, jumps);
		}
	}

}
