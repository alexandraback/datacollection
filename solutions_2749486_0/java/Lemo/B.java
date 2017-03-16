import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class B {

	final static String PREFIX = ".\\src\\B";
//	final static String FILE_NAME = PREFIX + "-test";
	final static String FILE_NAME = PREFIX + "-small-attempt0";
//	final static String FILE_NAME = PREFIX + "-large";

	private Scanner in;
	private PrintWriter out;

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new B().solveAll();
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
		int destX = in.nextInt();
		int destY = in.nextInt();
		
		StringBuilder sb = new StringBuilder();
		
		if(destX > 0) {
			for(int i = 0; i < destX; i++) {
				sb.append("WE");
			}
		} else {
			for(int i = 0; i < -destX; i++) {
				sb.append("EW");
			}
		}
		
		if(destY > 0) {
			for(int i = 0; i < destY; i++) {
				sb.append("SN");
			}
		} else {
			for(int i = 0; i < -destY; i++) {
				sb.append("NS");
			}
		}
		print("Case #%d: %s\n", tc, sb.toString());
//		System.out.println(sb.length());
	}

	private void print(String format, Object ... args) {
		out.format(format, args);
		System.out.format(format, args);
	}
}
