import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class X {
	public static void main(String[] args) throws FileNotFoundException {
		new X().run();
	}
	
	private static final String FILE = "../C-large";
//	private static final String FILE = "../sample2";
	
	private Scanner scanner;
	private PrintWriter out;
	
	void run() throws FileNotFoundException {
		scanner = new Scanner(new File(FILE + ".in"));
		out = new PrintWriter(new File(FILE + ".out"));
		
		int n = scanner.nextInt();
		for (int i = 1; i <= n; i++) {
			solve(i);
		}
		
		scanner.close();
		out.close();
	}
	
	void solve(int index) {
		int length = scanner.nextInt();
		long repeat = scanner.nextLong();
		String s = scanner.next();
		
		StringBuilder sb = new StringBuilder();
		
		if (repeat > 8) {
			repeat = 8 + (repeat % 4);
		}
		
		for (int i = 0; i < repeat; i++) {
			sb.append(s);
		}
		
		String result = C.solve(sb.toString()) ? "YES" : "NO";
		
		out.println("Case #" + index + ": " + result);
		out.flush();
	}
}

