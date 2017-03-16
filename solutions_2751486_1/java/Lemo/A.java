import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class A {

	final static String PREFIX = ".\\src\\A";
//	final static String FILE_NAME = PREFIX + "-test";
//	final static String FILE_NAME = PREFIX + "-small-attempt1";
	final static String FILE_NAME = PREFIX + "-large";

	private Scanner in;
	private PrintWriter out;
	private String s;
	private int n;
//	private int[] a;
	private int N;

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new A().solveAll();
	}

	private void solveAll() throws Exception {
		in = new Scanner(new File(FILE_NAME + ".in"));
		out = new PrintWriter(new File(FILE_NAME + ".out"));
		int tcn = in.nextInt();
		for (int tc = 1; tc <= tcn; tc++) {
			solve(tc);
		}
		out.close();
	}

	private void solve(int tc) {
		s = in.next();
		n = in.nextInt();
		N = s.length();
		
		List<Integer> pos = new ArrayList<Integer>();
		
		for(int i = 0; i < s.length(); i++) {
			if(isCorrect(i)) {
				pos.add(i);
			}
		}
		
		long r = 0;
		if(pos.size() == 0) {
			r = 0;
		};
		
		for(int i = 0; i < pos.size(); i++) {
			int p = pos.get(i);
			long le = 1 + p;
			int end = N - 1;
			if(i < pos.size() - 1) {
				int posNext = pos.get(i+1);
				end = posNext + n - 2;
			}
			long hi = 1 + end - (p + n - 1);
			if(hi <= 0) hi = 1;
			r += le * hi;
		}
		String res = r + "";// + pos;
		print("Case #%d: %s\n", tc, res);
	}

	private boolean isCorrect(int i) {
		if(i + n > s.length()) return false;
		
		for(int j = 0; j < n; j++) {
			char c = s.charAt(i + j);
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				return false;
			}
		}
		return true;
	}

	private void print(String format, Object ... args) {
		out.format(format, args);
		System.out.format(format, args);
	}
}
