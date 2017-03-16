package codejam;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

public class Main implements Runnable {
	Scanner sc;
	private boolean debug = false;

	/***************************************************************************/

	void solve() {
		int x = sc.nextInt();
		int y = sc.nextInt();
		int ship = sc.nextInt();
		int sc = x * (y / ship);
		// sc - 1
		if (y % ship == 0)
			System.out.print(sc + ship - 1);
		else
			System.out.print(sc + ship);
	}

	/***************************************************************************/

	@Override
	public void run() {
		Locale.setDefault(Locale.US);
		sc = new Scanner(System.in);
		if (!debug) {
			try {
				sc = new Scanner(new FileInputStream("C:\\Users\\Aesma\\Desktop\\in.in"));
				System.setOut(new PrintStream(new FileOutputStream("C:\\Users\\Aesma\\Desktop\\out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
				System.exit(0);
			}
		}

		int cn = sc.nextInt();
		for (int ca = 1; ca <= cn; ca++) {
			System.out.print("Case #" + ca + ": ");
			solve();
			System.out.println();
			System.err.println("Solved case #" + ca);
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
}