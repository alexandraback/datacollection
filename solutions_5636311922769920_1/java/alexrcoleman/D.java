import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(new FileInputStream(new File("D.in")));
		PrintWriter out = new PrintWriter(new FileOutputStream(new File("D.out")));
		int T = scan.nextInt();
		for (int t = 1; t <= T; t++) {
			int k = scan.nextInt(), c = scan.nextInt(), s = scan.nextInt();
			int covered = 0;
			int used = 0;
			StringBuilder ans = new StringBuilder();
			while (covered < k) {
				long at = 0;
				for (int i = 0; i < c; i++) {
					at *= k;
					if (covered < k)
						at += covered;
					else
						at += k-1;
					covered++;
				}
				used++;
				ans.append(at + 1).append(" ");
			}
			String str = "IMPOSSIBLE";
			if (used <= s)
				str = ans.toString().trim();
			out.printf("Case #%d: %s%n", t, str);
		}
		scan.close();
		out.close();
	}
}
