package googlejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class RecycledNumbers {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("inputC.txt"));
		PrintWriter pw = new PrintWriter("outputC.txt");
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			int count = count(sc.nextInt(), sc.nextInt());
			pw.println("Case #" + t + ": " + count);
		}
		pw.flush();
		pw.close();
	}

	public static int count(int A, int B) {
		int res = 0;
		Set<Integer> a = new HashSet<Integer>();
		for (int i = A; i < B; ++i) {
			a.clear();
			String n = Integer.toString(i);
			for (int start = 1; start < n.length(); ++start) {
				if (n.charAt(start) == '0') {
					continue;
				}
				int m = 0;
				for (int d = 0; d < n.length(); ++d) {
					m *= 10;
					m += n.charAt((start + d) % n.length()) - '0';
				}
				if (m > i && m <= B && !a.contains(m)) {
					a.add(m);
					++res;
				}
			}
		}
		return res;
	}
}
