import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class A {
	private int T, N;
	private String str = null;
	private Scanner in = null;

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
			str = in.next();
			int ans = 0;
			int tmp = 0;
			for (int i = 0; i <= N; i++) {
				// System.out.format("now:%d must:%d%n",tmp,i);
				if (tmp < i) {
					ans += i - tmp;
					tmp = i;
				}
				tmp += Integer.valueOf(str.substring(i, i + 1));
			}
			System.out.println(ans);
		}
	}

}
