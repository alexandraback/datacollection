package round1A;

import java.util.*;
import java.io.*;

public class Economy {

	public static void main(String[] args) throws IOException {
		Scanner infile = new Scanner(new File("sample.in"));
		PrintWriter pw = new PrintWriter(new File("out.txt"));
		int dataSets = infile.nextInt();
		infile.nextLine();

		for (int dataSet = 1; dataSet <= dataSets; dataSet++) {
			int e = infile.nextInt();
			int r = infile.nextInt();
			int n = infile.nextInt();
			infile.nextLine();
			ArrayList<Integer> list = new ArrayList<Integer>(n);
			for (int i = 0; i < n; i++) {
				list.add(infile.nextInt()); 	
			}
			

			System.out.printf("Case #%d: %d\n", dataSet,
					maximumGain(e, r, list));
			pw.printf("Case #%d: %d\n", dataSet,
					maximumGain(e, r, list));
		}
		infile.close();
		pw.close();
	}

	/**
	 * Returns optimal list of energies to spend on each activity. Checking the
	 * kth element each call.
	 */
	private static ArrayList<Integer> max(int maxEnergy, int energy,
			int regain, ArrayList<Integer> values, int k,
			ArrayList<Integer> usedEnergies) {
		// base case:
		if(k == values.size()) 
			return usedEnergies;
		if(energy > maxEnergy)
			energy = maxEnergy;
		int maxGain = 0;
		ArrayList<Integer> best = copyList(usedEnergies);
		for (int i = 0; i <= energy; i++) {
			// System.out.println("\tUsing " + i + " energy on activity " + k);
			if (energy - i < 0 || energy - i > maxEnergy)
				continue;
			ArrayList<Integer> copy = copyList(usedEnergies);
			// System.out.println("used: " + usedEnergies);
			// System.out.println("copy: " + copy);
			// System.out.println();
			copy.set(k, i);
			ArrayList<Integer> subList = max(maxEnergy, energy - i + regain, regain, values, k + 1, copy);
			int gain = gain(subList, values);
			if (gain > maxGain) {
				maxGain = gain;
				best = subList;
			}
		}
		return best;
	}
	
	private static ArrayList<Integer> copyList(ArrayList<Integer> in) {
		ArrayList<Integer> out = new ArrayList<Integer>(in.size());
		for(int i = 0; i < in.size(); i++)
			out.add(in.get(i));
		return out;
	}

	/**
	 * Returns the total gain of a sequence of energies used.
	 */
	private static int gain(ArrayList<Integer> values, ArrayList<Integer> energies) {
		int sum = 0;
		for (int i = 0; i < values.size(); i++) {
			sum += energies.get(i) * values.get(i);
		}
		return sum;
	}

	/**
	 * Returns the total maximum energy we could gain.
	 */
	public static int maximumGain(int maxEnergy, int regain,
			ArrayList<Integer> values) {
		ArrayList<Integer> energies = new ArrayList<Integer>(values.size());
		for(int i = 0; i < values.size(); i++)
			energies.add(0);
		return gain(max(maxEnergy, maxEnergy, regain, values, 0, energies), values);
	}

}
