import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class A {

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream(new File("large_a.in")));
		System.setOut(new PrintStream(new File("large_a.out")));
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for (int t = 1; t <= T; t++) {
			String S = scan.next();
			String ret = "" + S.charAt(0);
			for (int i = 1; i < S.length(); i++) {
				String op1 = S.charAt(i) + ret;
				String op2 = ret + S.charAt(i);
				if (op1.compareTo(op2) > 0) {
					ret = op1;
				} else {
					ret = op2;
				}
			}
			System.out.println(String.format("Case #%s: %s", t, ret));
		}
	}
}
