import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author Mark Devine
 * 
 */
public class C {
	static final boolean DEBUG = false;
	static Scanner in;
	static List<PrintStream> out;

	public static void main(String[] args) throws FileNotFoundException {
		out = new ArrayList<>();
		out.add(System.out);
		if (DEBUG) {
			in = new Scanner(new File("t"));
		} else {
			in = new Scanner(new File(C.class.getName() + ".in"));
			out.add(new PrintStream(C.class.getName() + ".out"));
		}
		int T = i();
		for (int i = 0; i < T; i++) {
			pf("Case #%d: %s\n", i + 1, solve());
		}
		System.out.println("Done");
		in.close();
		for (PrintStream ps : out) {
			ps.close();
		}
	}

	static String solve() {
		 int groups = i();
     double slowest = 0;
     double fastest = Double.MAX_VALUE;
     int hikers = 0;
		 for (int i = 0; i < groups; i++) {
		   int pos = i();
		   int num = i();
		   int minTime = i();
		   for (int j = 0; j < num; j++) {
		     hikers ++;
		     int time = minTime + j;
		     double remaining = ((double)time) * (((double)pos/360));
		     slowest = Math.max(slowest, remaining);
		     fastest = Math.min(fastest, (remaining + time));
		   }
		 }
		 if (hikers <= 1) {
		   return "0";
		 }
		 return slowest <= fastest ? "0" : "1";
	}

	static void p(String x) {
		for (PrintStream ps : out) {
			ps.print(x);
		}
	}

	static void pl(String x) {
		for (PrintStream ps : out) {
			ps.println(x);
		}
	}

	static void pf(String format, Object... args) {
		for (PrintStream ps : out) {
			ps.printf(format, args);
		}
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