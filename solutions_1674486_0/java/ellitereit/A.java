package round1c;


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class A {
    class Solver implements Runnable {
        int testId;
        boolean failed = false;
        boolean result = false;
        
        Solver(int testId) {
            this.testId = testId;
        }

        String in, out = "";
        
        ArrayList<String> text = new ArrayList<String>();
        
        boolean[][] classes;
        int n;

        private void readInput() {
        	n = nextInt();
        	
        	classes = new boolean[n+1][n+1];
        	for (int i=1; i<=n; i++){
        		int c = nextInt();
        		for (int j = 0; j<c; j++) classes[i][nextInt()] = true;
        	}
        }

        int res;
        boolean[] connected;
        
        private void inherit(int node, int depth) {
        	if (depth > n || result) return;
        	for (int i = 1; i <=n; i++){
        		if (classes[i][node]) {
        			if (!connected[i]){
        				connected[i] = true;
        				inherit(i,depth+1);
        			}
        			else {
        				result = true;
        				return;
        			}
        		}
        			
        	}
        }
        
        public void run() {
        	
        	for (int i=1; i<=n; i++){
        		connected = new boolean[n+1];
        		inherit(i, 0);        		
        	}
        }


        private void printOutput() {
            if (failed) {
                writer.println("No");
                System.out.println("FAILURE!!!");
            } else {
            	
                writer.println(String.format("Case #%d: %s", testId, (result ? "Yes" : "No")));
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
		new A().run();
	}

}
