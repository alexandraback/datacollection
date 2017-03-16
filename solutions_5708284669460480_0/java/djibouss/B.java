package gcj1C;

import java.io.*;
import java.util.*;

public class B {
	static PrintWriter writer;
	static Scanner sc;

	public static void main(String[] args) throws FileNotFoundException {
		writer = new PrintWriter("output");
		solveAllTests();
		writer.close();
		sc.close();
	}

	private static void solveAllTests() throws FileNotFoundException {
		sc = new Scanner(new File("input"));
		int nbTest = sc.nextInt();
		for (int i = 1; i <= nbTest; i++) {
			int K = sc.nextInt();
			int L = sc.nextInt();
			int S = sc.nextInt();
			String keyboard = sc.next();
			String target = sc.next();
			double res = solveOneTest(K, L, S, keyboard, target);
			writer.println("Case #" + i + ": " + res);
		}
	}

	private static double solveOneTest(int k, int l, int s, String keyboard,
			String target) {
		int nbPos = nbPos(k, s);
		int maxOc = 0;
		int sum = 0;
		for (int i = 0; i < nbPos; i++) {
			String curString = buildString(i, keyboard, k, s);
			int oc = countOc(curString, target, l, s);
			sum += oc;
			if (oc > maxOc) {
				maxOc = oc;
			}
		}
		double givenB = sum;
		givenB /= nbPos;
		return maxOc - givenB;
	}

	private static int countOc(String curString, String target, int l, int s) {
		int res = 0;
		for (int b = 0; b + l <= s; b++) {
			String sub = curString.substring(b, b + l);
			if (sub.equals(target)) {
				res++;
			}
		}
		return res;
	}

	private static String buildString(int nb, String keyboard, int k, int s) {
		StringBuilder res = new StringBuilder();
		for (int i = 0; i < s; i++) {
			int nextCharInd = nb % k;
			nb /= k;
			res.append(keyboard.charAt(nextCharInd));
		}
		return res.toString();
	}

	private static int nbPos(int k, int s) {
		int res = 1;
		for (int i = 0; i < s; i++) {
			res *= k;
		}
		return res;
	}
}