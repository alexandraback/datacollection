
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemA2 {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new FileInputStream(new File("A-small-attempt11b.in")));
		// Scanner sc = new Scanner(System.in);
		int t = Integer.parseInt(sc.nextLine());
		int tindex = 1;
		String[] chars = new String[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT",
				"NINE" };
		while (t-- > 0) {
			String s = sc.nextLine();
			String result = "";
			while (s.length() > 0) {
				boolean removed = false;
				// System.out.println(s);
				if (s.contains("U")) {
					result += 4;
					s = remove(s, chars[4]);
					removed = true;
				}
				if (s.contains("W")) {
					result += 2;
					s = remove(s, chars[2]);
					removed = true;
				}
				if (s.contains("X")) {
					result += 6;
					s = remove(s, chars[6]);
					removed = true;
				}
				if (s.contains("Z")) {
					result += 0;
					s = remove(s, chars[0]);
					removed = true;
				}
				if (!removed)
					break;
			}
			while (s.length() > 0) {
				boolean removed = false;
				// System.out.println(s);
				if (s.contains("F")) {
					result += 5;
					s = remove(s, chars[5]);
					removed = true;
				}
				if (s.contains("S")) {
					result += 7;
					s = remove(s, chars[7]);
					removed = true;
				}
				if (s.contains("R")) {
					result += 3;
					s = remove(s, chars[3]);
					removed = true;
				}
				if (s.contains("O")) {
					result += 1;
					s = remove(s, chars[1]);
					removed = true;
				}
				if (!removed)
					break;
			}
			while (s.length() > 0) {
				boolean removed = false;
				// System.out.println(s);
				if (s.contains("H")) {
					result += 8;
					s = remove(s, chars[8]);
					removed = true;
				}
				if (s.contains("T")) {
					result += 8;
					s = remove(s, chars[8]);
					removed = true;
				}

				if (!removed)
					break;
			}
			while (s.length() > 0) {
				boolean removed = false;
				// System.out.println(s);
				if (s.contains("I")) {
					result += 9;
					s = remove(s, chars[9]);
					removed = true;
				}
				if (s.contains("N")) {
					result += 9;
					s = remove(s, chars[9]);
					removed = true;
				}

				if (!removed)
					break;
			}
			while (s.length() > 0) {
				boolean removed = false;
				// System.out.println(s);
				if (s.contains("E")) {
					result += 7;
					s = remove(s, chars[7]);
					removed = true;
				}
				if (s.contains("V")) {
					result += 7;
					s = remove(s, chars[7]);
					removed = true;
				}

				if (!removed)
					break;
			}
			char[] a = result.toCharArray();
			Arrays.sort(a);
			;

			System.out.println("Case #" + tindex++ + ": " + new String(a));
		}

	}

	private static String remove(String s, String toremove) {
		for (char c1 : toremove.toCharArray()) {
			s = s.replaceFirst("" + c1, "");
		}
		return s;
	}

}
