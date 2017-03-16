import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Enclosure {

	static {
		try {
			String input = "C-small-attempt2.in";
			String output = input.substring(0, input.lastIndexOf('.')) + ".out";
			System.setIn(new FileInputStream(input));
			System.setOut(new PrintStream(new FileOutputStream(output), true));
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(0);
		}
	}

	public static void main(String[] args) {
		try {
			Scanner input = new Scanner(System.in);
			for (int T = input.nextInt(), t = 1; t <= T; t++) {
				int n = input.nextInt();
				int m = input.nextInt();
				int k = input.nextInt();
				int s = Integer.MAX_VALUE;
				if (k > 4 && n > 1 && m > 1) {
					for (int i = n; i > 0; i--)
						for (int j = m; j > 0; j--)
							if (i * j >= k)
								s = Math.min(s, ((i + j) << 1) - 4);
					for (int x = 1; x <= 4; x++) {
						for (int i = n; i > 0; i--)
							for (int j = m; j > 0; j--)
								if (i * j - x >= k)
									s = Math.min(s, ((i + j) << 1) - 4 - x);
					}
				} else {
					s = k;
				}
				// System.out.println(n + " " + m + " " + k);
				System.out.printf("Case #%d: %d\n", t, s);
			}
			input.close();
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	static int calc0(int i, int j) {
		return (i * j) + ((i + j) << 1);
	}

}
