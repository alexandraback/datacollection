import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Technobabble {
	
	private void solve(File in, File out) throws FileNotFoundException {
		Scanner s = new Scanner(in);
		PrintWriter pw = new PrintWriter(out);
		int T = s.nextInt();
		for (int i = 0; i < T; i++) {
			int N = s.nextInt();
			String[] x = new String[N];
			String[] y = new String[N];
			for (int j = 0; j < x.length; j++) {
				x[j] = s.next();
				y[j] = s.next();
			}
			pw.println("Case #" + (i+1) + ": " + solve(x, y));
		}
		pw.flush();
		pw.close();
	}
	
	private String solve(String[] x, String[] y) {
		boolean[] fake = new boolean[x.length];
		int c = 0;
		boolean is = false;
		for (int i = 0; i < x.length; i++) {
			is = false;
			for (int j = 0; j < y.length; j++) {
				if (is) {
					break;
				}
				for (int k = 0; k < y.length; k++) {
					if (is) {
						break;
					}
					if (i == j || i == k || j == k) {
						continue;
					}
					if (x[i].equals(x[j]) && y[i].equals(y[k])) {
						if (fake[i]) {
							continue;
						}
						c++;
						fake[j] = true;
						fake[k] = true;
						is = true;
					}
				}			
			}
		}
		return c + "";
	}

	public static void main(String[] args) throws FileNotFoundException {
		File in = new File("in.txt");
		File out = new File("out.txt");
		Technobabble t = new Technobabble();
		t.solve(in, out);
	}

}
