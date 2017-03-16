import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Iterator;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
public class B implements OneCaseSolver {
	
	int[][] a;
	private int n;
	private int m;
	
	@Override
	public void input(Scanner in) {
		n = in.nextInt();
		m = in.nextInt();
		a = new int[n][m];
		for(int i : Indices.create(n)) {
			for(int j : Indices.create(n)) {
				a[i][j] = in.nextInt();
			}
		}		
	}
	
	@Override
	public String solve() {
		boolean ok = true;
		for(int i : Indices.create(n)) {
			for(int j : Indices.create(m)) {
				boolean rowok = true;
				boolean colok = true;
				for(int k : Indices.create(m))
					if(a[i][k] > a[i][j])
						rowok = false;
				for(int k : Indices.create(n))
					if(a[k][j] > a[i][j])
						colok = false;
				if(!rowok && !colok)
					ok = false;
			}
		}
		return ok ? "YES" : "NO";
	}

	public static void main(String[] args) throws Exception {
		CodeJamProblemSolver.launch(1, "B.in", new OneCaseSolverFactory() {
			@Override
			public OneCaseSolver createSolver() {
				return new B();
			}
		});
	}
}
class CodeJamProblemSolver {

	public static void launch(int threadNumber, String inputFileNameOnDesktop, OneCaseSolverFactory factory, Integer... caseNumbers) throws Exception {
		String outputFileNameOnDesktop = inputFileNameOnDesktop.substring(0, inputFileNameOnDesktop.length()-3) + ".out";
		String desktopDir = System.getProperty("user.home") + "/Desktop";
		String inputFile = desktopDir + "/" + inputFileNameOnDesktop;
		String outputFile = desktopDir + "/" + outputFileNameOnDesktop;
		CodeJamStyleProblemSolver.launch(threadNumber, inputFile, outputFile, factory, caseNumbers);
	}

}
class CodeJamStyleProblemSolver {
	
	public static void launch(final int threadNumber, String inputFilePath, String outputFilePath, final OneCaseSolverFactory factory, Integer... caseIndices) throws Exception {
		final Object lock = new Object();
		final long startTime = System.currentTimeMillis();
		final Scanner in = new Scanner(new File(inputFilePath));
		final int casen = in.nextInt();
		final int[] nextIndex = {0}; 
		final String[] results = new String[casen];
		final java.util.Set<Integer> caseIndexToSolve = createCaseIndicesToSolve(casen, caseIndices);
		ExecutorService executor = Executors.newFixedThreadPool(threadNumber);
		for(int i=0;i<casen;i++) {
			executor.execute(new Runnable() {
				@Override
				public void run() {
					int casei;
					String result = null;
					{
						OneCaseSolver caseSolver = factory.createSolver();
						synchronized(lock) {
							caseSolver.input(in);
							casei = nextIndex[0]++;
						}
						if(caseIndexToSolve.contains(casei+1))
							result = caseSolver.solve();
					}
					if(result != null) {
						synchronized(lock) {
							results[casei] = result;
							int solved = countNotNull(results);
							outputProgess(startTime, solved, caseIndexToSolve.size());
						}
					}
				}
			});
		}
		executor.shutdown();
		executor.awaitTermination(Long.MAX_VALUE, TimeUnit.SECONDS);
		printLine();
		outputResult(results, outputFilePath);
		printLine();
		System.out.println("Output is written to " + outputFilePath);
	}

	private static java.util.Set<Integer> createCaseIndicesToSolve(int casen, Integer... caseIndices) {
		final java.util.Set<Integer> set = new java.util.TreeSet<Integer>();
		if(caseIndices.length == 0) {
			for(int i=1;i<=casen;i++)
				set.add(i);
		} else {
			for(int v : caseIndices) {
				if(v < 1 || v > casen)
					throw new RuntimeException("invalid case index : " + v);
				set.add(v);
			}
		}
		return set;
	}

	private static void printLine() {
		for(int i=0;i<100;i++)
			System.out.print("-");
		System.out.println();
	}

	private static int countNotNull(final String[] results) {
		int solved = 0;
		for(String s : results)
			if(s != null)
				solved++;
		return solved;
	}

	private static void outputProgess(long startTime, int solved, int caseNumberToSolve) {
		long duration = System.currentTimeMillis() - startTime;
		long estimation = (long)Math.round((double)duration * caseNumberToSolve / solved / 1000);
		System.out.printf("%.03fs : %d/%d solved (estimated : %dm %ds)\n", (double)duration / 1000, solved,  caseNumberToSolve, estimation / 60, estimation % 60);
	}

	private static void outputResult(final String[] results, String outputFilePath) throws FileNotFoundException {
		PrintStream ps = new PrintStream(outputFilePath);
		for(int i=0;i<results.length;i++) {
			if(results[i] != null) {
				String line = String.format("Case #%d: %s", i+1, results[i]);
				System.out.println(line);
				ps.println(line);
			}
		}
		ps.close();
	}

}
interface OneCaseSolver {
	void input(Scanner in);
	String solve();
}
interface OneCaseSolverFactory {
	OneCaseSolver createSolver();
}
class Indices {

	public static IntSequenceIterable create(int len) {
		return new IntSequenceIterable(0, len);
	}

}
class IntSequenceIterable implements Iterable<Integer> {
	
	private final int from;
	private final int size;

	public IntSequenceIterable(int from, int size) {
		this.from = from;
		this.size = size;
	}

	@Override
	public Iterator<Integer> iterator() {
		return new AbstractIterator<Integer>() {
			int next = from;
			@Override
			public boolean hasNext() {
				return next < from + size;
			}
			@Override
			public Integer next() {
				return next++;
			}
		};
	}
}
abstract class AbstractIterator<T> implements Iterator<T> {

	@Override
	public final void remove() {
		throw new UnsupportedOperationException();
	}

}
