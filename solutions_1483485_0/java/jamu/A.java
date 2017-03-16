import java.util.Locale;
import java.util.Scanner;

public class A {

	char[] map = new char[256];

	void solve(int icase) {
		String s = sline();
		printf("Case #%d: ", icase);
		for (int i = 0; i < s.length(); i++) {
			System.out.print(map[s.charAt(i)]);
		}
		printf("\n");
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new A().repSolve();
	}

	void repSolve() throws Exception {
		String in = "qz ejp mysljylc kd kxveddknmc re jsicpdrysi" + //
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" + //
				"de kr kd eoya kw aej tysr re ujdr lkgc jv";

		String out = "zq our language is impossible to understand" + //
				"there are twenty six factorial possibilities" + //
				"so it is okay if you want to just give up";

		for (int i = 0; i < in.length(); i++) {
			map[in.charAt(i)] = out.charAt(i);
		}

		scanner = new Scanner(System.in);
		// scanner = new Scanner(new java.io.File(""));
		int ncase = si();
		sline();
		for (int icase = 1; icase <= ncase; icase++) {
			solve(icase);
			System.err.println("[[ " + icase + " ]]");
		}
	}

	Scanner scanner;

	int si() {
		return scanner.nextInt();
	}

	long sl() {
		return scanner.nextLong();
	}

	String ss() {
		return scanner.next();
	}

	String sline() {
		return scanner.nextLine();
	}

	void printf(String format, Object... args) {
		System.out.printf(format, args);
	}

}
