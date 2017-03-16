import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class B {
	private int N, T;
	private Scanner in = null;
	private int[] a = null;

	void solve() {
		try {
			System.setIn(new FileInputStream("in"));
			System.setOut(new PrintStream("out"));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		in = new Scanner(System.in);
		T = in.nextInt();
		for (int testcase = 1; T > 0; T--, testcase++) {
			System.out.format("Case #%d: ", testcase);
			N = in.nextInt();
			a = new int[N];
			int max = 0;
			for (int i = 0; i < N; i++) {
				a[i] = in.nextInt();
				if (a[i] > max)
					max = a[i];
			}
			int ans = -1;
			for (int i = 1; i <= max; i++) {
				int tmp = 0;
				for (int j = 0; j < N; j++) {
					int delta = a[j] - i;
					if (delta <= 0)
						continue;
					tmp += (delta - 1) / i + 1;
				}
				if (ans == -1 || ans > tmp + i) {
					ans = tmp + i;
				}
			}
			System.out.println(ans);
		}
	}
}
