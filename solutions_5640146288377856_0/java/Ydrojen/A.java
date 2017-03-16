import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;


public class A {
	
	private static final int NUM_RETRIES = 1;
	private static final PROBLEM_SIZE PROBLEM = PROBLEM_SIZE.SMALL;
	private static final int NUM_THREAD = 4;
	
	// TestCase variables
	long r,c,w;
	
	public A(FastScanner in) {
		r = in.nextLong();
		c = in.nextLong();
		w = in.nextLong();
	}
	
	protected String solve() {
		long solve = w-1+r*c/w;
		if(c%w != 0){
			solve += 1;
		}
		return ""+solve;
	}

	public static void main(String[] args) throws IOException, InterruptedException, ExecutionException {
		ExecutorService executor = Executors.newFixedThreadPool(NUM_THREAD);
		Locale.setDefault(Locale.US);
		FastScanner in = new FastScanner(new File(PROBLEM.getInputFileName(NUM_RETRIES)));
		PrintWriter out = new PrintWriter(PROBLEM.getOutputFileName(NUM_RETRIES));
		int tests = in.nextInt();
		
		@SuppressWarnings("unchecked")
		Future<String>[] outputs = new Future[tests];
		for (int t = 0; t < tests; t++) {
			final A testCase = new A(in);
			final int testCaseNumber = t;
			outputs[t] = executor.submit(new Callable<String>() {
				@Override
				public String call() {
					String answer = testCase.solve();
					String printed = "Case #" + (testCaseNumber + 1) + ": " + answer;
					System.out.println(printed);
					return printed;
				}
			});
		}
		
		// Print solutions
		for (int t = 0; t < tests; t++) {
			out.println(outputs[t].get());
		}
		System.out.println("FINISHED");
		in.close();
		out.close();
		executor.shutdown();
	}



	static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
		
		void close(){
			try {
				br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	
	private enum PROBLEM_SIZE {
		TEST,
        SMALL,
        LARGE,
        PRACTICE_SMALL,
        PRACTICE_LARGE;
        
        public String getInputFileName(int numRetries){
        	return getFileName(numRetries)+".in";
        }
        
        public String getOutputFileName(int numRetries){
        	return getFileName(numRetries)+".out";
        }
        
        private String getFileName(int numRetries){
        	String fileName = "";
        	switch (this) {
				case TEST:
					fileName = A.class.getSimpleName()+"-Test";
					break;
				case SMALL:
					fileName = A.class.getSimpleName()+"-small-attempt"+numRetries;
					break;
				case LARGE:
					fileName = A.class.getSimpleName()+"-large";
					break;
				case PRACTICE_SMALL:
					fileName = A.class.getSimpleName()+"-small-practice";
					break;
				case PRACTICE_LARGE:
					fileName = A.class.getSimpleName()+"-large-practice";
					break;
			}
        	
        	return fileName;
        }
    }

}
