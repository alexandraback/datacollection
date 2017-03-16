

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class A {
    class Solver implements Runnable {
        int testId;
        boolean failed = false;
        int result = 0;
        
        Solver(int testId) {
            this.testId = testId;
        }

        long t,a;
        int n;
        
        ArrayList<Long> moths = new ArrayList<Long>();
        private void readInput() {
        	a = nextLong();
        	n = nextInt();
            //a = new int[n][m];
            
            for (int i = 0; i < n; i++){
            		moths.add(nextLong());
            }
        }
        
        public int go(long A, int i) {
        	if (i >= n ) return 0;
        	long m = moths.get(i);
    		if (A > m) { 
    			return go(A+m, ++i); //swallow
    		} else if (A*2-1 > m) {
    			return go(A*2-1 + m, ++i)+1; //add one, swallow 1
//    		} else if (Math.pow(2, n - i)*A - Math.pow(2, n - i) + 1 <= m ) {
//    			return n - i; //it's at least as efficient to delete;
    		} else if (A == 1) {
    			return n - i; //will not get any bigger
    		} else {
    			return Math.min(go(A*2-1, i)+1, n - i);
    		}
        }
        
        public void run() {
        	Collections.sort(moths);
        	
        	result = go(a, 0);
        	//int p = 0;
        	
        			//can either add several items or delete the moth and all after it
        			//it's possible that I'll add five items, but will swallow 500 more due to this. How to efficiently decide?4
        			//but it's also possible that my size is 1, and I'll not swallow anything
        			
        			//the best growth achievable is the sequence a -> (a*2-1) -> (a*2-1)*2-1 == 4*a-3 ; 8a-7; 16a-15
        			
        			// 10, 100, 1000, 1001, 1002, 1003, ... , 10000
        			
        			// LIMIT FOR N IS 100, go for DP
        			
        			// I can either add up to this item
        			// or delete everything from this element up to the end of sequence
        			
        }


        private void printOutput() {
            if (failed) {
                writer.println("0");
                System.out.println("FAILURE!!!");
            } else {
            	writer.println(String.format("Case #%d: %d", testId, result));
            }
        }
    }

	// solve the problem here
	private void solve(){
		int numTests = nextInt();
		for (int testId = 1; testId <= numTests; testId++) {
			Solver solver = new Solver(testId);
			solver.readInput();
			solver.run();
			solver.printOutput();
		}

	}


	BufferedReader reader;
	StringTokenizer tokenizer = null;
	PrintWriter writer;

	String encrypted = "ejp mysljylc kd kxveddknmc re jsicpdrysi"+
	         "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"+
	         "de kr kd eoya kw aej tysr re ujdr lkgc jv yeq";
    String output    = "our language is impossible to understand"+
	         "there are twenty six factorial possibilities"+ 
	         "so it is okay if you want to just give up aoz";

    char[] code = new char[256];
    	
    private void preparehalfcode() {
    	for (int i = 0; i<encrypted.length(); i++) {
    		code[encrypted.charAt(i)] = output.charAt(i);
    	}    	
    }
    
    private void prepare() {
    	preparehalfcode();
    	encrypted = encrypted.toUpperCase();
    	output = output.toUpperCase();
    	preparehalfcode();
    }
    
    public void run() {
        try {
            long now = System.currentTimeMillis();
            String problemfilename = this.getClass().getSimpleName();
            reader = new BufferedReader(new FileReader(problemfilename + ".in"));
            writer = new PrintWriter(problemfilename + ".out");
            prepare();
            solve();
            reader.close();
            writer.close();
            System.out.println(System.currentTimeMillis() - now + "ms");
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

	int nextInt() {
        return Integer.parseInt(nextToken());
    }

    double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    long nextLong() {
        return Long.parseLong(nextToken());
    }

    String nextToken() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }
    /**
	 * @param args
	 */
	public static void main(String[] args) {
		new A().run();
	}

}
