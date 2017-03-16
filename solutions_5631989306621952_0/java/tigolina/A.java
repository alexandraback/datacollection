import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	private static Scanner in;
	private static PrintWriter out;
	private static final boolean USE_FILE = true;
	private static final String FILE_NAME = "A-small-attempt0";

	public static void main(String[] args) throws IOException {
		in = new Scanner(new BufferedReader(new InputStreamReader(USE_FILE ? new FileInputStream(FILE_NAME + ".in") : System.in)));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(USE_FILE ? new FileOutputStream(FILE_NAME + ".out") : System.out)));
		
		int testCount = in.nextInt();
		for (int test = 0; test < testCount; test++) {
			String s = in.next();
			
			solveCase(test, s);
		}
		
		in.close();
		out.close();
	}
	
	public static void solveCase(int test, String s) {
		String last = "" + s.charAt(0);
		for (int i = 1; i < s.length(); i++) {
			char c = s.charAt(i);
			if (c >= last.charAt(0)) {
				last = c + last;
			} else {
				last = last + c;
			}
		}
		out.println("Case #" + (test + 1) + ": " + last);
	}
}
