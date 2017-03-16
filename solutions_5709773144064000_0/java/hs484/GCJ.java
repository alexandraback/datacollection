package gcj.Qual2014B;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;

public class GCJ {

	public static void tr(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}

	public static void main(String[] args) throws Throwable {
		String pkg = new Object(){}.getClass().getEnclosingClass().getPackage().getName().replace('.', '/');
		String dir = "src/" + pkg;

		String filename = "";

//		if (true) { filename = "sample.in"; }
		if (true) { filename = "B-small-attempt0.in"; }
//		if (true) { filename = "A-large-practice.in"; }

		Scanner sc = null;
		try {
			sc = new Scanner(new File(dir + "/" + filename));
		} catch (FileNotFoundException e) {
			tr(e.getMessage());
			return;
		}
		PrintWriter fout = new PrintWriter(new File(dir + "/" + filename + ".res"));

		GCJ obj = new GCJ();
		int TNO = sc.nextInt();
		for (int tno = 0; tno < TNO; tno++) {
			fout.write(String.format("Case #%d: ", (tno + 1)));
			obj.solve(sc, fout);
			fout.flush();
		}
		fout.flush();
		fout.close();
	}

	double C, F, X;
	void solve(Scanner sc, PrintWriter fout) {
		C = sc.nextDouble();
		F = sc.nextDouble();
		X = sc.nextDouble();



		int a = 0;
		int b = (int)(X + 1);
		for (int step = 0; step < 200; step++) {
		    int c1 = a + (b - a) / 3;
		    int c2 = b - (b - a) / 3;
		    if (f(c1) > f(c2)) a = c1; else b = c2; // max: < , min: >
		}

		double best = Long.MAX_VALUE;
		for (int x = a; x <= b; x++) {
			best = min(best, f(x));
		}
		fout.printf("%.8f\n", best);
	}

	double f(int build) {
		double time = 0;
		double gain = 2;
		for (int i = 0; i < build; i++) {
			time += C / gain;
			gain += F;
		}
		time += X / gain;
		return time;
	}
}
