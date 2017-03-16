import java.util.Scanner;
import java.util.regex.Pattern;

/**
 * Created by Kevin_2 on 5/11/14.
 */
public class Round1C_A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());

		for (int i = 0; i < T; i++) {

			String[] line = sc.nextLine().split("/");

			int n = Integer.parseInt(line[0]);
			int d = Integer.parseInt(line[1]);


			int result = result(n, d);

			System.out.println("Case #" + (i+1) + ": " + (result == -1 ? "impossible" : result));
		}
	}

	private static int result(int n, int d) {
		String binN = Integer.toBinaryString(n);
		String binD = Integer.toBinaryString(d);

		if (!Pattern.matches("10*", binD)) {
			return -1;
		}

		return binD.length() - binN.length();
	}
}
