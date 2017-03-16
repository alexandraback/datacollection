package qualifiers;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Locale;
import java.util.Scanner;

public class D {
	final static Boolean DEBUG_ENABLE = true;
	final static Boolean TIMER_ENABLE = true;

	final static String FILE_NAME = "D-large";// <<<--------

	final static String BASE = "C:/CodeJam/" + FILE_NAME;
	final static String INPUT = BASE + ".in";
	final static String OUTPUT = BASE + ".out";
	static Scanner in;
	static PrintWriter out;

	public static void main(String[] args) {
		try {
			in = new Scanner(new FileReader(INPUT));
			in.useLocale(Locale.US);
			out = new PrintWriter(OUTPUT);

			int number_of_cases = in.nextInt();
			in.nextLine();
			for (int c = 0; c < number_of_cases; c++) {
				out.print("Case #" + (c + 1) + ": ");

				if (DEBUG_ENABLE)
					System.out.println("Solving case " + (c + 1) + "...");
				if (TIMER_ENABLE) {
					long startTime = System.currentTimeMillis();
					caseSolver();
					long endTime = System.currentTimeMillis();
					System.out.println((endTime - startTime) + " ms");
				} else
					caseSolver();

				out.println();
			}
			out.println();
			out.flush();
			out.close();
			in.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void caseSolver() {
		int N = in.nextInt();
		ArrayList<Double> naomi = new ArrayList<Double>(N);
		ArrayList<Double> ken = new ArrayList<Double>(N);
		ArrayList<Double> naomid = new ArrayList<Double>(N);
		ArrayList<Double> kend = new ArrayList<Double>(N);
		int war = 0;
		int ward = 0;

		for (int i = 0; i < N; i++) {
			double temp = in.nextDouble();
			naomi.add(temp);
			naomid.add(temp);
		}
		for (int i = 0; i < N; i++) {
			double temp = in.nextDouble();
			ken.add(temp);
			kend.add(temp);
		}

		Collections.sort(naomi);
		Collections.sort(naomid);
		Collections.sort(ken);
		Collections.sort(kend);

		while (!naomi.isEmpty()) {
			// ken plays his smallest until he is able to win the round,
			// if ken have k blocks heavier then naomi's biggest, doesn't matter
			// which one he plays, then, doesn't matter naomi's order, let's
			// choose the easiest one
			int last_index = naomi.size() - 1;
			if (naomi.get(last_index) > ken.get(last_index)) {
				war++;
				naomi.remove(last_index);
				ken.remove(0);
			} else {
				naomi.remove(last_index);
				ken.remove(last_index);
			}
		}

		int i = 0;
		finish:
		while (i < naomid.size()) {
			// ken plays his smallest until he is able to win the round
			// so naomi just have to kite his smallest blocks, by telling a
			// weight higher than ken's biggest
			while (naomid.get(i) < kend.get(0)){
				i++;
				if(i >= naomid.size()) break finish;
			}
			naomid.remove(i);
			kend.remove(0);
			ward++;
		}
		
		out.print(ward + " " + war);
	}
}
