import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	private static char[] s;
	private static int n;

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader buf = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter writer = new PrintWriter(new File("Asmall.out"));
		int tcases = Integer.parseInt(buf.readLine());
		for (int t = 1; t <= tcases; t++) {
			StringTokenizer str = new StringTokenizer(buf.readLine());
			s = str.nextToken().toCharArray();
			n = Integer.parseInt(str.nextToken());
			int cnt = 0;
			for (int i = 0; i < s.length; i++)
				for (int j = i; j < s.length; j++)
					if (valid(i, j))
						cnt++;
			writer.printf("Case #%d: %d\n", t, cnt);
		}
		writer.close();
	}

	private static boolean valid(int i, int j) {
		int cnt = 0;
		for (int k = i; k <= j; k++) {
			if (isvowel(s[k]))
				cnt = 0;
			else {
				cnt++;
				if (cnt >= n)
					return true;
			}
		}
		return false;
	}

	private static boolean isvowel(char c) {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}
}
