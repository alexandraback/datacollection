import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Scanner;

public class C {

	final static String PREFIX = ".\\src\\C";
//	final static String FILE_NAME = PREFIX + "-test";
	final static String FILE_NAME = PREFIX + "-small-attempt0";
//	final static String FILE_NAME = PREFIX + "-large";

	private Scanner in;
	private PrintWriter out;

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new C().solveAll();
	}


	private void solveAll() throws Exception {
		in = new Scanner(new File(FILE_NAME + ".in"));
		out = new PrintWriter(new File(FILE_NAME + ".out"));
		
		// generate fair & square
		long max = 10000000;
		res = new ArrayList<Long>();
		for(long i = 1; i < max; i++) {
			long val = i * i;
			if(isPalindrom(i) && isPalindrom(val)) {
				res.add(val);
				System.out.println("Adding " + i + " ^2 = " + val);
			}
		}
		System.out.println(res);
		System.out.println(res.size());
		
		int tcn = in.nextInt();
		for (int tc = 1; tc <= tcn; tc++) {
			solve(tc);
		}
		out.close();
	}

	int N;
	int M;
	private ArrayList<Long> res;

	private void solve(int tc) {
		N = in.nextInt();
		M = in.nextInt();
		int count = 0;
		for(long l : res) {
			if(l >= N && l <= M) {
				count++;
			}
		}
		print("Case #%d: %d\n", tc, count);
	}

	private static boolean isPalindrom(long val) {
		String s = String.valueOf(val);
		int N = s.length();
		for(int i = 0; i < (N/2); i++) {
			if(s.charAt(i) != s.charAt(N - 1 -i))
				return false;
		}
		return true;
	}

	private void print(String format, Object ... args) {
		out.format(format, args);
		System.out.format(format, args);
	}
}
