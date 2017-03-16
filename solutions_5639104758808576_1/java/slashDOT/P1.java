import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class P1 {
	
	private static final String FILE_PREFIX = "A-large";
	
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File(FILE_PREFIX + ".in"));
		PrintWriter writer = new PrintWriter(new File(FILE_PREFIX + ".out"));
		int T = scanner.nextInt();
		for (int i=0; i<T; i++) {
			int Sm = scanner.nextInt();
			int r = 0, g = 0;
			String m = scanner.next();
			for (int j=0; j<Sm+1; j++) {
				int x = ((int) m.charAt(j)) - 48;
				if ((g+r) < j) r += (j - (g+r));
				g += x;
			}
			writer.println("Case #" + (i+1) + ": " + r);
		}
		scanner.close();
		writer.close();
	}
}
