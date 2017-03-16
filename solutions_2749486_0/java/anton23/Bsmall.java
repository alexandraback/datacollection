import java.util.Scanner;

public class Bsmall {
	int X, Y;

	public String solve(Scanner sc) {
		X = sc.nextInt();
		Y = sc.nextInt();
		if (X == 0 && Y == 0) {
			return "";
		}
		String ret = "";
		if (X > 0) {
			ret += new String(new char[X]).replace("\0", "WE");
		} 
		if (X < 0) {
			ret += new String(new char[-X]).replace("\0", "EW");
		}
		if (Y > 0) {
			ret += new String(new char[Y]).replace("\0", "SN");
		} 
		if (Y < 0) {
			ret += new String(new char[-Y]).replace("\0", "NS");
		}
		return ret;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			System.out.println("Case #" + i + ": " + new Bsmall().solve(sc));
		}
	}
}
