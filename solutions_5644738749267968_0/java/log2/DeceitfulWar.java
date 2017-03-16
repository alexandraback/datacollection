import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NavigableSet;
import java.util.SortedSet;
import java.util.TreeSet;

public class DeceitfulWar {

	private File from;
	private File to;

	public DeceitfulWar(String in, String out) {
		from = new File(in);
		to = new File(out);
	}

	public static void main(String[] args) throws IOException {
		new DeceitfulWar(args[0], args[1]).go();
	}

	private void go() throws IOException {
		try (FileReader fileReader = new FileReader(from)) {
			try (BufferedReader bufferedReader = new BufferedReader(fileReader)) {
				int cases = getNextInt(bufferedReader);
				translateAll(cases, bufferedReader);
			}
		}

	}

	private int getNextInt(BufferedReader bufferedReader) throws IOException {
		String readLine = bufferedReader.readLine();
		return Integer.valueOf(readLine);
	}

	private void translateAll(int count, BufferedReader bufferedReader)
			throws IOException {
		try (PrintWriter writer = new PrintWriter(new FileWriter(to))) {
			for (int i = 1; i <= count; i++) {
				translateNext(i, bufferedReader, writer);
			}
		}
	}

	private void translateNext(int caseIndex, BufferedReader bufferedReader,
			PrintWriter writer) throws IOException {
		int size = getNextInt(bufferedReader);
		double[] naomiBlocks = readVector(bufferedReader);
		double[] kenBlocks = readVector(bufferedReader);

		double[] naomiWarMoves = cloneSorted(naomiBlocks);
		NavigableSet<Double> kenBlocksSorted = toSorted(kenBlocks);

		double[] optimalKenMoves = new double[size];
		NavigableSet<Double> kenLoosingMoves = new TreeSet<>();
		int firstLosingMove = -1;
		int pointsWar = 0;
		for (int i = 0; i < naomiWarMoves.length; i++) {
			double chosenNaomi = naomiWarMoves[i];
			Double chosenKen = null;
			while (!kenBlocksSorted.isEmpty()) {
				Double first = kenBlocksSorted.pollFirst();
				if (first > chosenNaomi) {
					chosenKen = first;
					break;
				} else
					kenLoosingMoves.add(first);
			}
			if (chosenKen == null)
				chosenKen = kenLoosingMoves.pollFirst();
			optimalKenMoves[i] = chosenKen;
			if (chosenNaomi > chosenKen) {
				pointsWar++;
				if (firstLosingMove < 0)
					firstLosingMove = i;
			}
		}

		int pointsDeceitfulWar = pointsWar;

		// Try cheating before that point
		double epsilon = 1e-8 / size;
		NavigableSet<Double> allKenBlocks = toSorted(kenBlocks);
		for (int i = size - 1; i >= 0; i--) {
			double toldNaomi = optimalKenMoves[i] - epsilon;

			double[] bonafideKenAnswers = new double[size];
			NavigableSet<Double> kenBlocksToTest = new TreeSet<>(allKenBlocks);
			int points = 0;
			boolean failed = false;
			for (int j = 0; j < size && !failed; j++) {
				double chosenNaomi = naomiWarMoves[j];
				toldNaomi = Math.max(chosenNaomi, toldNaomi);
				Double chosenKen = kenBlocksToTest.ceiling(toldNaomi);
				if (chosenKen == null) {
					// Can't answer, get first available block
					chosenKen = kenBlocksToTest.first();
				}
				bonafideKenAnswers[j] = chosenKen;
				kenBlocksToTest.remove(chosenKen);
				if (toldNaomi > chosenKen) {
					// Ken loses here
					// Will balance scale confirm?
					if (!(chosenNaomi > chosenKen)) {
						failed = true;
						break;
					}
					points++;
					toldNaomi += epsilon;
					while (allKenBlocks.contains(toldNaomi))
						toldNaomi += epsilon;
				} else {
					Double nextHigherMove = kenBlocksToTest.higher(chosenKen);
					if (nextHigherMove == null) {
						toldNaomi += epsilon;
						while (allKenBlocks.contains(toldNaomi))
							toldNaomi += epsilon;
					} else
						toldNaomi = Math.max(toldNaomi, nextHigherMove
								- epsilon);
				}
			}
			if (!failed && points > pointsDeceitfulWar) {
				pointsDeceitfulWar = points;
				// break;
			}
		}

		writer.println("Case #" + caseIndex + ": " + pointsDeceitfulWar + " "
				+ pointsWar);

	}

	private double[] cloneSorted(double[] naomiBlocks) {
		double[] naomiWarMoves = naomiBlocks.clone();
		Arrays.sort(naomiWarMoves);
		return naomiWarMoves;
	}

	private NavigableSet<Double> toSorted(double[] kenBlocks) {
		NavigableSet<Double> kenBlocksSorted = new TreeSet<>();
		for (double d : kenBlocks) {
			kenBlocksSorted.add(d);
		}
		return kenBlocksSorted;
	}

	private double[] readVector(BufferedReader bufferedReader)
			throws IOException {
		String line = bufferedReader.readLine();
		String[] parts = line.split(" ");
		double[] values = new double[parts.length];
		for (int i = 0; i < parts.length; i++) {
			values[i] = Double.valueOf(parts[i]);
		}
		return values;
	}
}
