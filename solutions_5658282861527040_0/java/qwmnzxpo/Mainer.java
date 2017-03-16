
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;



// some template code used from contestant "winger"'s Round 1A submissions.

// all solutions here that pertains to round 1B are are my own

public class Mainer {
	
	
	public static void main(String[] args) throws IOException {
		
		
		FastReader in = new FastReader(new BufferedReader(new FileReader("input.txt")));
		PrintWriter out = new PrintWriter(new File("output.txt"));
		
		
		int tests = in.nextInt();
		
		for (int test = 0; test < tests; ++test) {
			int a = in.nextInt();
			int b = in.nextInt();
			int k = in.nextInt();
			int sols = 0;
			for (int ai = 0; ai < a; ai ++){
				for (int bi = 0; bi < b; bi ++){
					for (int ki = 0; ki < k; ki ++){
						if ((ai & bi) == ki){
							sols++;
						}
					}
				}
			}
			System.out.println("Case #" + (test + 1) + ": " + sols);
			out.println("Case #" + (test + 1) + ": " + sols);
		}
		
		out.close();


}
	

	public static void main1sdfg(String[] args) throws IOException {
		
	
			FastReader in = new FastReader(new BufferedReader(new FileReader("input.txt")));
			PrintWriter out = new PrintWriter(new File("output.txt"));
			
			
			int tests = in.nextInt();
			
			for (int test = 0; test < tests; ++test) {
				int strNum = in.nextInt();
				String acceptableStr = null;
				ArrayList<ArrayList<Integer>> counts = new ArrayList<ArrayList<Integer>>();
				boolean isGood = true;
				for (int s = 0; s < strNum;s++){
					ArrayList<Integer> cCounts = new ArrayList<Integer>();
					String cStr = in.next();
					String outStr = noRepeats(cStr, cCounts);
					counts.add(cCounts);
					if (acceptableStr == null)
						acceptableStr = outStr;
					if (!outStr.equals(acceptableStr)){
						if (isGood){
						System.out.println("Case #" + (test + 1) + ": Fegla Won");
						out.println("Case #" + (test + 1) + ": Fegla Won");
						}
						isGood =false;
					}
				}
				if (!isGood)
					continue;
				int movesReqd = 0;
				for (int col = 0; col < acceptableStr.length(); col++){
					ArrayList<Integer> cr = new ArrayList<Integer>();
					for (int row = 0; row < counts.size(); row ++){
						cr.add(counts.get(row).get(col));
					}
					int max = Collections.max(cr);
					int min = Collections.min(cr);
					
					int[] moves = new int[max-min+1];
					for (int pos = min; pos <= max; pos++) {
						for (int row = 0; row < counts.size(); row ++){
							moves[pos-min] += Math.abs(pos - cr.get(row));
						}
					}
					int minn = 9999999;
					for (int i: moves){
						minn = Math.min(i, minn);
					}
					movesReqd += minn;

				}
				
				System.out.println("Case #" + (test + 1) + ": " + movesReqd);
				out.println("Case #" + (test + 1) + ": " + movesReqd);
			}
			
			out.close();


	}
	
	
	public class Tuple<X, Y> { 
		  public final X x; 
		  public final Y y; 
		  public Tuple(X x, Y y) { 
		    this.x = x; 
		    this.y = y; 
		  } 
		} 
	

	public static String noRepeats(String s, ArrayList<Integer> counts){
		String str = "";
		for (int i =0 ; i < s.length(); i++){
			if (str.length() ==0 || str.charAt(str.length()-1) != s.charAt(i)){
				str += s.charAt(i);
				counts.add(1);
			} else {
				counts.set(counts.size() -1, counts.get(counts.size()-1)+1);
			}
		}
		return str;
	}
	
	static class InputData {

        int n, l;
        long[] a, b;
		
		InputData(FastReader in) throws IOException {
            n = in.nextInt();
            l = in.nextInt();
            a = new long[n];
            b = new long[n];
            for (int i = 0; i < n; ++i) {
                String s = in.next();
                for (int j = 0; j < l; ++j) {
                    if (s.charAt(j) == '1') {
                        a[i] |= 1L << j;
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                String s = in.next();
                for (int j = 0; j < l; ++j) {
                    if (s.charAt(j) == '1') {
                        b[i] |= 1L << j;
                    }
                }
            }
		}
	}
	
	static class FastReader {
		public FastReader(BufferedReader in) {
			this.in = in;
			eat("");
		}
		
		private StringTokenizer st;
		private BufferedReader in;
		
		void eat(String s) {
			st = new StringTokenizer(s);
		}
		
		String next() throws IOException {
			while (!st.hasMoreTokens()) {
				String line = in.readLine();
				if (line == null) {
					return null;
				}
				eat(line);
			}
			return st.nextToken();
		}
		
		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
		
		long nextLong() throws IOException {
			return Long.parseLong(next());
		}
		
		double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
	}

}
