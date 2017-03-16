import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Alarge {
	private static char[] s;
	private static int n;

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader buf = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter writer = new PrintWriter(new File("Alarge.out"));
		int tcases = Integer.parseInt(buf.readLine());
		for (int t = 1; t <= tcases; t++) {
			StringTokenizer str = new StringTokenizer(buf.readLine());
			s = str.nextToken().toCharArray();
			n = Integer.parseInt(str.nextToken());
			long cnt = 0;
			int first = 0;
			int ptr1 = -1;
			int ptr2 = -1;
			for (int i = 0; i < s.length; i++) {
				if (isvowel(s[i])) {
					ptr1 = i;
					ptr2 = i;

				} else
					ptr2++;
				if (ptr2 - ptr1 == n) {
					long left = ptr1 - first + 1;
					long right = s.length - ptr2 - 1;
					cnt += (left + 1) * (right + 1);
					ptr1++;
					first = ptr1 + 1;
				}
			}
			writer.println("Case #" + t + ": " + cnt);
		}
		writer.close();
	}

	private static boolean isvowel(char c) {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}

}
