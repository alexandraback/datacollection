import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;


public class taskA implements Runnable {
    class Solver implements Runnable {
        int testId;
        boolean failed = false;

        Solver(int testId) {
            this.testId = testId;
        }

        int N;
        int map[][];
        private void readInput() {
        	N=nextInt();
        	map=new int[N][10];
        	for(int i=0;i<N;i++)
        	{
        		int m=nextInt();
        		for(int j=0;j<m;j++){
        			int t=nextInt();
        			//t--;
        			map[i][j]=t;
        		}
        	}
        	
        }
     
        String res;
        boolean vis[];
        boolean go(int index,int parent)
        {
        	vis[index]=true;
        	for(int i=0;i<10;i++)
        	{
        		if(map[index][i]!=0)
        		{
        			int t=map[index][i]-1;
        			if(vis[t])
        				return true;
        			if(go(t,index))
        				return true;
        		}
        	}
        	return false;
        }
        public void run() {
        	vis=new boolean[N];
        	res="No";
        	for(int i=0;i<N;i++)
        	{
        		Arrays.fill(vis, false);
        		if(go(i,-1))
        		{
        			res="Yes";
        			break;
        		}
        	}
        }
        

        private void printOutput() {
            if (failed) {
                writer.println("BAD!!!");
                System.out.println("BAD!!!");
            } else {
            	writer.println(res);
            }
        }
    }

    private void solveSequential() {
        int numTests = nextInt();
        for (int testId = 0; testId < numTests; ++testId) {
            Solver solver = new Solver(testId);
            solver.readInput();
            solver.run();
            solver.printOutput();
        }
    }

    private void solveParallel() {
        int numTests = nextInt();
        ExecutorService executor = Executors.newFixedThreadPool(4);
        Solver[] solver = new Solver[numTests];
        for (int testId = 0; testId < numTests; ++testId) {
            solver[testId] = new Solver(testId);
            solver[testId].readInput();
        }
        Future[] res = new Future[numTests];
        for (int testId = 0; testId < numTests; ++testId) {
            res[testId] = executor.submit(new Thread(solver[testId]));
        }
        for (int testId = 0; testId < numTests; ++testId) {
            try {
                res[testId].get();
            } catch (InterruptedException e) {
                solver[testId].failed = true;
            } catch (ExecutionException e) {
                solver[testId].failed = true;
            }
        }
        for (int testId = 0; testId < numTests; ++testId) {
        	writer.print("Case #");
        	writer.print(testId+1);
        	writer.print(": ");
            solver[testId].printOutput();
        }
        executor.shutdown();
    }

    static final String TASK_ID = "taskA";

    public static void main(String[] args) {
        new taskA().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer = null;
    PrintWriter writer;

    public void run() {
        try {
            long now = System.currentTimeMillis();
            reader = new BufferedReader(new FileReader(TASK_ID + ".txt"));
            writer = new PrintWriter(TASK_ID + ".out");
            solveParallel();
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
    
    String nextLine()
    {
    	String res;
        try {
            res = reader.readLine();
        } catch (IOException e) {
        //	System.out.println("failededed");
            throw new RuntimeException(e);
        }   	
        return res;
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
}
