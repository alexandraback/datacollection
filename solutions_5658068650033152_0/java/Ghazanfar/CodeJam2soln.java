/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Package1;

/**
 *
 * @author Mohammad Ghazanfar
 */

import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class CodeJam2soln implements Runnable {

	private PrintWriter out;
	
	final String file = "C:\\Users\\Mohammad Ghazanfar\\Documents\\NetBeansProjects\\RandomPrograms\\src\\Package1\\C-small-attempt0";

	static class InputData {

            int n,m,k;
            int placed,curLength,curHeight;
            int stones;
            boolean added;
            InputData(FastReader in) throws IOException {
                n=in.nextInt();
                m=in.nextInt();
                k=in.nextInt();
                curHeight=curLength=1;
                placed=5;
                added=true;
                stones=4;
            }

            void solve(PrintWriter out) {
                if(k<=4){
                    stones=k;
                }
                if(m==1 || m==2){
                    stones=k;
                    placed=k;
                }
                if(n==1 || n==2){
                    stones=k;
                    placed=k;
                }
                for(int i=0;placed<k;i=(~i)){
                    added=false;
                    if(i==0){
                        pullRight();
                        if(!added)
                            pullDown();
                    }
                    else{
                        pullDown();
                        if(!added)
                            pullRight();
                    }
                    if(!added)
                        break;
                }
                if(placed<k){                    
                    stones+=(k-placed);
                }
                out.println(stones);
            }
            
            void pullRight(){
                if(curLength<m-2){
                    added=true;
                    if(k-placed==1){
                        placed++;
                        stones++;
                    }
                    else{
                        stones+=2;
                        curLength++;
                        placed+=curHeight;
                        placed+=2;
                    }
                }
            }
            void pullDown(){
                if(curHeight<n-2){
                    added=true;
                    if(k-placed==1){
                        placed++;
                        stones++;
                    }
                    else{
                        stones+=2;
                        curHeight++;
                        placed+=curLength;
                        placed+=2;
                    }
                }
            }
	}
	
	static class Solver implements Callable<String> {

		InputData data;
		
		Solver(InputData data) {
			this.data = data;
		}

		@Override
		public String call() throws Exception {
			StringWriter out = new StringWriter();
			data.solve(new PrintWriter(out));
			return out.toString();
		}
	}

	public void run() {
		try {
			FastReader in = new FastReader(new BufferedReader(new FileReader(file + ".in")));
			out = new PrintWriter(file + ".out");
			
			ScheduledThreadPoolExecutor service = new ScheduledThreadPoolExecutor(7);
			
			int tests = in.nextInt();
			Future<String>[] ts = new Future[tests];
			for (int test = 0; test < tests; ++test) {
				ts[test] = service.submit(new Solver(new InputData(in)));
			}
			for (int test = 0; test < tests; ++test) {
				while (!ts[test].isDone()) {
					Thread.sleep(500);
				}
				System.err.println("Test " + test);
				out.print("Case #" + (test + 1) + ": ");
				out.print(ts[test].get());
			}
			service.shutdown();
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
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
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new CodeJam2soln().run();
	}
	
}