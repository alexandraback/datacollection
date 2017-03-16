package se.matst.codejam;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class B {
	static ArrayList<Integer> layerCount = new ArrayList<Integer>();
	static ArrayList<Integer> layerSum = new ArrayList<Integer>();

	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new File("C:\\dev\\codejam\\codejam\\src\\B-small-attempt2.in"));

		PrintWriter out = new PrintWriter("C:\\dev\\codejam\\codejam\\src\\B-small-attempt2.out");

		int testCases = scanner.nextInt();
		layerCount.add(1);
		layerSum.add(1);
		for (int i = 1; true; i++) {
			int lc = i * 4 + 1;
			layerCount.add(lc);
			int ls = layerSum.get(i - 1) + lc;
			layerSum.add(ls);
			if (ls > 1000000) {
				break;
			}
		}

		for (int i = 0; i < testCases; i++) {
			int nrDiamonds = scanner.nextInt();
			int xLoc = scanner.nextInt();
			int yLoc = scanner.nextInt();

			int layer = getLayer(xLoc, yLoc);
			if (layer > layerSum.size()) {
				System.out.println("Case #" + (i + 1) + ": N: " + nrDiamonds + " X: " + xLoc + " Y: " + yLoc + " --- 0.0 too high layer (" + (layer - 1) + ")");
				out.println("Case #" + (i + 1) + ": " + 0.0);
			} else if (layerSum.get(layer) <= nrDiamonds) {
				System.out.println("Case #" + (i + 1) + ": N: " + nrDiamonds + " X: " + xLoc + " Y: " + yLoc + " --- 1.0 layer (" + layer + ") fully covered");
				out.println("Case #" + (i + 1) + ": " + 1.0);
			} else if (layer > 0 && layerSum.get(layer - 1) >= nrDiamonds) {
				System.out.println("Case #" + (i + 1) + ": N: " + nrDiamonds + " X: " + xLoc + " Y: " + yLoc + " --- 0.0 previous layer (" + (layer - 1) + ") not filled");
				out.println("Case #" + (i + 1) + ": " + 0.0);
			} else if (xLoc == 0) {
				System.out.println("Case #" + (i + 1) + ": N: " + nrDiamonds + " X: " + xLoc + " Y: " + yLoc + " --- 0.0 layer (" + (layer) + ") not filled and x=0");
				out.println("Case #" + (i + 1) + ": " + 0.0);
			} else {
				int over = nrDiamonds - layerSum.get(layer - 1);
				if (over >= (layerCount.get(layer) / 2 + yLoc + 1)) {
					System.out.println("Case #" + (i + 1) + ": N: " + nrDiamonds + " X: " + xLoc + " Y: " + yLoc + " --- 1.0 enough to fill up to");
					out.println("Case #" + (i + 1) + ": " + 1.0);
				} else {
					double result = 1 - (cumulativeBinom(over, yLoc + 1) / Math.pow(2, over));
					System.out.println("Case #" + (i + 1) + ": N: " + nrDiamonds + " X: " + xLoc + " Y: " + yLoc + " --- " + result);
					out.println("Case #" + (i + 1) + ": " + result);
				}
			}
		}

		out.close();
	}

	public static int getLayer(int xLoc, int yLoc) {
		return (Math.abs(xLoc) + yLoc) / 2;
	}

	public static long binom(int n, int k) {
		long coeff = 1;
		for (int i = n - k + 1; i <= n; i++) {
			coeff *= i;
		}
		for (int i = 1; i <= k; i++) {
			coeff /= i;
		}
		return coeff;
	}

	public static long cumulativeBinom(int n, int k) {
		long sum = 0;
		for (int i = 0; i < k; i++) {
			sum += binom(n, i);
		}
		return sum;
	}
}