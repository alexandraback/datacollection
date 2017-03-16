import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		int t = in.nextInt();

		in.nextLine();

		for (int testCase = 1; testCase <= t; testCase++) {

			String scores = in.nextLine();
			String c = scores.split(" ")[0];
			String j = scores.split(" ")[1];

			int minDiff = Integer.MAX_VALUE;
			int minC = Integer.MAX_VALUE;
			int minJ = Integer.MAX_VALUE;

			int finalC = 0;
			int finalJ = 0;

			int countC = c.length() - c.replace("?", "").length();
			int countJ = j.length() - j.replace("?", "").length();

			for (int i = 0; i < Math.pow(10, countC); i++) {
				for (int k = 0; k < Math.pow(10, countJ); k++) {

					int numberC = arrayToNumber(c, i, countC);
					int numberJ = arrayToNumber(j, k, countJ);

					int diff = Math.abs(numberJ - numberC);
					if (diff < minDiff) {
						minDiff = diff;
						finalC = numberC;
						finalJ = numberJ;
					} else if (diff == minDiff) {
						if (numberC < finalC) {
							finalC = numberC;
							finalJ = numberJ;
						} else if (numberC == finalC) {
							if (numberJ < finalJ) {
								finalC = numberC;
								finalJ = numberJ;
							}
						}
					}
				}
			}

			System.out.println("Case #" + testCase + ": " 
					+ String.format("%" + c.length() + "s", finalC).replace(' ', '0')
					+ " "
					+ String.format("%" + j.length() + "s", finalJ).replace(' ', '0'));

		}
	}

	private static int arrayToNumber(String score, int n, int count) {
		
		if (count == 0) return Integer.parseInt(score);

		String number = score;
		String[] digits = String.format("%" + count + "s", n).replace(' ', '0')
				.split("");

		for (int i = 0; i < digits.length; i++) {
			if (number.contains("?")) {
				number = number.replaceFirst("\\?", digits[i]);
			}
		}

		return Integer.parseInt(number);
	}

}
