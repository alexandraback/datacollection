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
			int K = scan.nextInt(), C = scan.nextInt(), S = scan.nextInt();
			StringBuilder ans = new StringBuilder();
			for(int i=1;i<=S;i++) {
				ans.append(i).append(" ");
			}
			out.printf("Case #%d: %S%n", t, ans.toString().trim());
		}
		scan.close();
		out.close();
	}
}
