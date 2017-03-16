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

	static int evaluateSign(String expr, long times) {
		if (times == 0)
			return 1;
		for (long i = 0; i < times - 1; i++) {
			expr += expr;
		}
//		System.out.println(expr);
		char last = expr.charAt(0);
		int sign = 1;
		for (int i = 1; i < expr.length(); i++) {
			char ch = expr.charAt(i);
			sign *= getSign(last, ch);
//			System.out.println(last+ " "+ ch);
			last = getChar(last, ch);
		}
		return sign;
	}

	static char evaluateChar(String expr, long times) {
		if (times == 0) {
			return '0';
		}
		for (long i = 0; i < times - 1; i++) {
			expr += expr;
		}
		char last = expr.charAt(0);
		for (int i = 1; i < expr.length(); i++) {
			char ch = expr.charAt(i);
			last = getChar(last, ch);
		}
		return last;
	}

	static boolean eveluateExpression(long X, String expr) {
		boolean allSame = true;
		for (int p = 1; p < expr.length(); p++) {
			allSame &= expr.charAt(p) == expr.charAt(p - 1);
		}
		if (allSame)
			return false;

		int sign = 1; // positive
		boolean foundI = false;
		boolean foundJ = false;
		boolean foundK = false;
		boolean success = false;
		char lastChar = '0';
		long count = 0;
		long itr = X < 1000 ? X : 1000;
		while (count < itr) {
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
			if (lastChar == '0' && (foundI && foundJ && foundK)) {
//				System.out.println(count);
				success = true;
				break;
			}
		}
		if (success) {
			long remaining = X % count;
			int remSign = evaluateSign(expr, remaining);
			char remCh = evaluateChar(expr, remaining);
			long times = X / count;

//			System.out.println(remaining+ " "+ times+" "+ remCh+" " +sign+" "+remSign);
			if (remCh != '0')
				return false;
			if (sign == -1) {
				// times does not matter. all you need is a '0' remchar and a -1 sign
				if (remSign == -1) {
					return true;
				}
			} else {
				if (times % 2 == 0) {
					if(remSign == -1) return true; 
				} else {
					return true;
				}
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
			scan.nextLong();
			long X = scan.nextLong();
			String expr = scan.next();
			boolean bool = eveluateExpression(X, expr);
			System.out.println("Case #" + count + ": " + (bool ? "YES" : "NO"));
		}
	}
}
