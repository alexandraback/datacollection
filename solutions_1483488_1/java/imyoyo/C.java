import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
public class C implements CodeJamCaseSolver {
	
	int a, b;
	
	@Override
	public void input(Scanner in) {
		a = in.nextInt();
		b = in.nextInt();
	}
	
	@Override
	public String solve() {
		int count = 0;
		for(int i=a;i<=b;i++) {
			int n = i;
			String s = Integer.toString(i);
			Set<Integer> mset = new HashSetFactory().create();
			for(int j=0;j<s.length();j++) {
				String ms = s.substring(j, s.length()) + s.substring(0, j);
				int m = Integer.parseInt(ms);
				if(n != m && IntInRange.is(m, a, b))
				mset.insert(m);
			}
			count += mset.size();
		}
		return count/2 + "";
	}

	public static void main(String[] args) throws Exception {
		CodeJamSolver.launch(8, "C-large.in", new CodeJamCaseSolverFactory() {
			@Override
			public CodeJamCaseSolver createSolver() {
				return new C();
			}
		});
	}

}
class IntInRange {
	public static boolean is(int v, int min, int max) {
		return min <= v && v <= max;
	}
}
interface CodeJamCaseSolver {
	void input(Scanner in);
	String solve();
}
interface CodeJamCaseSolverFactory {
	CodeJamCaseSolver createSolver();
}
class CodeJamSolver {

	public static void launch(int threadNumber, String inputFileNameOnDesktop, CodeJamCaseSolverFactory factory, Integer... caseNumbers) throws Exception {
		if(!inputFileNameOnDesktop.endsWith(".in"))
			throw new RuntimeException("input filename should ends with '.in'");
		String outputFileNameOnDesktop = inputFileNameOnDesktop.substring(0, inputFileNameOnDesktop.length()-3) + ".out";
		String desktopDir = System.getProperty("user.home") + "/Desktop";
		String inputFile = desktopDir + "/" + inputFileNameOnDesktop;
		String outputFile = desktopDir + "/" + outputFileNameOnDesktop;
		launch(inputFile, outputFile, threadNumber, factory, caseNumbers);
	}

	private static void launch(String inputFilePath, String outputFilePath, final int threadNumber, final CodeJamCaseSolverFactory factory, Integer... caseIndices) throws Exception {
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
						CodeJamCaseSolver caseSolver = factory.createSolver();
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
					throw new RuntimeException("invalid index : " + v);
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
class HashSetFactory implements SetFactory {

	public <T> Set<T> create() {
		return new SetWrapper<T>(new HashSet<T>());
	}
	
}
interface Set<T> extends Container<T> {
	
	void clear();
	void insert(T v);
	void insertAll(Iterable<T> a);
	boolean contains(T v);
	void remove(T v);
}
interface Container<T> extends Iterable<T> {
	int size();
	boolean isEmpty();
}
interface SetFactory {
	<T> Set<T> create();
}
class SetWrapper<T> extends AbstractSet<T> {
	
	private final java.util.Set<T> set;
	
	public SetWrapper(java.util.Set<T> set) {
		this.set = set;
	}
	public void clear() {
		set.clear();		
	}
	
	public boolean contains(T v) {
		return set.contains(v);		
	}
	
	public void insert(T v) {
		set.add(v);
	}

	public Iterator<T> iterator() {
		return set.iterator();
	}
	
	public int size() {
		return set.size();
	}
	
	public void remove(T v) {
		set.remove(v);
	}
}
abstract class AbstractSet<T> implements Set<T> {

	final public void insertAll(Iterable<T> a) {
		for(T v : a)
			insert(v);
	}
	
	@Override
	final public boolean isEmpty() {
		return size() == 0;
	}
	
	final public String toString() {
		String r = "";
		for(T v : this) {
			if(!r.isEmpty())
				r += ",";
			r += v;			
		}
		return "{" + r + "}";
	}

}
