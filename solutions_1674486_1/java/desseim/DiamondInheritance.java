import java.io.File;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.Set;


public final class DiamondInheritance {
	
	private static class Clazz {
		final int num;
		
		private static Map<Integer, Clazz> createdClazzes = new HashMap<Integer, Clazz>();
		
		public static Clazz create (final int num) {
			Clazz clazz = createdClazzes.get(num);
			if (clazz == null) {
				clazz = new Clazz(num);
				createdClazzes.put(num, clazz);
			}
			return clazz;
		}
		
		public static void reset () {
			createdClazzes.clear();
		}
		
		private Clazz (final int num) {
			this.num = num;
		}
		
		final Set<Clazz> parents = new HashSet<Clazz>();
		Set<Clazz> accessibles = null;
		
		Set<Clazz> getAccessibles () {
			if (accessibles == null) {
				accessibles = new HashSet<Clazz>();
				for (final Clazz parent : parents) {
					accessibles.addAll(parent.getAccessibles());
				}
				accessibles.add(this);
			}
			return accessibles;
		}
		
		public int getNum () {
			return num;
		}
		
		public Set<Clazz> getParents () {
			return parents;
		}
		
		public void addParent (final Clazz parent) {
			parents.add(parent);
		}

		@Override
		public boolean equals(final Object obj) {
			if (! (obj instanceof Clazz))
				return false;
			return num == ((Clazz)obj).num;
		}

		@Override
		public String toString() {
			return Integer.toString(num);
		}
		
	}

	private static boolean isDiamond (final Clazz[] clazzes) {
		for (final Clazz clazz : clazzes) {
			final HashSet<Clazz> testSet = new HashSet<Clazz>();
			for (final Clazz parent : clazz.getParents()) {
				final Set<Clazz> parentAccessibles = parent.getAccessibles();
				for (Clazz accessible : parentAccessibles) {
					if (testSet.contains(accessible))
						return true;
				}
				testSet.addAll(parentAccessibles);
			}
		}
		return false;
	}

	private static final String OUTPUT_FILE_EXTENSION = "out";

	public static void main (final String[] args) throws Exception {
		//input init
		if (args.length < 1)
			throw new IllegalArgumentException();

		final String inputFileName = args[0];
		final int lastDotIndex = inputFileName.lastIndexOf('.');
		final String fileName = (lastDotIndex < 0) ? inputFileName : inputFileName.substring(0, lastDotIndex);
		final String outputFileName = fileName + "." + OUTPUT_FILE_EXTENSION;

		final File inputFile = new File(inputFileName);
		final File outputFile = new File(outputFileName);
		Scanner inputScanner = null;
		PrintWriter outputWriter = null;

		try {
			inputScanner = new Scanner(inputFile);
			outputWriter = new PrintWriter(outputFile);
			final int numberLines = inputScanner.nextInt();
			for (int i = 0; i < numberLines; ++i) {
				inputScanner.nextLine();
				final int classesNumber = inputScanner.nextInt();
				inputScanner.nextLine();
				final Clazz[] classes = new Clazz[classesNumber];
				for (int j = 0; j < classesNumber; ++j) {
					final Clazz clazz = Clazz.create(j + 1);
					final int parentsNb = inputScanner.nextInt();
					for (int k = 0; k < parentsNb; ++k) {
						clazz.addParent(Clazz.create(inputScanner.nextInt()));
					}
					classes[j] = clazz;
				}
				outputWriter.print("Case #" + (i+1) + ": ");
				outputWriter.print((isDiamond(classes) ? "Yes" : "No"));
				outputWriter.println();
				Clazz.reset();
			}
		} catch (final NoSuchElementException noSuchElementException) {
			System.err.println("invalid input");
			throw noSuchElementException;
		} finally {
			if (inputScanner != null) {
				inputScanner.close();
			}
			if (outputWriter != null) {
				outputWriter.flush();
				outputWriter.close();
			}
		}
	}

}
