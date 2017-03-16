import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class ProblemA {
	public static void main(String[] args) throws Exception {
		char[] mapping = new char[26];
		mapping['q' - 'a'] = 'z';
		mapping['y' - 'a'] = 'a';
		mapping['e' - 'a'] = 'o';
		mapping['z' - 'a'] = 'q';

		String[] ins = { "ejp mysljylc kd kxveddknmc re jsicpdrysi",
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
				"de kr kd eoya kw aej tysr re ujdr lkgc jv" };

		String[] outs = { "our language is impossible to understand",
				"there are twenty six factorial possibilities",
				"so it is okay if you want to just give up" };
		
		for (int i = 0; i < ins.length; i++) {
			for (int j = 0; j < ins[i].length(); j++) {
				if (outs[i].charAt(j) == ' ') continue;
				mapping[ins[i].charAt(j) - 'a'] = outs[i].charAt(j);
			}
		}
		
		Scanner in = new Scanner(
//				System.in
				new FileInputStream("a-small.in")
		);
		PrintStream out = new PrintStream(
//				System.out
				new FileOutputStream("a-small.out")
		);
		int N = in.nextInt();
		in.nextLine();
		
		for (int i = 1; i <= N; i++) {
			String res = "";
			for (char c : in.nextLine().toCharArray()) {
				if (c == ' ') res += " ";
				else res += mapping[c-'a'];
			}
			out.println("Case #" + i + ": " + res);
		}
	}
}
