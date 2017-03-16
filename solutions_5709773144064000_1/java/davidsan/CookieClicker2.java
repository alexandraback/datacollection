package codejam;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

public class CookieClicker2 {

	int T;
	List<List<Double>> tests;
	StringBuilder result;

	public CookieClicker2(String filename) {
		super();
		tests = new ArrayList<List<Double>>();
		try {
			readFile(filename);
		} catch (IOException e) {
			e.printStackTrace();
		}

		result = new StringBuilder();
		computeResult();
	}

	public void readFile(String filename) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(filename));
		String line = br.readLine();
		T = Integer.parseInt(line);

		try {
			for (int cpt = 0; cpt < T; cpt++) {
				line = br.readLine();
				String[] param = line.split(" ");
				List<Double> l = new ArrayList<Double>();
				for (int j = 0; j < param.length; j++) {
					l.add(Double.parseDouble(param[j]));
				}
				tests.add(l);
			}
		} finally {
			br.close();
		}

	}

	public void computeResult() {
		for (int numTest = 0; numTest < T; numTest++) {
			Double C = tests.get(numTest).get(0);
			Double F = tests.get(numTest).get(1);
			Double X = tests.get(numTest).get(2);

			Double cookies = 0.0;
			Double cps = 2.0;
			Double time = 0.0;
			while (cookies < X) {
				Double objectif = X - cookies;
				Double cps1 = cps;
				Double cps2 = cps + F;
				Double tps1 = objectif / cps1;
				Double tps2 = (objectif / cps2) + ((C - cookies) / cps1);
				if (tps1 > tps2) {
					// doit acheter
					time += ((C - cookies) / cps1);
					cps += F;
				} else {
					// ne doit pas acheter, mais attends la fin
					cookies += objectif;
					time += tps1;
					break;
				}
			}
			result.append("Case #");
			result.append(numTest + 1);
			result.append(": ");
			result.append(String.format(Locale.ENGLISH, "%.7f", time));
			result.append(System.lineSeparator());
		}
	}

	public static void main(String[] args) {
		CookieClicker2 mt = new CookieClicker2(args[0]);
		// Gson g = new Gson();
		// System.err.println(g.toJson(mt.tests));
		// System.out.println(mt.result.toString());
		PrintWriter writer;
		try {
			writer = new PrintWriter(args[0].substring(0,
					args[0].lastIndexOf('.'))
					+ ".out", "UTF-8");
			writer.println(mt.result.toString());
			writer.close();
		} catch (FileNotFoundException | UnsupportedEncodingException e) {
			e.printStackTrace();
		}
	}
}
