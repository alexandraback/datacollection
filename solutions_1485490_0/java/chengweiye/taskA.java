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
import java.util.HashMap;
public class taskA implements Runnable {
    class Solver implements Runnable {
        int testId;
        boolean failed = false;

        Solver(int testId) {
            this.testId = testId;
        }

        int N,M;
        HashMap dp[][][];
        int ta[];
        long na[];
        int tb[];
        long nb[];
        long rema[][][];
        long remb[][][];
        long go(int in,int im,long cont,int who)
        {
        	if((in>=N)||(im>=M)) return 0;
        	if(dp[in][im][who].containsKey(cont)){
        		return (long)dp[in][im][who].get(cont);
        	}
        	long res=0;
        	if(ta[in]!=tb[im])
        	{
        		if(who==0){
        			long t=go(in+1,im,0,0);
        			res=Math.max(res, t);
        			t=go(in,im+1,0,0);
        			res=Math.max(res, t);			
        		}
        		if(who==1){
        			long t=go(in,im+1,cont,who);
        			res=Math.max(res, t);
        			 t=go(in+1,im,0,0);
        			res=Math.max(res, t);

        		}
        		if(who==2){
        			long t=go(in+1,im,cont,who);
        			res=Math.max(res, t);
        			t=go(in,im+1,0,0);
        			res=Math.max(res, t); 			
        		}
        	}else{
        		long ra=na[in];
        		long rb=nb[im];
        		if(who==1){
        			ra=cont;
        		}
        		if(who==2){
        			rb=cont;
        		}
        		long tt=Math.min(ra, rb);
        		if(ra>=rb){
        			long t=go(in,im+1,ra-tt,1);
        			res=Math.max(res, tt+t);
        		}else
        		{
        			long t=go(in+1,im,rb-tt,2);
        			res=Math.max(res, tt+t);
        		}
        	}
        	dp[in][im][who].put(cont, res);
        	return res;
        }
        private void readInput() {
        	N=nextInt();
        	M=nextInt();
        	ta=new int[N];
        	na=new long[N];
        	tb=new int[M];
        	nb=new long[M];
        	for(int i=0;i<N;i++){
        		na[i]=nextLong();
        		ta[i]=nextInt();
        	}
        	for(int i=0;i<M;i++){
        		nb[i]=nextLong();
        		tb[i]=nextInt();
        	}
        	dp=new HashMap[N][M][3];
        	for(int i=0;i<N;i++)
        		for(int j=0;j<M;j++)
        			for(int k=0;k<3;k++)
        			{
        				dp[i][j][k]=new HashMap();
        			}
        	
        	
        }
     
        long res;
        public void run() {
        /*	rema=new long[100][100][100];
        	remb=new long[100][100][100];
        	for(int i=0;i<N;i++)
        	{
        		for(int j=0;j<M;j++){
        		    for(int k=j+1;k<M;k++){
        		    	if(ta[i]!=tb[k-1])
        		    		rema[i][j][k]=rema[i][j][k-1];
        		    	else{
        		    		if(rema[i][j][k-1]>nb[k-1]){
        		    			rema[i][j][k]=rema[i][j][k-1]-nb[k-1];
        		    		}
        		    	}
        		    }

        		}	
        	}
        	for(int i=0;i<M;i++)
        	{
        		for(int j=0;j<N;j++){
        		    for(int k=j+1;k<N;k++){
        		    	if(tb[i]!=ta[k-1])
        		    		remb[i][j][k]=remb[i][j][k-1];
        		    	else{
        		    		if(remb[i][j][k-1]>na[k-1]){
        		    			remb[i][j][k]=remb[i][j][k-1]-na[k-1];
        		    		}
        		    	}
        		    }

        		}	
        	}*/
        	res=go(0,0,0,0);
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
