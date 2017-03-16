package round1c;


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class C {
    class Solver implements Runnable {
        int testId;
        boolean failed = false;
        long result = 0;
        
        Solver(int testId) {
            this.testId = testId;
        }

        String in, out = "";
        
        int /*a,b, p, A, B,*/ N, M;
        //long[] na, A, nb, B;
        ArrayList<Long> na, A, nb, B;
        private void readInput() {
        	N = nextInt();
        	M = nextInt();
        	
//        	na = new long[N];
//        	A = new long[N];
//        	
//        	nb = new long[M];
//        	B = new long[M];
//        	
//        	for (int i = 0; i< N; i++) {
//        		na[i] = nextLong();
//        		A[i] = nextLong();
//        	}
//        	for (int i = 0; i< M; i++) {
//        		nb[i] = nextLong();
//        		B[i] = nextLong();
//        	}
        	
        	na = new ArrayList<Long>();
        	nb = new ArrayList<Long>();
        	A = new ArrayList<Long>();
        	B = new ArrayList<Long>();
        	
			for (int i = 0; i < N; i++) {
				na.add( nextLong());
				A.add(nextLong());
			}
			for (int i = 0; i < M; i++) {
				nb.add(nextLong());
				B.add(nextLong());
			}
        	
        }

        int res;
        
        private void moveline(long na[], long[] A, long[] nb, long[] B) {
        	
        }

        private long moveline(ArrayList<Long> na, ArrayList<Long> A, ArrayList<Long> nb, ArrayList<Long> B) {
        	long result = 0;
        	if (A.isEmpty() || B.isEmpty()) return 0;
        	if (A.get(0) == B.get(0)) {
        		long n = Math.min(na.get(0), nb.get(0));
        		na.set(0, na.get(0) - n);
        		nb.set(0, nb.get(0) - n);
        		
        		result = n;
        	}
        	
        	ArrayList<Long> na1 = new ArrayList<Long>(na);
        	ArrayList<Long> A1 = new ArrayList<Long>(A);
        	ArrayList<Long> nb1 = new ArrayList<Long>(nb);
        	ArrayList<Long> B1 = new ArrayList<Long>(B);
        	
        	na1.remove(0);
        	A1.remove(0);
        	nb1.remove(0);
        	B1.remove(0);
        	
        	return result + Math.max(moveline(na1, A1, nb, B), 
        			moveline(na, A, nb1, B1) );
        }
        
        
        public void run() {
        	result = moveline(na, A, nb, B); 
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
    
    private void prepare() {
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
		new C().run();
	}

}
