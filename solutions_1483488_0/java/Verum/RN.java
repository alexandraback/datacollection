import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class RN {

	static ArrayList<Character> str2list(String s) {
		ArrayList<Character> r = new ArrayList<Character>();
		for (char c : s.toCharArray()) {
			r.add(c);
		}
		return r;
	}

	static String list2str(ArrayList<Character> cs) {
		StringBuilder builder = new StringBuilder(cs.size());
		for (Character c : cs)
			builder.append(c);
		return builder.toString();
	}

	static ArrayList<String> cycles(String s) {
		ArrayList<Character> cs = str2list(s);

		ArrayList<String> res = new ArrayList<String>();

		for (int i = 0; i < cs.size(); i++) {
			Collections.rotate(cs, 1);
			res.add(list2str(cs));
		}
		
		HashSet<String> hs = new HashSet<String>(res);
		return new ArrayList<String>(hs);
	}

	static void log(String fs, Object... args) {
		System.err.println(String.format(fs, args));
	}

	public static void main(String[] args) throws FileNotFoundException {
		String filename = "src/C-small-attempt0.in";
		Scanner sc = 
				new Scanner(
						new FileInputStream(
								new File(filename)));
		PrintWriter pw = 
				new PrintWriter(
						new FileOutputStream(
								new File(filename + ".result")));

		int N = sc.nextInt();
		for (int task = 1; task <= N; task++) {
			int A = sc.nextInt();
			int B = sc.nextInt();

			int cnt = 0;
			for (int i = A; i <= B; i++) {
				String s = Integer.toString(i);
				for (String r : cycles(s)) {
					int n = Integer.parseInt(r);
					if (n >= A && n <= B && r.charAt(0) != '0' && !r.equals(s)) {
						cnt++;
					}
				}
			}
			pw.println(String.format("Case #%d: %d", task, cnt / 2));
		}
		pw.close();
	}

}
