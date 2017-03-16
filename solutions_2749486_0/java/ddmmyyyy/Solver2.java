package ddmmyyyy;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class Solver2 {

	private int x;
	private int y;
	private String result;

	public Solver2(int x, int y) {
		this.x = x;
		this.y = y;
		StringBuilder b = new StringBuilder();
		if (x > 0) {
			for (int i = 0; i < x; i++) {
				b.append("WE");
			}
		} else {
			for (int i = 0; i > x; i--) {
				b.append("EW");
			}
		}
		if (y > 0) {
			for (int i = 0; i < y; i++) {
				b.append("SN");
			}
		} else {
			for (int i = 0; i > y; i--) {
				b.append("NS");
			}
		}
		this.result = b.toString();
	}

	private String getResult() {
		return this.result;
	}

	public static final String DIR = "C:\\Users\\Nick\\development\\codejam\\2013\\round1c\\files\\";
	public static final String FILE = "B-small-attempt0";
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
			final Solver2 solver = new Solver2(Integer.parseInt(split[0]), Integer.parseInt(split[1]));
			bw.printf("Case #%d: %s\n", i+1, solver.getResult());
//			if (i%10==0) System.out.printf("Done #%d, ", i+1);
		}
		reader.close();
	}
}
