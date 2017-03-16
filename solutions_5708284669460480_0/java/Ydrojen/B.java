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
import java.util.TreeMap;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;


public class B {
	
	private static final int NUM_RETRIES = 5;
	private static final PROBLEM_SIZE PROBLEM = PROBLEM_SIZE.SMALL;
	private static final int NUM_THREAD = 4;
	
	// TestCase variables
	int k, l, s;
	String keyboard, targetLetter;
	
	public B(FastScanner in) {
		k = in.nextInt();
		l = in.nextInt();
		s = in.nextInt();
		keyboard = in.next();
		targetLetter = in.next();
	}
	
	protected String solve() {
		TreeMap<Character, Integer> frecuencias = getFrecuencias();
		double letterProbability = calculateProbability(frecuencias, targetLetter);
		
		if(letterProbability == 0 || letterProbability == 1){
			return "0.0";
		}
		
		int overlap = calculateOverlapMinSize();
		int bananas = s - l;
		int bananasOverlap = bananas/overlap;
		bananas = 1 + bananasOverlap;
		
		int intentos = s - l - bananasOverlap * overlap + 1;
		
		double overlapProbability = calculateProbability(frecuencias, targetLetter.substring(l-overlap));
		
		double result = bananas - intentos*letterProbability*bananas*overlapProbability;
		
		return ""+result;
	}
	
	private int calculateOverlapMinSize(){
		int overlap = 1;
		bucle1:
		for(; overlap < l; overlap++){
			int imax = l - overlap;
			for(int i = 0; i < imax; i++){
				if(!(targetLetter.charAt(overlap) == targetLetter.charAt(i))){
					continue bucle1;
				}
			}
			return overlap;
		}
		return overlap;
	}
	
	private double calculateProbability(TreeMap<Character, Integer> frecuencias, String letters){
		double result = 1;
		int lmax = letters.length();
		for(int i = 0; i < lmax; i++){
			Character c = letters.charAt(i);
			
			if(!frecuencias.containsKey(c)){
				return 0d;
			}
			
			Double repeat = frecuencias.get(c).doubleValue();
			result = result * (repeat/k);
		}
		return result;
	}
	
	private TreeMap<Character, Integer> getFrecuencias(){
		TreeMap<Character, Integer> result = new TreeMap<>();
		
		for(int i = 0; i < k; i++){
			Character c = keyboard.charAt(i);
			Integer repeat;
			if(result.containsKey(c)){
				repeat = result.get(c);
			}else{
				repeat = 0;
			}
			repeat++;
			result.put(c, repeat);
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
			final B testCase = new B(in);
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
					fileName = B.class.getSimpleName()+"-Test";
					break;
				case SMALL:
					fileName = B.class.getSimpleName()+"-small-attempt"+numRetries;
					break;
				case LARGE:
					fileName = B.class.getSimpleName()+"-large";
					break;
				case PRACTICE_SMALL:
					fileName = B.class.getSimpleName()+"-small-practice";
					break;
				case PRACTICE_LARGE:
					fileName = B.class.getSimpleName()+"-large-practice";
					break;
			}
        	
        	return fileName;
        }
    }

}
