package cj;

import java.util.Scanner;

public class Dijkstra {

	static int getSign(char ch1, char ch2) {
		if (ch1 == '0')
			return 1;
		if ((ch1 == 'i' && ch2 == 'j') || (ch1 == 'j' && ch2 == 'k')
				|| (ch1 == 'k' && ch2 == 'i'))
			return 1;
		return -1;
	}

	static char getChar(char ch1, char ch2) {
		if (ch1 == '0')
			return ch2;
		if ((ch1 == 'i' && ch2 == 'j') || (ch1 == 'j' && ch2 == 'i'))
			return 'k';
		if ((ch1 == 'j' && ch2 == 'k') || (ch1 == 'k' && ch2 == 'j'))
			return 'i';
		if ((ch1 == 'k' && ch2 == 'i') || (ch1 == 'i' && ch2 == 'k'))
			return 'j';
		return '0';
	}

	static boolean eveluateExpression(long X, String expr) {
		int sign = 1; // positive
		boolean foundI = false;
		boolean foundJ = false;
		boolean foundK = false;
		char lastChar = '0';
		boolean success = false;
		long count = 0;
		while (true) {
			for (int p = 0; p < expr.length(); p++) {
				char ch = expr.charAt(p);
				if (!foundI) {
					if (ch == 'i' && lastChar == '0') {
						foundI = true;
					} else {
						sign *= getSign(lastChar, ch);
						lastChar = getChar(lastChar, ch);
						if (lastChar == 'i') {
							foundI = true;
							lastChar = '0';
						}
					}
				} else if (!foundJ) {
					if (ch == 'j' && lastChar == '0') {
						foundJ = true;
					} else {
						sign *= getSign(lastChar, ch);
						lastChar = getChar(lastChar, ch);
						if (lastChar == 'j') {
							foundJ = true;
							lastChar = '0';
						}
					}

				} else if (!foundK) {
					if (ch == 'k' && lastChar == '0') {
						foundK = true;
					} else {
						sign *= getSign(lastChar, ch);
						lastChar = getChar(lastChar, ch);
						if (lastChar == 'k') {
							foundK = true;
							lastChar = '0';
						}
					}
				} else {
					sign *= getSign(lastChar, ch);
					lastChar = getChar(lastChar, ch);
				}
			}
			count++;
			if (count == X) {
				break;
			}
		}

		if (lastChar == '0' && (foundI && foundJ && foundK)) {
			if (sign == 1) {
				return true;
			}
		}
		return false;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		int count = 0;
		while (T-- > 0) {
			count++;
			scan.nextInt();
			int X = scan.nextInt();
			String expr = scan.next();
			boolean bool = eveluateExpression(X, expr);
			System.out.println("Case #" + count + ": " + (bool ? "YES" : "NO"));
		}
	}
}
