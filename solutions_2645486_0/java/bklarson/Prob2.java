package org.blarson.codeJam._2013Round1A;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;

public class Prob2 {
	private static BufferedReader r;
	private static PrintStream outFile;
	private static PrintStream out = new PrintStream(new OutputStream() {
		@Override
		public void write(int b) throws IOException {
			System.out.write(b);
			outFile.write(b);
		}
	});

	public static void main(String[] args) throws IOException {
		File f = new File("/home/blarson/input");
		r = new BufferedReader(new FileReader(f));
		outFile = new PrintStream(new FileOutputStream(new File(
				"/home/blarson/output")));
		final int numCases = readInt();

		for (int i = 0; i < numCases; i++) {
			out.print("Case #" + (i + 1) + ": ");

			solve();

			out.println();
		}

		out.close();
	}

	private static void solve() throws IOException {
		int[] nums = readIntArray(3);
		int maxEnergy = nums[0];
		int energyRegain = nums[1];
		int numActivities = nums[2];
		int[] activities = readIntArray(numActivities);
		int gain = 0;
		if(energyRegain >= maxEnergy) {
			for(int i = 0; i < numActivities; i++) {
				gain += activities[i] * maxEnergy;
			}
			out.print(gain);
			return;
		}
		out.print(findBest(maxEnergy, maxEnergy, energyRegain, activities, 0, gain));
	}

	private static int findBest(int maxEnergy, int curEnergy,
			int energyRegain, int[] activities, int curActivity, int gain) {
		if(curActivity == activities.length) {
			return gain;
		}
		int best = 0;
		for(int i = 0; i <= curEnergy; i++) {
			int tempEnergy = curEnergy - i;
			tempEnergy += energyRegain;
			if(tempEnergy > maxEnergy) {
				tempEnergy = maxEnergy;
			}
			int t = findBest(maxEnergy, tempEnergy, energyRegain, activities, curActivity + 1, gain + (i * activities[curActivity]));
			if(t > best) {
				best = t;
			}
		}
		return best;
	}

	private static int[] readIntArray(int maxItems) throws IOException {
		int[] array = new int[maxItems];
		String line = r.readLine().trim();
		String[] data = line.split(" ");
		for (int i = 0; i < data.length && i < maxItems; i++) {
			array[i] = new Integer(data[i]);
		}
		return array;
	}

	private static int readInt() throws IOException {
		String line = r.readLine().trim();
		return new Integer(line);
	}

}