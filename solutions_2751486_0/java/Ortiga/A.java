import java.awt.Point;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;

public class A {
	HashSet<String> map = new HashSet<String>(10000000);
	static ArrayList<Point> valid = new ArrayList<Point>(10000);

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(
				new FileInputStream("A.txt")));
		PrintWriter out = new PrintWriter("Ao.txt");
		int t = Integer.parseInt(in.readLine());
		for (int i = 1; i <= t; i++) {
			StringTokenizer to = new StringTokenizer(in.readLine(), " ");
			String s = to.nextToken();
			int n = Integer.parseInt(to.nextToken());
			long val = 0;
			int l = s.length();
			valid.clear();
			for (int j = l - 1; j >= 0; j--) {
				int x = 0;
				while (j >= 0 && s.charAt(j) != 'a' && s.charAt(j) != 'e'
						&& s.charAt(j) != 'i' && s.charAt(j) != 'o'
						&& s.charAt(j) != 'u') {
					x++;
					if (x >= n) {
						valid.add(new Point(j, j + n - 1));
					}
					j--;
				}
			}
			int siz = valid.size();
			for (int j = 0; j < l; j++) {
				for (int k = j; k < l; k++) {
					if (k - j >= n - 1)
						for (int m = 0; m < siz; m++) {
							if (j <= valid.get(m).x && k >= valid.get(m).y) {
								val++;
								break;
							}

						}
				}
			}
			// val--;
			out.println("Case #" + i + ": " + val);
		}
		in.close();
		out.close();
	}
}
