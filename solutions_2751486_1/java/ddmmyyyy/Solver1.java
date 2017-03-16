package ddmmyyyy;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;

public class Solver1 {

	private String name;
	private int n;
	private BigInteger result = new BigInteger("0");

	public Solver1(String name, int n) {
		this.name = name.toLowerCase();
		this.n = n;

		int l = this.name.length();
		boolean[] vowels = new boolean[l];
		for (int i = 0; i < l; i++) {
			char charAtI = this.name.charAt(i);
			vowels[i] = (charAtI == 'a' || charAtI == 'e' || charAtI == 'i' || charAtI == 'o' || charAtI == 'u');
		}

		//find the streaks of n
		int[] streakPosses = new int[l];
		int streak = 0, j=0;
		for (int i = 0; i < l; i++) {
			if (!vowels[i]) {
				streak++;
				if (streak >= n) {
					streakPosses[j++] = i-n+1;
				}
			}
			else streak = 0;
		}

		for (int i = 0; i < j; i++) {
			int s = streakPosses[i];
			int sPrev = i==0? -1 : streakPosses[i-1];
			String ss = "" + ((l-(s+n)+1));
			String sss = "" + (s-sPrev);
			this.result = this.result.add(new BigInteger(ss).multiply(new BigInteger(sss)));
		}
	}

	private BigInteger getResult() {
		return this.result;
	}

	public static final String DIR = "C:\\Users\\Nick\\development\\codejam\\2013\\round1c\\files\\";
//	public static final String FILE = "A-sample";
	public static final String FILE = "A-large";

	public static void main(String args[]) throws IOException {
		//read T (number of lines)
		final InputStreamReader isr = new FileReader(new File(DIR + FILE + ".in"));
//		final InputStreamReader isr = new InputStreamReader(System.in);
		final PrintStream bw = new PrintStream(new File(DIR + FILE + ".out"));
//		final PrintStream bw = new PrintStream(System.out);
		final BufferedReader reader = new BufferedReader(isr);
		final int t = Integer.parseInt(reader.readLine());
		for (int i = 0; i < t; i++) {
			String line = reader.readLine();
			String[] split = line.split(" ");
			final Solver1 solver = new Solver1(split[0], Integer.parseInt(split[1]));
			bw.printf("Case #%d: %s\n", i+1, solver.getResult());
//			if (i%10==0) System.out.printf("Done #%d, ", i+1);
		}
		reader.close();
	}
}
