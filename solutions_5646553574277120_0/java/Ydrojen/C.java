import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;


public class C {
	
	private static final int NUM_RETRIES = 0;
	private static final PROBLEM_SIZE PROBLEM = PROBLEM_SIZE.SMALL;
	private static final int NUM_THREAD = 1;
	
	// TestCase variables
	long c,v;
	int d;
	List<Long> coins;
	
	public C(FastScanner in) {
		c = in.nextLong();
		d = in.nextInt();
		v = in.nextLong();
		
		coins = new ArrayList<Long>(d);
		
		for(int i = 0; i < d; i++){
			coins.add(in.nextLong());
		}
	}
	
	protected String solve() {
		long solution = 0;
		for(long i = 1; i <= v; i++){
			if(!canPay(i, d)){
				coins.add(i);
				d++;
				solution++;
				Collections.sort(coins);
			}
		}
		
		
		return ""+solution;
	}
	
	private boolean canPay(long value, int coinUsePosition){
		if(value == 0){
			return true;
		}
		
		boolean result = false;
		coinUsePosition--;
		if(coinUsePosition < 0){
			return false;
		}
		long coin = coins.get(coinUsePosition);
		int numCoin = 0;
		long valueIt = value;
		while(!result && valueIt >= 0 && numCoin <= c){
			result = canPay(valueIt, coinUsePosition);
			numCoin++;
			valueIt = value - numCoin*coin;
		}
		
		
		return result;
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
			final C testCase = new C(in);
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
					fileName = C.class.getSimpleName()+"-Test";
					break;
				case SMALL:
					fileName = C.class.getSimpleName()+"-small-attempt"+numRetries;
					break;
				case LARGE:
					fileName = C.class.getSimpleName()+"-large";
					break;
				case PRACTICE_SMALL:
					fileName = C.class.getSimpleName()+"-small-practice";
					break;
				case PRACTICE_LARGE:
					fileName = C.class.getSimpleName()+"-large-practice";
					break;
			}
        	
        	return fileName;
        }
    }

}
