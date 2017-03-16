import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt(); in.nextLine();
		for (int i = 1; i <= T; i++) {
			String[] data = in.nextLine().split(" ");
			int nval = solve(data[0], Integer.parseInt(data[1]));
			System.out.println("Case #" + i + ": " + nval);
		}
		in.close();
	}

	private static int solve(String string, int n) {
		//System.out.println("nval of " + string + " and n=" + n);
		for (int i = 0; i <= string.length() - n; i++) {
			if (nConsecutiveConsonants(string, i, n)) {
				int substringStart = i;
				int substringEnd = i + n - 1;
				int partialSol = (substringStart + 1) * (string.length() - substringEnd);
				return partialSol + solve(string.substring(i + 1), n);
			}
		}
		return 0;
	}

	private static boolean nConsecutiveConsonants(String string, int i, int n) {
		for (int j = 0; j < n; j++) {
			char c = string.charAt(i + j);
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				return false;
		}
		return true;
	}
}
