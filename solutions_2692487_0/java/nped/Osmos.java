package se.nped.codejam;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Osmos {

	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(reader.readLine());

		for (int i = 1; i <= cases; i++) {
			String line = reader.readLine();
			String[] split = line.split(" ");
			int startSize = Integer.parseInt(split[0]);
			int numberOfMotes = Integer.parseInt(split[1]);

			List<Integer> motes = new ArrayList<Integer>();

			line = reader.readLine();
			split = line.split(" ");

			for (int j = 0; j < numberOfMotes; j++) {
				motes.add(Integer.parseInt(split[j]));
			}

			Collections.sort(motes);
			int result = findResult(startSize, motes, 0, motes.size());

			System.out.println("Case #" + i + ": " + result);
		}
	}

	private static int findResult(int startSize, List<Integer> motes, int moves, int cutoff) {
		if (moves >= cutoff) {
			return Integer.MAX_VALUE;
		}

		int currentSize = startSize;

		for (int i = 0; i < motes.size(); i++) {
			if (currentSize > motes.get(i)) {
				currentSize += motes.get(i);
				// System.out.println("Gobbled up " + motes.get(i) +
				// ", current size " + currentSize);
			} else {
				int removeMoves = moves + motes.size() - i;
				// System.out.println("Could not eat " + motes.get(i) +
				// ", current size is " + currentSize);

				if (currentSize > 1) {
					List<Integer> impossibleMotes = motes.subList(i, motes.size());
					// System.out.println("There are " + impossibleMotes.size()
					// +
					// " too large motes, returning the min of removing them all and adding new motes");
					return Math.min(removeMoves, findResult(currentSize * 2 - 1, impossibleMotes, moves + 1, cutoff));
				} else {
					return removeMoves;
				}
			}
		}

		return moves;
	}
}
