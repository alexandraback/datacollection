import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
public class B implements CodeJamCaseSolver {
	
	int n, s, p;
	int[] t;
	
	@Override
	public void input(Scanner in) {
		n = in.nextInt();
		s = in.nextInt();
		p = in.nextInt();
		t = new int[n];
		for(int i=0;i<n;i++)
			t[i] = in.nextInt();			
	}
	
	@Override
	public String solve() {
		int count = 0;
		int remains = s;
		for(int i=0;i<n;i++) {
			int notallowed;
			int allowed;
			int v = t[i];
			if(v%3 == 0) {
				notallowed = v/3;
				if(v/3 > 0)
					allowed = v/3+1;
				else
					allowed = notallowed;
			} else if(v%3 == 1) {
				notallowed = v/3+1;
				allowed = v/3+1;
			} else {
				notallowed = v/3+1;
				if(v/3+1 > 0) 
					allowed = v/3+2;
				else
					allowed = notallowed;					
			}
			if(notallowed >= p) {
				count++;
			} else if(allowed >= p && remains > 0) {
				count++;
				remains--;
			}			
		}
		return count + "";
	}

	public static void main(String[] args) throws Exception {
		CodeJamSolver.launch(8, "B-example.in", new CodeJamCaseSolverFactory() {
			@Override
			public CodeJamCaseSolver createSolver() {
				return new B();
			}
		});
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
		final Set<Integer> caseIndexToSolve = createCaseIndicesToSolve(casen, caseIndices);
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

	private static Set<Integer> createCaseIndicesToSolve(int casen, Integer... caseIndices) {
		final Set<Integer> set = new TreeSet<Integer>();
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
