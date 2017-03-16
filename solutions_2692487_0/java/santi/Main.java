import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Main {

	public static void main(String[] args) {
		try {
			// solvefromInputToOutPut("test.in", "test.out");
			solvefromInputToOutPut("A-small-attempt0 (1).in",
					"A-small-attempt0.out");
			// solvefromInputToOutPut("A-large.in", "A-large.out");
		} catch (NumberFormatException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public static void solvefromInputToOutPut(final String inputFileName,
			final String outputFileName) throws NumberFormatException,
			IOException {
		final BufferedReader reader = new BufferedReader(new FileReader(
				inputFileName));
		final int testCases = Integer.parseInt(reader.readLine());
		final List<ArrayList<Long>> motesSet = new ArrayList<ArrayList<Long>>(
				testCases);
		final List<Long> armins = new ArrayList<Long>(testCases);
		for (int i = 0; i < testCases; i++) {
			String[] line = reader.readLine().split(" ");
			final Long armin = Long.parseLong(line[0]);
			final int n = Integer.parseInt(line[1]);
			armins.add(i, armin);
			final ArrayList<Long> motes = new ArrayList<Long>(n);
			line = reader.readLine().split(" ");
			for (int j = 0; j < n; j++) {
				motes.add(Long.parseLong(line[j]));
			}
			motesSet.add(i, motes);
		}
		reader.close();
		final List<String> result = solve(armins, motesSet);
		final BufferedWriter writer = new BufferedWriter(new FileWriter(
				outputFileName));
		for (int i = 0; i < testCases; i++) {
			writer.write("Case #" + (i + 1) + ": " + result.get(i) + "\n");
		}
		writer.close();
	}

	private static List<String> solve(final List<Long> armins,
			final List<ArrayList<Long>> motesSet) {
		final List<String> result = new ArrayList<String>(armins.size());
		for (int i = 0; i < armins.size(); i++) {
			result.add(i, solve(armins.get(i), motesSet.get(i)).toString());
		}
		return result;
	}

	private static Integer solve(final Long armin, final ArrayList<Long> motes) {
		Collections.sort(motes);
		Long currentValue = armin;
		while (motes.size() > 0) {
			if (motes.get(0) < currentValue) {
				currentValue += motes.get(0);
				motes.remove(0);
			} else {
				if (currentValue < 2) {
					return motes.size();
				}
				return Math.min(motes.size(),
						1 + solve(2 * currentValue - 1, motes));
			}
		}
		return 0;
	}

	/*
	 * (non-Java-doc)
	 * 
	 * @see java.lang.Object#Object()
	 */
	public Main() {
		super();
	}

}