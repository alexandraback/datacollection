import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	public final static String IN_FILE = "A-small-attempt1.in";
	public final static String OUT_FILE = "A-small-attempt1.out";

	private static Scanner IN;

	public static void main(String[] args) throws Exception {
		char[] cc = new char[1000];

		map(cc, "ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
		map(cc, "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
		map(cc, "de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");

		cc['q'] = 'z';
		cc['z'] = 'q';

		// for (char i = 'a'; i <= 'z'; i++) {
		// System.out.println(i + " " + cc[i]);
		// }

		InputStream in = new FileInputStream(IN_FILE);
		PrintWriter out = new PrintWriter(new FileWriter(OUT_FILE));
		IN = new Scanner(in);

		int T = IN.nextInt();
		IN.nextLine();
		for (int t = 1; t <= T; t++) {
			String s = IN.nextLine();
			String r = "";
			for (char c : s.toCharArray()) {
				r += cc[c];
			}

			out.println("Case #" + t + ": " + r);
		}

		out.flush();
		out.close();
		in.close();
	}

	private static void map(char[] cc, String s1, String s2) {
		char[] c1 = s1.toCharArray();
		char[] c2 = s2.toCharArray();

		for (int i = 0; i < c1.length; i++) {
			cc[c1[i]] = c2[i];
		}
	}
}
