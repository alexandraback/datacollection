package GoogleCodeJam2013;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class ManageYourEnergy {

	private static int max, regain;
	private static int[] values;
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner input = new Scanner(new File("input.txt"));
		PrintStream output = new PrintStream("output.txt");
		int numCases = input.nextInt();
		for (int i = 1; i <= numCases; i++) {
			max = input.nextInt();
			regain = input.nextInt();
			int num = input.nextInt();
			values = new int[num];
			for (int n = 0; n < num; n++) {
				values[n] = input.nextInt();
			}
			int gain = solve();
			output.println("Case #" + i + ": " + gain);
		}
	}

	private static int solve() {
		int index = 0;
		return solve(index, max);
	}

	private static int solve(int index, int energy) {
		if (energy > max) {
			energy = max;
		}
		if (index == values.length-1) {
			int gain = (values[index] * energy);
			return gain;
		}
		int optimum = 0;
		int max = 0;
		for (int e = 0; e <= energy; e++) {
			int value = solve(index + 1, energy - e + regain);
			value = value + (values[index] * (e));
			if (value > max) {
				max = value;
				optimum = e;
			}
		}
		return max;
	}
}
