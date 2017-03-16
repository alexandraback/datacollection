import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Scanner;

/**
 * @author Mark Devine
 * 
 */
public class A {
	static final boolean DEBUG = false;
	static Scanner in;
	static PrintStream out;
	static final String[] samples = { "our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up" };
	static final String[] answers = { "ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv" };
	static HashMap<Character, Character> mappings;

	static void loadMappings() {
		mappings = new HashMap<Character, Character>();
		mappings.put('y','a');
		mappings.put('e','o');
		mappings.put('q','z');
		mappings.put('z','q');
		for (int i = 0; i < 3; i++) {
			String samp = samples[i];
			String ans = answers[i];
			for (int j = 0; j < samp.length(); j++) {
				mappings.put(ans.charAt(j), samp.charAt(j));
			}
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		if (DEBUG) {
			in = new Scanner(new File("t"));
			out = System.out;
		} else {
			in = new Scanner(new File(A.class.getName() + ".in"));
			out = new PrintStream(A.class.getName() + ".out");
		}
		loadMappings();
		int T = i();
		li();
		for (int i = 0; i < T; i++) {
			pl(f("Case #%d: %s", i + 1, solve()));
		}
		out.close();
		in.close();
		System.out.println("Done");
	}

	static String solve() {
		String line = li();
		char[] answer = new char[line.length()];
		for (int i = 0; i < line.length(); i++) {
			answer[i] = mappings.get(line.charAt(i));
		}
		return new String(answer);
	}

	static void p(String x) {
		out.print(x);
	}

	static void pl(String x) {
		out.println(x);
	}

	static String f(String format, Object... args) {
		return String.format(format, args);
	}

	static int i() {
		return in.nextInt();
	}

	static long l() {
		return in.nextLong();
	}

	static String s(String pattern) {
		return in.next(pattern);
	}

	static String li() {
		return in.nextLine();
	}
}