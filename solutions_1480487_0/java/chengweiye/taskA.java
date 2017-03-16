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
        double[] score;
        double[] org;
        double res[];
        private void readInput() {
        	N=nextInt();
        	score=new double[N];
        	org=new double[N];
        	for(int i=0;i<N;i++)
        	{
        		score[i]=nextDouble();
        		org[i]=score[i];
        	}
        	
        }
     
      //  int res;
        public void run() {
        	Arrays.sort(score);
        	double tot=0;      	
        	for(double x:score)
        	{
        		tot+=x;
        	}
        	res=new double[N];
        	int i=1;
        	for(;i<N;i++)
        	{
        		double t=tot;
        		for(int j=0;j<i;j++)
        		{
        			t+=score[j];
        		}
        		if(t/i<=score[i])
        			break;
        	}
        	double t=tot;
    		for(int j=0;j<i;j++)
    		{
    			t+=score[j];
    		}
    		double mins=t/i;
        	for(int j=0;j<N;j++)
        	{
        		if(org[j]<mins)
        		{
        			res[j]=(mins-org[j])/tot;
        		}else
        		{
        			res[j]=0;
        		}
        	}
        }
        

        private void printOutput() {
            if (failed) {
                writer.println("BAD!!!");
                System.out.println("BAD!!!");
            } else {
            	for(int j=0;j<N;j++)
            	{
            		if(j!=0)
            			writer.print(" ");
            		writer.print(res[j]*100);
            	}
            	writer.println();
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
