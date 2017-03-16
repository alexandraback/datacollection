import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {

	public static int f(int x, int min, int max) {
		String s = Integer.toString(x);
		String s2 = null;

		Set<Integer> set = new HashSet<Integer>();
		for (int i = 1; i < s.length(); i++) {
			s2 = s.substring(i) + s.substring(0, i);
			if (Integer.valueOf(s2) > x && Integer.valueOf(s2) <= max && Integer.toString(Integer.valueOf(s2)).length() == s.length()) {
				set.add(Integer.valueOf(s2));
			}
		}
		return set.size();
	}

	public static void main(String[] args) throws Exception {
		System.setOut(new PrintStream("zz"));

		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		for (int t = 1; t <= T; t++) {
			int A = s.nextInt();
			int B = s.nextInt();

			System.err.println(t);
			int n = 0;
			for (int x = A; x < B; x++) {
				n += f(x, A, B);
			}
			System.out.println("Case #" + t + ": " + n);
		}

	}
}
