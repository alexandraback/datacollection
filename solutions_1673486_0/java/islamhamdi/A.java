package CodeJam2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Vector;

public class A {
	public static void main(String[] args) throws IOException {
		FileReader in = new FileReader("A-small-attempt0.in");
		BufferedReader buff = new BufferedReader(in);
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"A-small-attempt0.out")));

		int nCases = Integer.parseInt(buff.readLine());
		StringBuilder output = new StringBuilder("");
		StringTokenizer st;
		double[] array;

		for (int i = 0; i < nCases; i++) {
			st = new StringTokenizer(buff.readLine());
			int A = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());
			array = new double[A];
			st = new StringTokenizer(buff.readLine());
			for (int j = 0; j < A; j++)
				array[j] = Double.parseDouble(st.nextToken());

			output.append("Case #" + (i + 1) + ": " + getMinExp(A, B, array)
					+ "\n");
		}
		out.print(output.toString());
		in.close();
		out.close();
	}

	static Vector<Double> probs;

	private static double getMinExp(int a, int b, double[] array) {
		probs = new Vector<Double>();
		getProb(a, b, array, 1, new boolean[a], 0);

		int[][] keep = new int[4][probs.size()];
		boolean[] check = new boolean[4];

		// keep typing
		keep[0][0] = b - a + 1;// no errors
		for (int i = 1; i < probs.size(); i++)
			keep[0][i] = 2 * b - a + 2;

		// backOnce
		keep[1][0] = keep[1][1] = keep[0][0] + 2;
		for (int i = 2; i < probs.size(); i++)
			keep[1][i] = keep[0][i] + 2;

		// backTwice
		if (a >= 2) {
			keep[2][0] = keep[2][1] = keep[2][2] = keep[2][3] = keep[1][0] + 2;
			for (int i = 4; i < probs.size(); i++)
				keep[2][i] = keep[1][i] + 2;
		} else
			check[2] = true;

		// enter
		for (int i = 0; i < probs.size(); i++)
			keep[3][i] = b + 2;

		double Min = Double.MAX_VALUE;
		for (int j = 0; j < 4; j++)
			if (!check[j]) {
				double current = 0;
				for (int i = 0; i < probs.size(); i++)
					current += probs.get(i) * keep[j][i];
				Min = Math.min(Min, current);
			}
		return Min;
	}

	private static void getProb(int a, int b, double[] array, double current,
			boolean[] bools, int index) {

		if (index == array.length) {
			probs.add(current);
			return;
		}

		for (int i = index; i < array.length; i++)
			if (!bools[i]) {
				bools[i] = true;

				getProb(a, b, array, current * array[i], bools, index + 1);
				getProb(a, b, array, current * (1 - array[i]), bools, index + 1);

				bools[i] = false;
			}
	}
}
