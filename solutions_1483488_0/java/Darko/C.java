import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {

	private void work() throws IOException {

		Scanner sc = new Scanner(new FileReader("C-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("C-small-attempt0.out"));
		Set<Integer> set = new HashSet<Integer>();
		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int len = Integer.toString(a).length();
			char[] c = new char[len];
			int res = 0;
			for (int i = a; i <= b; i++) {
				set.clear();
				int t = i;
				for (int j = len - 1; j >= 0; j--) {
					c[j] = (char) (t % 10 + '0');
					t /= 10;
				}
				for (int j = 0; j < len - 1; j++) {
					char tmp = c[len - 1];
					for (int k = len - 1; k > 0; k--) {
						c[k] = c[k - 1];
					}
					c[0] = tmp;
					int blah = Integer.valueOf(new String(c));
					if (blah > i && blah <= b)
						set.add(blah);
				}
				res += set.size();
			}
			pw.printf("Case #%d: %d\n", tc, res);
		}
		pw.close();
	}

	public static void main(String[] args) throws IOException {
		new C().work();
	}

}
