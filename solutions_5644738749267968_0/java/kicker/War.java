import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class War {

	Scanner sc = new Scanner(getClass().getResourceAsStream(IN));
	static final String FILENAME = "D-small-attempt1";
	static final String IN = FILENAME + ".in";
	static final String OUT = FILENAME + ".out";
	PrintStream out;

	private void solve() {
		int n = sc.nextInt();
		Double c = 0.0;
		List<Double> blocksNaomi = new ArrayList<>();
		List<Double> blocksKen = new ArrayList<>();
		int resWar = 0;
		int resDestWar = 0;
		Double extra = 2.0;
		sc.nextLine();
		for (int i = 0; i < n; i++) {
			c = sc.nextDouble();
			blocksNaomi.add(c);
		}
		sc.nextLine();
		for (int i = 0; i < n; i++) {
			c = sc.nextDouble();
			blocksKen.add(c);
		}

		Collections.sort(blocksNaomi, Collections.reverseOrder());
		Collections.sort(blocksKen, Collections.reverseOrder());
		resDestWar = getDestWarResult(blocksKen, blocksNaomi);
		resWar = getWarResult(blocksNaomi, blocksKen);
		out.print(resWar + " " + resDestWar);

	}

	private int getDestWarResult(List<Double> blocksKen, List<Double> blocksNaomi) {
		int resWar = 0;
		int indexNaomi = 0;
		int indexKan = 0;

		while (indexNaomi < blocksNaomi.size()) {

			if (blocksNaomi.get(indexNaomi) > blocksKen.get(indexKan)) {
				resWar++;
				indexNaomi++;

			} else {
				indexNaomi++;
				indexKan++;
			}
		}
		return resWar;

	}

	private int getWarResult(List<Double> blocksNaomi, List<Double> blocksKen) {
		int resWar = 0;
		int indexNaomi = 0;
		int indexKan = 0;

		while (indexNaomi < blocksKen.size()) {

			if (blocksKen.get(indexNaomi) > blocksNaomi.get(indexKan)) {

				indexNaomi++;

			} else {
				indexNaomi++;
				indexKan++;
				resWar++;
			}
		}
		return resWar;

	}

	private void run() throws Exception {
		sc.useLocale(Locale.US);
		out = new PrintStream(new FileOutputStream(OUT));
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			sc.nextLine();
			out.print("Case #" + i + ": ");
			solve();
			out.println();
		}
		sc.close();
		out.close();
	}

	public static void main(String args[]) throws Exception {
		new War().run();
	}

}