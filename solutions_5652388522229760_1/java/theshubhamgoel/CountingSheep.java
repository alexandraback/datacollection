import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class CountingSheep {

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int n, a, b = 1;
		int digit[] = new int[10];
		n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			a = Integer.parseInt(br.readLine().trim());
			if (a == 0) {
				pw.println("Case #" + (i + 1) + ": INSOMNIA");
				continue;
			}

			Arrays.fill(digit, 0);
			int x = 1;
			while (!checkAlldigit(digit)) {
				b = a * x;
				String y = "" + b;
				for (int j = 0; j < y.length(); j++) {
					digit[y.charAt(j) - 48]++;
				}
				x++;
			}
			pw.println("Case #" + (i + 1) + ": " + b);
		}
		pw.flush();
	}

	private static boolean checkAlldigit(int[] digit) {
		for (int i = 0; i < digit.length; i++) {
			if (digit[i] == 0)
				return false;
		}
		return true;
	}

}
