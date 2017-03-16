import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class A {
//	 static PrintStream writer = System.out;

	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		Scanner sc = new Scanner(new File("./src/A-large.in"));
		int t = sc.nextInt();
		PrintWriter writer = new PrintWriter("./src/A-large.out", "UTF-8");

		for (int k = 1; k <= t; k++) {
			writer.print("Case #" + k + ": ");
			String s = sc.next();
			String ans = "";
			String ans2 = "";
			int large = 0;
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) >= s.charAt(large)) {
					large = i;
					ans = ans + s.charAt(i);
				} else
					ans2 = ans2 + s.charAt(i);
			}
			writer.println(new StringBuilder(ans).reverse().toString() + ans2);
		}
		writer.close();
		sc.close();
	}
}
