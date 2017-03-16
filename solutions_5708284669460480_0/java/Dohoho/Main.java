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

	int ln;
	int tn;
	int wrsz;
	String kb;
	String word;
	StringBuilder curword;
	int maxb;
	int combos;
	int score;

	void doword(int n) {
		if (n == wrsz) {
			int thismaxb = 0;
			for (int s = 0; s <= wrsz - tn; s++) {
				String sub = curword.substring(s, s + tn);
				if (sub.equals(word.toString())) {
					thismaxb++;
				}
			}
			if (thismaxb > maxb)
				maxb = thismaxb;
			score += thismaxb;
			combos++;
		} else
			for (int i = 0; i < ln; i++) {
				curword.setCharAt(n, kb.charAt(i));
				doword(n + 1);
			}
	}

	void solve() {
		ln = sc.nextInt();
		tn = sc.nextInt();
		wrsz = sc.nextInt();
		kb = sc.next();
		word = sc.next();
		curword = new StringBuilder(wrsz);
		for (int i = 0; i < wrsz; i++)
			curword.append("a");
		maxb = 0;
		score = 0;
		combos = 0;
		doword(0);
		System.out.print(maxb - ((double)score)/combos);
		/*System.out.println(score);
		System.out.println(combos);
		System.out.println(maxb);*/
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