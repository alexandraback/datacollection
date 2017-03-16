import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class B {
	public static void run() throws IOException {
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("out.txt")));
		BufferedReader in = new BufferedReader(new FileReader("in.txt"));
		
		int caseN = Integer.parseInt(in.readLine());
		for (int caseIndex = 1; caseIndex <= caseN; caseIndex++) {
			String tokens[] = in.readLine().split(" ");
			int x = Integer.parseInt(tokens[0]);
			int y = Integer.parseInt(tokens[1]);
			out.println("Case #" + caseIndex + ": " + solve(x, y));
		}
		in.close();
		out.close();
	}
	
	private static String solve(int x, int y) {
		StringBuffer result = new StringBuffer();
		if (x > 0) {
			f(result, x, "WE");
		} else {
			f(result, -x, "EW");
		}
		if (y > 0) {
			f(result, y, "SN");
		} else {
			f(result, -y, "NS");
		}
		return result.toString();
	}
	
	private static void f(StringBuffer sb, int n, String s) {
		for (int i = 0; i < n; i++) {
			sb.append(s);
		}
	}
}
