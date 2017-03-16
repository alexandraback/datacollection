package round1c;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class B {
	Scanner sc;
	PrintWriter out;
	int x;
	int y;
	String sol = null;

	public static void main(String[] args) throws IOException {
		long iniTime = System.currentTimeMillis();
		
		Locale.setDefault(Locale.US);
		File in = new File("round1c/" + B.class.getSimpleName() + "1.in");
		File out = new File(in.getAbsolutePath().replace(".in", ".out"));
		new B(new Scanner(in), new PrintWriter(out)).solve();
		
		System.out.println("Time: " + (System.currentTimeMillis() - iniTime));
	}

	private void solveCase() throws IOException {
		x = sc.nextInt();
		y = sc.nextInt();
		
		sol = null;
		run(0, 0, "");
		
		out.println(sol);
		System.out.println(sol);
	}
	
	void run(int posx, int posy, String path) {
		if (path.length() <= 500 && (sol == null || path.length() < sol.length())) {
			if (posx == x && posy == y) {
				sol = path;
			} else {
				if (posx != x) {
					if (posx < x && x - posx >= path.length() + 1) {
						run(posx + path.length() + 1, posy, path + "E");
					} else {
						run(posx - path.length() - 1, posy, path + "W");
					}
				} else {
					if (posy < y && y - posy >= path.length() + 1) {
						run(posx, posy + path.length() + 1, path + "N");
					} else {
						run(posx, posy - path.length() - 1, path + "S");
					}
				}
			}
		}
	}

	public B(Scanner sc, PrintWriter out) {
		this.sc = sc;
		this.out = out;
	}

	public void solve() throws NumberFormatException, IOException {
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.printf("Case #%d: ", i);
			out.printf("Case #%d: ", i);
			solveCase();
		}

		sc.close();
		out.close();
	}
}